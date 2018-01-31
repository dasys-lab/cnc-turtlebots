#pragma once

#include <actionlib/client/action_client.h>
#include <actionlib/client/terminal_state.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>
#include <move_base_msgs/MoveBaseAction.h>

#include <ros/ros.h>

#include <string>
#include <vector>

namespace supplementary
{
class SystemConfig;
}

namespace ttb
{
class TTBWorldModel;
namespace wm
{
	class Area;
	class Room;
}
namespace robot
{
namespace pathPlanning
{
class TopologicalPathPlanner;
}

class Movement
{
  public:
    Movement(ttb::TTBWorldModel *wm);
    virtual ~Movement();

    std::vector<std::shared_ptr<wm::Area>> plan(std::shared_ptr<wm::Room> start, std::shared_ptr<wm::Room> goal);
    void send(geometry_msgs::Twist &twist);
    actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> send(move_base_msgs::MoveBaseGoal &mbg);
    void cancelAllGoals();
    void cancelGoalsAtAndBeforeTime(const ros::Time &time);

  private:
    supplementary::SystemConfig *sc;
    ttb::robot::pathPlanning::TopologicalPathPlanner *topoPlanner;
    std::string directVelocityCmd;
    std::string moveBaseActionClientNamespace;

    ros::NodeHandle n;
    ros::Publisher directVelocityCmdPub;

    actionlib::ActionClient<move_base_msgs::MoveBaseAction> *ac;
};

} /* namespace robot */
} /* namespace ttb */
