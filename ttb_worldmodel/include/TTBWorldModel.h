/*
 * TTBWorldModel.h
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */

#ifndef TTBWORLDMODEL_H_
#define TTBWORLDMODEL_H_

#include <iostream>
#include <list>
#include <mutex>
#include <string>
#include <tuple>

#include <ros/ros.h>

#include "ar_track_alvar_msgs/AlvarMarkers.h"
#include "gazebo_msgs/ModelStates.h"
#include "geometry_msgs/Twist.h"
#include "kobuki_msgs/BumperEvent.h"
#include "kobuki_msgs/CliffEvent.h"
#include "kobuki_msgs/DockInfraRed.h"
#include "kobuki_msgs/SensorState.h"
#include "robot_control/RobotCommand.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/JointState.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/PointCloud2.h"
#include "tf/transform_listener.h"
#include "ttb_msgs/ServeTask.h"
#include "ttb_msgs/LogicalCamera.h"

#include "Doors.h"
#include "EventTrigger.h"
#include "LogicalCameraData.h"
#include "RawSensorData.h"
#include "Robots.h"
#include "SystemConfig.h"
#include "TaskManager.h"
#include "ttb_poi/TTBPointOfInterests.h"

namespace supplementary
{
class SystemConfig;
}

namespace alica
{
class AlicaEngine;
}

namespace ttb
{
class WrappedMessageHandler;

class TTBWorldModel
{
  public:
    static TTBWorldModel *get(); /**< Singleton Getter */

    bool setEngine(alica::AlicaEngine *ae);
    alica::AlicaEngine *getEngine();
    virtual ~TTBWorldModel();
    InfoTime getTime();
    int getRingBufferLength();

    // Public Data Access Classes
    wm::RawSensorData rawSensorData;
    wm::LogicalCameraData logicalCameraData;
    wm::TaskManager taskManager;
    wm::Robots robots;
    wm::TTBPointOfInterests pois;
    wm::Doors doors;

  private:
    TTBWorldModel(); /**< Private Singleton Constructor */

    supplementary::SystemConfig *sc;
    alica::AlicaEngine *alicaEngine;
    WrappedMessageHandler *wrappedMessageHandler;

    int ownID;
    int ringBufferLength;

    mutex wmMutex;

    // ROS Stuff
    ros::NodeHandle n;
    ros::AsyncSpinner *spinner;

    string serveTaskTopic;
    string alvarTopic;
    string odometryTopic;
    string laserScanTopic;
    string bumperSensorTopic;
    string bumperEventTopic;
    string imuDataTopic;
    string cameraPclTopic;
    string commandVelTopic;
    string jointStateTopic;
    string cliffEventsTopic;
    string cameraImageRawTopic;
    string robotOnOffTopic;
    string mobileBaseSensorStateTopic;
    string dockInfrRedTopic;
    string logicalCameraSensorTopic;

    InfoTime timeLastSimMsgReceived;

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

    void onAlvarData(ar_track_alvar_msgs::AlvarMarkersPtr alvarData);
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

  protected:
};

} /* namespace ttb */

#endif /* TTBWORLDMODEL_H_ */
