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
class Robot;
namespace wm
{
	class Area;
	class Room;
	class Door;
	class POI;
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
    Movement(ttb::TTBWorldModel *wm, ttb::Robot* robot);
    virtual ~Movement();

    std::shared_ptr<ttb::wm::POI> getNextPOI(std::shared_ptr<ttb::wm::Room> currentPosition, std::shared_ptr<ttb::wm::POI> goal);

    std::vector<std::shared_ptr<wm::Area>> plan(std::shared_ptr<wm::Room> start, std::shared_ptr<wm::Room> goal);
    void send(geometry_msgs::Twist &twist);
    actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> send(move_base_msgs::MoveBaseGoal &mbg);
    void cancelAllGoals();
    void cancelGoalsAtAndBeforeTime(const ros::Time &time);

  private:
    supplementary::SystemConfig *sc;

    ttb::TTBWorldModel* wm;
    ttb::Robot* robot;

    ttb::robot::pathPlanning::TopologicalPathPlanner *topoPlanner;
    std::string directVelocityCmd;
    std::string moveBaseActionClientNamespace;

    ros::NodeHandle n;
    ros::Publisher directVelocityCmdPub;

    actionlib::ActionClient<move_base_msgs::MoveBaseAction> *ac;
    std::vector<std::shared_ptr<ttb::wm::Area>> currentPath;
    std::vector<std::shared_ptr<ttb::wm::Door>> currentPathInArea;
    std::shared_ptr<ttb::wm::POI> currentGoal;
    std::shared_ptr<ttb::wm::Door> doorToOpen;
};

} /* namespace robot */
} /* namespace ttb */
