#include "robot/Movement.h"

#include <SystemConfig.h>

namespace ttb
{
namespace robot
{

Movement::Movement()
{
	this->sc = supplementary::SystemConfig::getInstance();
	this->directVelocityCmd = (*sc)["Drive"]->get<std::string>("Topics.DirectVelocityCmd", NULL);
	this->directVelocityCmdPub = n.advertise<geometry_msgs::Twist>(directVelocityCmd, 10);

    this->moveBaseActionClientNamespace = (*sc)["Drive"]->get<string>("Topics.MoveBaseActionClientNamespace", NULL);
    this->ac = new actionlib::ActionClient<move_base_msgs::MoveBaseAction>(moveBaseActionClientNamespace);
}

Movement::~Movement()
{
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

void Movement::cancelGoalsAtAndBeforeTime(const ros::Time & time)
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
