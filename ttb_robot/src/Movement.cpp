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
    this->goalHandle.reset();

    this->goalPOI = nullptr;
    this->doorToOpen = nullptr;
    this->sqrCatchRadius = (*this->sc)["TTBRobot"]->get<double>("Movement.catchRadius", NULL);
    this->sqrCatchRadius *= this->sqrCatchRadius;

    this->sequenceCounter = 0;
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

void Movement::run()
{
    lock_guard<std::mutex> guard(this->goalMutex);

    // clean up, if necessary
    if (this->goalPOIDirty)
    {
        // cancel current progress
        this->reset();
    }

    if (!goalHandle.isExpired())
    {
        std::cout << "Movement: GoalHandle-CommState: " << this->goalHandle.getCommState().toString() << std::endl;
        std::cout << "Movement: GoalHandle-TerminalState: " << this->goalHandle.getTerminalState().toString()
                  << std::endl;
    }

    if (!this->goalHandle.isExpired() && this->goalHandle.getCommState() == actionlib::CommState::DONE &&
        (this->goalHandle.getTerminalState() == actionlib::TerminalState::SUCCEEDED ||
         this->goalHandle.getTerminalState() == actionlib::TerminalState::ABORTED))
    {
        this->goalHandle.reset();
    }

    // get own room
    auto startRoom = this->wm->topologicalLocalization.getRoomBuffer()->getLastValidContent();
    if (!startRoom)
    {
        std::cerr << "Movement: No own room known!" << std::endl;
        return;
    }

    // plan area path
    std::vector<std::shared_ptr<::ttb::wm::Area>> areaList;
    if (!this->topoPlanner->planAreaPath(startRoom.value(), this->goalPOI->room, areaList))
    {
        std::cerr << "Movement: Planning area path didn't work out!" << std::endl;
        return;
    }

    // determine next goal room
    std::shared_ptr<ttb::wm::Room> goalRoom = std::shared_ptr<ttb::wm::Room>();
    std::shared_ptr<ttb::wm::Door> doorToNextArea = std::shared_ptr<ttb::wm::Door>();
    if (areaList.size() > 0)
    {
        if (!determineGoalRoom(startRoom.value(), areaList[0], goalRoom, doorToNextArea))
        {
            std::cerr << "Movement: Determining goal room didn't work out!" << std::endl;
            return;
        }
    }
    else
    {
        goalRoom = this->goalPOI->room;
    }

    // plan door path
    std::vector<std::shared_ptr<::ttb::wm::Door>> doorList;
    if (!this->topoPlanner->planDoorPath(startRoom.value(), goalRoom, doorList))
    {
        std::cerr << "Movement: Planning Door Path didn't work out!" << std::endl;
        return;
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
        currentPOI = this->goalPOI;
    }

    // Get own pos
    auto ownPos = this->wm->rawSensorData.getAMCLPositionBuffer()->getLastValidContent();
    if (!ownPos)
    {
        std::cerr << "Movement: Not localized!" << std::endl;
        return;
    }

    // 1. Check distance to currentPOI -> Drive to currentPOI (MoveBase)
    cout << "Movement: currentPOI: " << currentPOI->id << std::endl;
    if (!closeToPOI(ownPos.value(), currentPOI) && this->goalHandle.isExpired())
    {
        // MoveBase to currentPOI
        std::cout << "Movement: Drive to current POI: " << currentPOI->id << std::endl;
        move_base_msgs::MoveBaseGoal mbg;
        mbg.target_pose.pose.position.x = currentPOI->x;
        mbg.target_pose.pose.position.y = currentPOI->y;
        mbg.target_pose.header.frame_id = "/map";
        mbg.target_pose.header.seq = this->sequenceCounter++;
        auto time = this->wm->getTime();
        mbg.target_pose.header.stamp = ros::Time((uint32_t)(time / 1000000000UL), (uint32_t)(time % 1000000000UL));
        mbg.target_pose.pose.orientation.w = 1;
        this->goalHandle = this->send(mbg);
        return;
    }

    // 2. Check door state of doorList.at(0) -> Open door (Arm)
    if (!doorList.at(0)->open && !this->robot->simulatedArm->openDoor(doorList.at(0)->name, true))
    {
        std::cerr << "Movement: Closed door '" << doorList.at(0)->name << "' unable to open!" << std::endl;
        return;
    }

    // 3. Drive to nextPOI (MoveBase)
    cout << "Movement: nextPOI: " << nextPOI->id << std::endl;
    if (!closeToPOI(ownPos.value(), nextPOI) && this->goalHandle.isExpired())
    {
        // MoveBase to nextPOI
        std::cout << "Movement: Drive to next POI: " << nextPOI->id << std::endl;
        move_base_msgs::MoveBaseGoal mbg;
        mbg.target_pose.pose.position.x = nextPOI->x;
        mbg.target_pose.pose.position.y = nextPOI->y;
        mbg.target_pose.header.frame_id = "/map";
        mbg.target_pose.header.seq = this->sequenceCounter++;
        auto time = this->wm->getTime();
        mbg.target_pose.header.stamp = ros::Time((uint32_t)(time / 1000000000UL), (uint32_t)(time % 1000000000UL));
        mbg.target_pose.pose.orientation.w = 1;
        this->goalHandle = this->send(mbg);
        return;
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
    // to be implemented
    this->currentPath.clear();
    this->currentPathInArea.clear();
    // reset goal handle
    this->goalHandle.reset();
    this->goalPOIDirty = false;
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
