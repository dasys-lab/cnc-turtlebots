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
{
    this->wm = wm;
    this->robot = robot;
    this->topoPlanner = new ttb::robot::pathPlanning::TopologicalPathPlanner(&(wm->topologicalModel));
    this->sc = supplementary::SystemConfig::getInstance();
    this->directVelocityCmd = (*sc)["Drive"]->get<std::string>("Topics.DirectVelocityCmd", NULL);
    this->directVelocityCmdPub = n.advertise<geometry_msgs::Twist>(directVelocityCmd, 10);

    this->moveBaseActionClientNamespace = (*sc)["Drive"]->get<string>("Topics.MoveBaseActionClientNamespace", NULL);
    this->ac = new actionlib::ActionClient<move_base_msgs::MoveBaseAction>(moveBaseActionClientNamespace);
    this->currentGoal = nullptr;
    this->doorToOpen = nullptr;
}

Movement::~Movement()
{
    delete this->topoPlanner;
}

// PATH PLANNER

std::shared_ptr<ttb::wm::POI> Movement::getNextPOI(std::shared_ptr<ttb::wm::Room> currentPosition, std::shared_ptr<ttb::wm::POI> goal)
{
    if (goal->room == currentPosition)
    {
        std::cout << "Movement::getNextPOI: returning goal since poi is situated in current room!" << std::endl;
        return goal;
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
            return nullptr;
        }
    }
    if (!this->currentGoal || this->currentGoal->id != goal->id)
    {
        std::cout << "Movement::getNextPOI: current goal null or different goal => area planning" << std::endl;
        this->currentGoal = goal;
        this->currentPath = this->topoPlanner->plan(currentPosition, goal->room);
    }
    if (this->currentPath.size() > 0)
    {
    	std::cout << "Movement::getNextPOI: area path length: " << this->currentPath.size() << std::endl;
        if (this->currentPathInArea.size() == 0)
        {
        	std::cout << "Movement::getNextPOI: no path in area!" << std::endl;
            this->currentPathInArea = this->topoPlanner->planToNextArea(currentPosition, this->currentPath.at(0));
            std::cout << "Movement::getNextPOI: new Path in area length is: " << this->currentPathInArea.size() << std::endl;
        }
    }
    else
    {
    	std::cout << "Movement::getNextPOI: are path length is 0 plan between rooms of an area!" << std::endl;
        if (this->currentPathInArea.size() == 0)
        {
            this->currentPathInArea = this->topoPlanner->planBetweenRooms(currentPosition, goal->room);
        }
    }
    std::cout << "Movement::getNextPOI: getting next door!" << std::endl;
    this->doorToOpen = this->currentPathInArea.at(0);
    std::cout << "Movement::getNextPOI: next door is: " << this->doorToOpen->name << std::endl;
    this->currentPathInArea.erase(this->currentPathInArea.begin());
    if (this->currentPathInArea.size() == 0 && this->currentPath.size() != 0)
    {
    	std::cout << "Movement::getNextPOI: path finished in this area move to next area." << std::endl;
        this->currentPath.erase(this->currentPath.begin());
    }
    if (currentPosition == this->doorToOpen->fromRoom)
    {
        return this->doorToOpen->fromPOI;
    }
    else
    {
        return this->doorToOpen->toPOI;
    }
    return nullptr;
}

std::vector<std::shared_ptr<::ttb::wm::Area>> Movement::plan(std::shared_ptr<ttb::wm::Room> start, std::shared_ptr<ttb::wm::Room> goal)
{
    return this->topoPlanner->plan(start, goal);
}

// MOVE BASE STUFF

actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> Movement::send(move_base_msgs::MoveBaseGoal &mbag)
{
    return ac->sendGoal(mbag);
}

void Movement::cancelAllGoals()
{
    ac->cancelAllGoals();
}

void Movement::cancelGoalsAtAndBeforeTime(const ros::Time &time)
{
    ac->cancelGoalsAtAndBeforeTime(time);
}

// OTHER STUFF

void Movement::send(geometry_msgs::Twist &tw)
{
    directVelocityCmdPub.publish(tw);
}

} /* namespace robot */
} /* namespace ttb */
