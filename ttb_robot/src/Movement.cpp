#include "robot/Movement.h"

#include "TopologicalPathPlanner.h"
#include <Robot.h>
#include <SystemConfig.h>
#include <TTBWorldModel.h>
#include <TopologicalLocalization.h>

namespace ttb
{
namespace robot
{

Movement::Movement(ttb::TTBWorldModel *wm, ttb::Robot *robot)
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

    this->sqrCatchRadius = (*this->sc)["TTBRobot"]->get<double>("Movement.catchRadius", NULL);
    this->sqrCatchRadius *= this->sqrCatchRadius;
}

Movement::~Movement()
{
    delete this->topoPlanner;
}

// PATH PLANNER

std::shared_ptr<ttb::wm::Door> Movement::getNextDoor(std::shared_ptr<ttb::wm::POI> goalPOI)
{
	std::cerr << "Movement::getNextDoor is not implemented, yet!" << std::endl;
	return nullptr;
}

std::shared_ptr<ttb::wm::POI> Movement::getNextPOI(std::shared_ptr<ttb::wm::POI> goalPOI)
{
	// only one query at a time
    lock_guard<std::mutex> guard(this->queryMutex);
    this->reset();

    // get own room
    auto startRoom = this->wm->topologicalLocalization.getRoomBuffer()->getLastValidContent();
    if (!startRoom)
    {
        std::cerr << "Movement: No own room known!" << std::endl;
        return nullptr;
    }

    // plan area path
    std::vector<std::shared_ptr<::ttb::wm::Area>> areaList;
    if (!this->topoPlanner->planAreaPath(startRoom.value(), goalPOI->room, areaList))
    {
        std::cerr << "Movement: Planning area path didn't work out!" << std::endl;
        return nullptr;
    }

    // determine next goal room
    std::shared_ptr<ttb::wm::Room> goalRoom = std::shared_ptr<ttb::wm::Room>();
    std::shared_ptr<ttb::wm::Door> doorToNextArea = std::shared_ptr<ttb::wm::Door>();
    if (areaList.size() > 0)
    {
        if (!determineGoalRoom(startRoom.value(), areaList[0], goalRoom, doorToNextArea))
        {
            std::cerr << "Movement: Determining goal room didn't work out!" << std::endl;
            return nullptr;
        }
    }
    else
    {
        goalRoom = goalPOI->room;
    }

    // plan door path
    std::vector<std::shared_ptr<::ttb::wm::Door>> doorList;
    if (!this->topoPlanner->planDoorPath(startRoom.value(), goalRoom, doorList))
    {
        std::cerr << "Movement: Planning Door Path didn't work out!" << std::endl;
        return nullptr;
    }
    if (doorToNextArea)
    {
        std::cout << "Movement: Setting door to next area to '" << doorToNextArea->name << "'" << std::endl;
        doorList.push_back(doorToNextArea);
    }

    // determine next POI
    std::shared_ptr<ttb::wm::POI> currentPOI = nullptr;
    std::shared_ptr<ttb::wm::POI> nextPOI = nullptr;
    if (doorList.size() > 0)
    {
        if ((*startRoom)->name.compare(doorList.at(0)->fromRoom->name) == 0)
        {
            currentPOI = doorList.at(0)->fromPOI;
            nextPOI = doorList.at(0)->toPOI;
        }
        else
        {
            currentPOI = doorList.at(0)->toPOI;
            nextPOI = doorList.at(0)->fromPOI;
        }
    }
    else
    {
        // door list is empty => POI is in same room
        currentPOI = goalPOI;
    }

    // Get own pos
    auto ownPos = this->wm->rawSensorData.getAMCLPositionBuffer()->getLastValidContent();
    if (!ownPos)
    {
        std::cerr << "Movement: Not localized!" << std::endl;
        return nullptr;
    }

    // 1. Check distance to currentPOI -> Drive to currentPOI (MoveBase)
    cout << "Movement: currentPOI: " << currentPOI->id << std::endl;
    if (!closeToPOI(ownPos.value(), currentPOI))
    {
        // MoveBase to currentPOI
        return currentPOI;
    }
    else
    {
        return nextPOI;
    }
}

bool Movement::determineGoalRoom(std::shared_ptr<::ttb::wm::Room> start, std::shared_ptr<::ttb::wm::Area> goal,
                                 std::shared_ptr<ttb::wm::Room> &goalRoom,
                                 std::shared_ptr<ttb::wm::Door> &doorToNextArea)
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

bool Movement::closeToPOI(geometry::CNPositionAllo ownPos, std::shared_ptr<ttb::wm::POI> currentPOI)
{
    double sqrDistance = (currentPOI->x - ownPos.x) * (currentPOI->x - ownPos.x) +
                         (currentPOI->y - ownPos.y) * (currentPOI->y - ownPos.y);
    return sqrDistance < this->sqrCatchRadius;
}

void Movement::reset()
{
    this->currentPath.clear();
    this->currentPathInArea.clear();
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
