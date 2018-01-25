#pragma once

#include <geometry_msgs/PoseStamped.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/action_client.h>
#include <actionlib/client/terminal_state.h>
#include <geometry_msgs/Twist.h>

#include <ros/ros.h>

#include <string>
#include <vector>

namespace supplementary {
	class SystemConfig;
}

namespace ttb
{
namespace robot
{

class Movement
{
  public:
    Movement();
    virtual ~Movement();

    void send(geometry_msgs::Twist& twist);
    actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> send(move_base_msgs::MoveBaseGoal& mbg);
	void cancelAllGoals();
	void cancelGoalsAtAndBeforeTime(const ros::Time & time);

  private:
	supplementary::SystemConfig* sc;
	std::string directVelocityCmd;
	std::string moveBaseActionClientNamespace;

	ros::NodeHandle n;
	ros::Publisher directVelocityCmdPub;

	actionlib::ActionClient<move_base_msgs::MoveBaseAction>* ac;
};

} /* namespace robot */
} /* namespace ttb */
