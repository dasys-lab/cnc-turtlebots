#include "robot/Movement.h"

#include "TopologicalPathPlanner.h"
#include <SystemConfig.h>
#include <TTBWorldModel.h>

namespace ttb
{
namespace robot
{

Movement::Movement(ttb::TTBWorldModel *wm)
{
    this->topoPlanner = new ttb::robot::pathPlanning::TopologicalPathPlanner(&(wm->topologicalModel));
    this->sc = supplementary::SystemConfig::getInstance();
    this->directVelocityCmd = (*sc)["Drive"]->get<std::string>("Topics.DirectVelocityCmd", NULL);
    this->directVelocityCmdPub = n.advertise<geometry_msgs::Twist>(directVelocityCmd, 10);

    this->moveBaseActionClientNamespace = (*sc)["Drive"]->get<string>("Topics.MoveBaseActionClientNamespace", NULL);
    this->ac = new actionlib::ActionClient<move_base_msgs::MoveBaseAction>(moveBaseActionClientNamespace);
    this->currentGoal = nullptr;
}

Movement::~Movement()
{
}

// PATH PLANNER

std::shared_ptr<ttb::wm::POI> Movement::getNextPOI(std::shared_ptr<ttb::wm::Room> currentPosition, std::shared_ptr<ttb::wm::POI> goal)
{
	if(goal->room == currentPosition)
	{
		return goal;
	}
    if (!currentGoal || this->currentGoal->id != goal->id)
    {
        this->currentPath = this->topoPlanner->plan(currentPosition, goal->room);
    }
    if (this->currentPath.size() > 0)
    {
        if (this->currentPathInArea.size() == 0)
        {
            this->currentPathInArea = this->topoPlanner->planToNextArea(currentPosition, this->currentPath.at(0));
        }
    }
    else
    {
        if (this->currentPathInArea.size() == 0)
        {
            this->currentPathInArea = this->topoPlanner->planBetweenRooms(currentPosition, goal->room);
        }
    }
    auto currentDoor = this->currentPathInArea.at(0);
    std::cout << currentDoor->toString() << std::endl;
    this->currentPathInArea.erase(this->currentPathInArea.begin());
    if (this->currentPathInArea.size() == 0 && this->currentPath.size() != 0)
    {
        this->currentPath.erase(this->currentPath.begin());
    }
    if (currentPosition == currentDoor->fromRoom)
    {
        return currentDoor->fromPOI;
    }
    else
    {
        return currentDoor->toPOI;
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
