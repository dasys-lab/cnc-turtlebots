#pragma once

#include <cnc_geometry/CNPointAllo.h>
#include <cnc_geometry/CNPositionAllo.h>
#include <cnc_geometry/CNVecAllo.h>
#include <supplementary/InfoBuffer.h>
#include <supplementary/InformationElement.h>

#include <tf/transform_listener.h>
#include <vector>

#define RAW_SENSOR_DEBUG

namespace ttb
{
class TTBWorldModel;
}

namespace sensor_msgs
{
ROS_DECLARE_MESSAGE(PointCloud2)
ROS_DECLARE_MESSAGE(Imu)
ROS_DECLARE_MESSAGE(JointState)
ROS_DECLARE_MESSAGE(LaserScan)
ROS_DECLARE_MESSAGE(Image)
}

namespace kobuki_msgs
{
ROS_DECLARE_MESSAGE(SensorState)
ROS_DECLARE_MESSAGE(BumperEvent)
ROS_DECLARE_MESSAGE(DockInfraRed)
ROS_DECLARE_MESSAGE(CliffEvent)
}

namespace ar_track_alvar_msgs
{
ROS_DECLARE_MESSAGE(AlvarMarkers)
}

namespace ttb_msgs
{
ROS_DECLARE_MESSAGE(ServeTask)
ROS_DECLARE_MESSAGE(LogicalCamera)
}

namespace robot_control
{
ROS_DECLARE_MESSAGE(RobotCommand)
}

namespace nav_msgs
{
ROS_DECLARE_MESSAGE(Odometry)
}

namespace ttb
{
namespace wm
{
class RawSensorData
{
  public:
    RawSensorData(TTBWorldModel *wm);
    virtual ~RawSensorData();

    // methods for processing ROS messages
    void processAlvarMarkers(ar_track_alvar_msgs::AlvarMarkersPtr alvar);
    void processOdometryData(nav_msgs::OdometryPtr odometry);
    void processLaserScan(sensor_msgs::LaserScanPtr laserScan);
    void processBumperEvent(kobuki_msgs::BumperEvent bumperEvent);
    void processBumperCloud(sensor_msgs::PointCloud2Ptr bumperCloud);
    void processImu(sensor_msgs::Imu imu);
    void processDepthCameraCloud(sensor_msgs::PointCloud2Ptr depthImageCloud);
    void processCliffEvent(kobuki_msgs::CliffEvent cliffEvent);
    void processCameraImageRaw(sensor_msgs::ImagePtr cameraImageRaw);
    void processRobotOnOff(robot_control::RobotCommandPtr robotCommand);
    void processMobileBaseSensorState(kobuki_msgs::SensorStatePtr mobileBaseSensorState);
    void processDockInfrRed(kobuki_msgs::DockInfraRedPtr dockInfrRed);
    void processServeTask(ttb_msgs::ServeTaskPtr serveTask);
    void processLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCamera);
    void processGazeboMsg(geometry_msgs::Pose gazeboMsg);

    // data access through public buffers

    const supplementary::InfoBuffer<nav_msgs::Odometry>& getOdometryBuffer();
    //shared_ptr<nav_msgs::Odometry> getOwnOdom(int index = 0);

    const supplementary::InfoBuffer<geometry::CNPositionAllo>& getOdomPositionBuffer();
    //shared_ptr<geometry::CNPositionAllo> getOwnOdomPosition(int index = 0);

    const supplementary::InfoBuffer<geometry::CNPositionAllo>& getGazeboPositionBuffer(); // TODO: fuse this with normal Buffer above
    //shared_ptr<geometry::CNPositionAllo> getOwnPosition(int index = 0); /*<- Gazebo only! */

    const supplementary::InfoBuffer<geometry::CNVecAllo>& getOdomVelocityBuffer(); // TODO: Check whether vector is allo or ego
    //shared_ptr<geometry::CNVecAllo> getOwnVelocityMotion(int index = 0);

    const supplementary::InfoBuffer<sensor_msgs::LaserScan>& getLaserScanBuffer();
    //shared_ptr<sensor_msgs::LaserScan> getOwnLaserScans(int index = 0);

    const supplementary::InfoBuffer<kobuki_msgs::BumperEvent>& getBumperEventBuffer();
    //shared_ptr<kobuki_msgs::BumperEvent> getOwnBumperEvents(int index = 0);

    const supplementary::InfoBuffer<sensor_msgs::PointCloud2>& getBumperCloudBuffer();
    //shared_ptr<sensor_msgs::PointCloud2> getOwnBumperSensors(int index = 0);

    const supplementary::InfoBuffer<sensor_msgs::PointCloud2>& getDepthCameraCloudBuffer();
    //shared_ptr<sensor_msgs::PointCloud2> getOwnCameraPcl(int index = 0);

    const supplementary::InfoBuffer<sensor_msgs::Imu>& getImuDataBuffer();
    //shared_ptr<sensor_msgs::Imu> getOwnImuData(int index = 0);

    const supplementary::InfoBuffer<kobuki_msgs::CliffEvent>& getCliffEventBuffer();
    //shared_ptr<kobuki_msgs::CliffEvent> getOwnCliffEvent(int index = 0);

    const supplementary::InfoBuffer<sensor_msgs::Image>& getRawCameraImageBuffer();
    //shared_ptr<sensor_msgs::Image> getOwnCameraImageRaw(int index = 0);

    const supplementary::InfoBuffer<robot_control::RobotCommand>& getRobotCommandBuffer();
    //shared_ptr<robot_control::RobotCommand> getOwnRobotOnOff(int index = 0);

    const supplementary::InfoBuffer<kobuki_msgs::SensorState>& getMobileBaseSensorStateBuffer();
    //shared_ptr<kobuki_msgs::SensorState> getOwnMobileBaseSensorState(int index = 0);

    const supplementary::InfoBuffer<kobuki_msgs::DockInfraRed>& getDockInfrRedBuffer();
    //shared_ptr<kobuki_msgs::DockInfraRed> getOwnDockInfrRed(int index = 0);

    const supplementary::InfoBuffer<ttb_msgs::ServeTask>& getServeTaskBuffer();

    const supplementary::InfoBuffer<ar_track_alvar_msgs::AlvarMarkers>& getAlvarMarkerBuffer();
    //shared_ptr<ar_track_alvar_msgs::AlvarMarkers> getAlvar(int index = 0);

    const supplementary::InfoBuffer<ttb_msgs::LogicalCamera>& getLogicalCameraDataBuffer(); // TODO: name of message misleading
    //shared_ptr<ttb_msgs::LogicalCamera> getLogicalCamera(int index = 0);

  private:
    TTBWorldModel *wm;
    const supplementary::InfoTime maxValidity = 1000000000;
    tf::TransformListener listener;

    // common stuff
    supplementary::InfoBuffer<robot_control::RobotCommand>* robotCommandBuffer;
    supplementary::InfoBuffer<ttb_msgs::ServeTask>* serveTaskBuffer;

    // real robots only stuff
    // maps marker id to buffer for this marker
    int alvarMarkerBufferLength;
    supplementary::InfoTime alvarMarkerValidityDuration;
    std::map<unsigned int, std::shared_ptr<supplementary::InfoBuffer<geometry_msgs::PoseStamped>>> alvarMarkerMap;

    supplementary::InfoTime cliffEventValidityDuration;
    supplementary::InfoBuffer<kobuki_msgs::CliffEvent>* cliffEventBuffer;

    supplementary::InfoTime odometryValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<nav_msgs::Odometry>>* odometryBuffer; /* <- contains the next two */

    supplementary::InfoTime odomPositionValidityDuration;
    supplementary::InfoBuffer<geometry::CNPositionAllo>* odomPositionBuffer;

    supplementary::InfoTime odomVelocityValidityDuration;
    supplementary::InfoBuffer<geometry::CNVecAllo>* odomVelocityBuffer;

    supplementary::InfoTime laserScanValidityDuration;
    supplementary::InfoBuffer<sensor_msgs::LaserScan>* laserScanBuffer;

    supplementary::InfoTime bumperEventValidityDuration;
    supplementary::InfoBuffer<kobuki_msgs::BumperEvent>* bumperEventBuffer;

    supplementary::InfoTime bumperCloudValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::PointCloud2>>* bumperCloudBuffer;

    supplementary::InfoTime depthCameraCloudValidityDuration;
    supplementary::InfoBuffer<sensor_msgs::PointCloud2>* depthCameraCloudBuffer;

    supplementary::InfoTime imuDataValidityDuration;
    supplementary::InfoBuffer<sensor_msgs::Imu>* imuDataBuffer;

    supplementary::InfoTime rawCameraImageValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::Image>>* rawCameraImageBuffer;

    supplementary::InfoTime mobileBaseSensorStateValidityDuration;
    supplementary::InfoBuffer<kobuki_msgs::SensorState>* mobileBaseSensorStateBuffer;

    supplementary::InfoTime dockInfrRedValidityDuration;
    supplementary::InfoBuffer<kobuki_msgs::DockInfraRed>* dockInfrRedBuffer;

    // simulation only stuff
    supplementary::InfoTime gazeboPositionValidityDuration;
    supplementary::InfoBuffer<geometry::CNPositionAllo>* gazeboPositionBuffer;

    supplementary::InfoTime logicalCameraValidityDuration;
    supplementary::InfoBuffer<ttb_msgs::LogicalCamera>* logicalCameraBuffer;
};
} /* namespace wm */
} /* namespace ttb */
