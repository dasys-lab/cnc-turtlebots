#pragma once

#include <supplementary/InfoBuffer.h> /*< needed for InfoTime */

#include <ros/ros.h>
// TODO: forward declare the message with the ros macro (see MSL WorldModel)
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <gazebo_msgs/ModelStates.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/BumperEvent.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/JointState.h>
#include <kobuki_msgs/CliffEvent.h>
#include <kobuki_msgs/DockInfraRed.h>
#include <kobuki_msgs/SensorState.h>
#include <robot_control/RobotCommand.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/JointState.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/PointCloud2.h>
#include <tf/transform_listener.h>
#include <ttb_msgs/ServeTask.h>
#include <ttb_msgs/LogicalCamera.h>
#include <nav_msgs/Odometry.h>

namespace ttb
{
class TTBWorldModel;
class WrappedMessageHandler;

namespace wm
{

class Communication
{
  public:
    Communication(ttb::TTBWorldModel *wm);
    virtual ~Communication();

  private:
    void onAlvarMarkers(ar_track_alvar_msgs::AlvarMarkersPtr alvarData);
    void onOdometryData(nav_msgs::OdometryPtr odometryData);
    void onLaserScanData(sensor_msgs::LaserScanPtr laserScanData);
    void onBumperSensorData(sensor_msgs::PointCloud2Ptr bumperSensorData);
    void onBumperEventData(kobuki_msgs::BumperEventPtr bumperEventData);
    void onImuData(sensor_msgs::ImuPtr imuData);
    void onCameraPclData(sensor_msgs::PointCloud2Ptr pclData);
    void onCommandVelData(geometry_msgs::TwistPtr commandVelData);
    void onJointStateData(sensor_msgs::JointStatePtr jointStateData);
    void onCliffEventsData(kobuki_msgs::CliffEventPtr clifEventData);
    void onCameraImageRawData(sensor_msgs::ImagePtr cameraImageRawData);
    void onRobotOnOff(robot_control::RobotCommandPtr robotOnOffData);
    void onMobileBaseSensorStateData(kobuki_msgs::SensorStatePtr mobileBaseSensorStateData);
    void onDockInfrRedData(kobuki_msgs::DockInfraRedPtr dockInfrRedData);
    void onServeTask(ttb_msgs::ServeTaskPtr serveTask);
    void onGazeboModelState(gazebo_msgs::ModelStatesPtr msg);
    void onLogicalCameraData(ttb_msgs::LogicalCameraPtr logicalCameraData);

    ttb::TTBWorldModel *wm;

    // ROS Stuff
    ros::NodeHandle n;
    ros::AsyncSpinner *spinner;

    supplementary::InfoTime timeLastSimMsgReceived;

    ros::Subscriber odometrySub;
    ros::Subscriber alvarSub;
    ros::Subscriber serveTaskSub;
    ros::Subscriber laserScanSub;
    ros::Subscriber bumperSensorSub;
    ros::Subscriber bumperEventSub;
    ros::Subscriber imuDataSub;
    ros::Subscriber cameraPclSub;
    ros::Subscriber commandVelocitySub;
    ros::Subscriber jointStateSub;
    ros::Subscriber cliffEventsSub;
    ros::Subscriber cameraImageRawSub;
    ros::Subscriber robotOnOffSub;
    ros::Subscriber mobileBaseSensorStateSub;
    ros::Subscriber dockInfrRedSub;
    ros::Subscriber gazeboWorldModelSub;
    ros::Subscriber logicalCameraSensorSub;

    WrappedMessageHandler *wrappedMessageHandler;
};

} /* namespace wm */
} /* namespace ttb */
