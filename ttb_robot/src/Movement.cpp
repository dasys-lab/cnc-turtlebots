#include "robot/Movement.h"

#include "TopologicalPathPlanner.h"
#include <Robot.h>
#include <SystemConfig.h>
#include <TTBWorldModel.h>

namespace ttb
{
namespace robot
{

Movement::Movement(ttb::TTBWorldModel *wm, ttb::Robot *robot)
    : supplementary::Worker("Movement")
    , goalReached(false)
    , goalFailed(false)
    , goalPOIDirty(false)
{
    this->wm = wm;
    this->robot = robot;
    this->topoPlanner = new ttb::robot::pathPlanning::TopologicalPathPlanner(&(this->wm->topologicalModel));
    this->sc = supplementary::SystemConfig::getInstance();

    this->directVelocityCmd = (*this->sc)["Drive"]->get<std::string>("Topics.DirectVelocityCmd", NULL);
    this->directVelocityCmdPub = n.advertise<geometry_msgs::Twist>(this->directVelocityCmd, 10);

    this->moveBaseActionClientNamespace =
        (*this->sc)["Drive"]->get<string>("Topics.MoveBaseActionClientNamespace", NULL);
    this->ac = new actionlib::ActionClient<move_base_msgs::MoveBaseAction>(moveBaseActionClientNamespace);

    this->goalPOI = nullptr;
    this->doorToOpen = nullptr;
}

Movement::~Movement()
{
    delete this->topoPlanner;
}

// PATH PLANNER

ttb::robot::MovementReturnState Movement::getState(std::shared_ptr<ttb::wm::POI> goalPOI)
{
    if (!this->goalPOI)
    {
        return ttb::robot::MovementReturnState::NoGoalAssigned;
    }

    if (this->goalPOI->id != goalPOI->id)
    {
        return ttb::robot::MovementReturnState::OtherGoalAssigned;
    }
    else
    {
        if (this->goalReached)
        {
            return ttb::robot::MovementReturnState::GoalReached;
        }
        else if (this->goalFailed)
        {
            return ttb::robot::MovementReturnState::GoalFailed;
        }
        else
        {
            return ttb::robot::MovementReturnState::GoalInProgress;
        }
    }
}

void Movement::setGoalPOI(std::shared_ptr<ttb::wm::POI> goalPOI)
{
    lock_guard<std::mutex> guard(this->goalMutex);
    if (!this->goalPOI || this->goalPOI->id != goalPOI->id)
    {
        this->goalPOI = goalPOI;
        this->goalPOIDirty = true;
        this->start();
    }
}

virtual void Movement::run()
{
    lock_guard<std::mutex> guard(this->goalMutex);
    if (this->goalPOIDirty)
    {
        // cancel current progress
        this->reset();
        this->goalPOIDirty = false;
    }

    auto startRoom = this->wm->topologicalLocalization.getRoomBuffer()->getLastValidContent();
    if (!startRoom)
    {
        std::cerr << "Movement: No own room known!" << std::endl;
        return;
    }

    std::vector<std::shared_ptr<::ttb::wm::Area>> areaList;
    if (!this->topoPlanner->planAreaPath(startRoom, this->goalPOI->room, areaList))
    {
        // failed
        return;
    }

    // todo length of area list
    std::shared_ptr<ttb::wm::Room> goalRoom = nullptr;
    std::shared_ptr<ttb::wm::Door> doorToNextArea = nullptr;
    if (areaList.size() > 0)
    {
		if (!determineGoalRoom(startRoom, areaList[0], goalRoom, doorToNextArea))
		{
			// failed
			return;
		}
    }
    else
    {
    	goalRoom = this->goalPOI->room;
    }

    std::vector<std::shared_ptr<::ttb::wm::Door>> doorList;
    if (!this->topoPlanner->planDoorPath(startRoom, goalRoom, doorList))
    {
        // failed
        return;
    }
}

bool Movement::determineGoalRoom(std::shared_ptr<::ttb::wm::Room> start, std::shared_ptr<::ttb::wm::Area> goal,
                                 std::shared_ptr<ttb::wm::Room> goalRoom, std::shared_ptr<ttb::wm::Door> doorToNextArea)
{
    for (auto door : goal->doors)
    {
        if (start->area == door->fromArea)
        {
            goalRoom = door->fromRoom;
            doorToNextArea = door;
            return true;
        }
        else if (start->area == door->toArea)
        {
            goalRoom = door->toRoom;
            doorToNextArea = door;
            return true;
        }
    }
    return false;
}

void Movement::reset()
{
    // to be implemented
}

void Movement::driveToPOI(std::shared_ptr<ttb::wm::Room> startRoom, std::shared_ptr<ttb::wm::POI> goalPOI)
{
    if (goalPOI->room == startRoom)
    {
        std::cout << "Movement::driveToPOI: room!" << std::endl;
    }
    if (this->doorToOpen)
    {
        if (!this->doorToOpen->open)
        {
            std::cout << "Movement::getNextPOI: door " << this->doorToOpen->name << " is not open!" << std::endl;
            if (this->robot->simulatedArm->openDoor(this->doorToOpen->name, true))
            {
                std::cout << "Movement::getNextPOI: arm can open door: " << this->doorToOpen->name << std::endl;
                this->doorToOpen = nullptr;
            }
            else
            {
                std::cout << "Movement::getNextPOI: arm can not open door: " << this->doorToOpen->name << std::endl;
            }
        }
        else
        {
            std::cout << "Movement::getNextPOI: door " << this->doorToOpen->name << " is already open!" << std::endl;
            this->doorToOpen = nullptr;
        }
    }
    if (!this->goalPOI || this->goalPOI->id != goalPOI->id)
    {
        std::cout << "Movement::getNextPOI: current goal null or different goal => area planning" << std::endl;
        this->goalPOI = goalPOI;
        this->currentPath = this->topoPlanner->plan(startRoom, goalPOI->room);
    }
    if (this->currentPath.size() > 0)
    {
        std::cout << "Movement::getNextPOI: area path length: " << this->currentPath.size() << std::endl;
        if (this->currentPathInArea.size() == 0)
        {
            std::cout << "Movement::getNextPOI: no path in area!" << std::endl;
            this->currentPathInArea = this->topoPlanner->planToNextArea(startRoom, this->currentPath.at(0));
            std::cout << "Movement::getNextPOI: new Path in area length is: " << this->currentPathInArea.size()
                      << std::endl;
        }
    }
    else
    {
        std::cout << "Movement::getNextPOI: are path length is 0 plan between rooms of an area!" << std::endl;
        if (this->currentPathInArea.size() == 0)
        {
            this->currentPathInArea = this->topoPlanner->planBetweenRooms(startRoom, goalPOI->room);
        }
    }
    std::cout << "Movement::getNextPOI: getting next door!" << std::endl;
    if (this->currentPathInArea.size() > 0)
    {
        this->doorToOpen = this->currentPathInArea.at(0);
        std::cout << "Movement::getNextPOI: next door is: " << this->doorToOpen->name << std::endl;
    }
    else
    {
        this->doorToOpen = nullptr;
    }
    this->currentPathInArea.erase(this->currentPathInArea.begin());
    if (this->currentPathInArea.size() == 0 && this->currentPath.size() != 0)
    {
        std::cout << "Movement::getNextPOI: path finished in this area move to next area." << std::endl;
        this->currentPath.erase(this->currentPath.begin());
    }
}

std::vector<std::shared_ptr<::ttb::wm::Area>> Movement::plan(std::shared_ptr<ttb::wm::Room> start,
                                                             std::shared_ptr<ttb::wm::Room> goal)
{
    return this->topoPlanner->plan(start, goal);
}

// MOVE BASE STUFF

actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> Movement::send(move_base_msgs::MoveBaseGoal &mbag)
{
    return this->ac->sendGoal(mbag);
}

void Movement::cancelAllGoals()
{
    this->ac->cancelAllGoals();
}

void Movement::cancelGoalsAtAndBeforeTime(const ros::Time &time)
{
    this->ac->cancelGoalsAtAndBeforeTime(time);
}

// OTHER STUFF

void Movement::send(geometry_msgs::Twist &tw)
{
    this->directVelocityCmdPub.publish(tw);
}

} /* namespace robot */
} /* namespace ttb */
