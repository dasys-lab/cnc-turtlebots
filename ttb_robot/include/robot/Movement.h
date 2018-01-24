#pragma once

#include <geometry_msgs/PoseStamped.h>
#include <move_base_msgs/MoveBaseActionGoal.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <move_base_msgs/MoveBaseActionResult.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <geometry_msgs/Twist.h>

#include <ros/ros.h>

#include <string>

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
    void send(geometry_msgs::PoseStamped& pose);
	void send(move_base_msgs::MoveBaseGoal& mbg);
	actionlib::SimpleClientGoalState getMoveState();
	void cancelGoal();

  private:
	supplementary::SystemConfig* sc;
	std::string moveBaseGoalTopic;
	std::string moveBaseActionClientNamespace;
	std::string moveBaseActionGoalTopic;
	std::string velocityTopic;

	ros::NodeHandle n;
	ros::Publisher mobile_baseCommandVelocityPub;
	ros::Publisher move_base_simpleGoalPub;
	ros::Publisher move_base_ActionGoalPub;

	actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>* ac;
	bool goalActive;
};

} /* namespace robot */
} /* namespace ttb */
