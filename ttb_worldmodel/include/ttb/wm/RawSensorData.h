#pragma once

#include <cnc_geometry/CNPointAllo.h>
#include <cnc_geometry/CNPositionAllo.h>
#include <cnc_geometry/CNVecAllo.h>
#include <engine/AlicaClock.h>
#include <supplementary/InfoBuffer.h>
#include <supplementary/InformationElement.h>

#include <tf/transform_listener.h>

#include <vector>

#define RAW_SENSOR_DEBUG

namespace sensor_msgs
{
ROS_DECLARE_MESSAGE(PointCloud2)
ROS_DECLARE_MESSAGE(Imu)
ROS_DECLARE_MESSAGE(JointState)
ROS_DECLARE_MESSAGE(LaserScan)
ROS_DECLARE_MESSAGE(Image)
} // namespace sensor_msgs

namespace geometry_msgs
{
ROS_DECLARE_MESSAGE(PoseWithCovarianceStamped)
}

namespace kobuki_msgs
{
ROS_DECLARE_MESSAGE(SensorState)
ROS_DECLARE_MESSAGE(BumperEvent)
ROS_DECLARE_MESSAGE(DockInfraRed)
ROS_DECLARE_MESSAGE(CliffEvent)
} // namespace kobuki_msgs

namespace ar_track_alvar_msgs
{
ROS_DECLARE_MESSAGE(AlvarMarkers)
}

namespace ttb_msgs
{
ROS_DECLARE_MESSAGE(ServeTask)
ROS_DECLARE_MESSAGE(LogicalCamera)
} // namespace ttb_msgs

namespace robot_control
{
ROS_DECLARE_MESSAGE(RobotCommand)
}

namespace nav_msgs
{
ROS_DECLARE_MESSAGE(Odometry)
}

namespace gazebo_msgs
{
ROS_DECLARE_MESSAGE(ModelStates)
}

namespace ttb
{

class TTBWorldModel;

namespace wm
{
class RawSensorData
{
public:
    RawSensorData(TTBWorldModel* wm);
    virtual ~RawSensorData();

    // methods for processing ROS messages
    void processAlvarMarkers(ar_track_alvar_msgs::AlvarMarkersPtr alvar);
    void processOdometry(nav_msgs::OdometryPtr odometry);
    void processLaserScan(sensor_msgs::LaserScanPtr laserScan);
    void processBumperEvent(kobuki_msgs::BumperEvent bumperEvent);
    void processBumperCloud(sensor_msgs::PointCloud2Ptr bumperCloud);
    void processImu(sensor_msgs::Imu imu);
    void processDepthCameraCloud(sensor_msgs::PointCloud2Ptr depthImageCloud);
    void processCliffEvent(kobuki_msgs::CliffEvent cliffEvent);
    void processRawCameraImage(sensor_msgs::ImagePtr cameraImageRaw);
    void processRobotCommand(robot_control::RobotCommand robotCommand);
    void processMobileBaseSensorState(kobuki_msgs::SensorStatePtr mobileBaseSensorState);
    void processDockInfrRed(kobuki_msgs::DockInfraRed dockInfrRed);
    void processServeTask(ttb_msgs::ServeTask serveTask);
    void processLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCamera);
    void processAMCLPose(geometry_msgs::PoseWithCovarianceStamped msg);
    void processGazeboModelState(gazebo_msgs::ModelStatesPtr modelStates);

    // data access through public buffers
    const supplementary::InfoBuffer<std::shared_ptr<nav_msgs::Odometry>>* getOdometryBuffer();
    const supplementary::InfoBuffer<geometry::CNPositionAllo>* getOdomPositionBuffer();
    const supplementary::InfoBuffer<geometry::CNPositionAllo>* getAMCLPositionBuffer();
    const supplementary::InfoBuffer<geometry::CNVecAllo>* getOdomVelocityBuffer(); // TODO: Check whether vector is allo or ego
    const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::LaserScan>>* getLaserScanBuffer();
    const supplementary::InfoBuffer<kobuki_msgs::BumperEvent>* getBumperEventBuffer();
    const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::PointCloud2>>* getBumperCloudBuffer();
    const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::PointCloud2>>* getDepthCameraCloudBuffer();
    const supplementary::InfoBuffer<sensor_msgs::Imu>* getImuDataBuffer();
    const supplementary::InfoBuffer<kobuki_msgs::CliffEvent>* getCliffEventBuffer();
    const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::Image>>* getRawCameraImageBuffer();
    const supplementary::InfoBuffer<robot_control::RobotCommand>* getRobotCommandBuffer();
    const supplementary::InfoBuffer<std::shared_ptr<kobuki_msgs::SensorState>>* getMobileBaseSensorStateBuffer();
    const supplementary::InfoBuffer<kobuki_msgs::DockInfraRed>* getDockInfrRedBuffer();
    const supplementary::InfoBuffer<ttb_msgs::ServeTask>* getServeTaskBuffer();
    const supplementary::InfoBuffer<geometry_msgs::PoseStamped>* getAlvarMarkerBuffer(unsigned int id);
    const supplementary::InfoBuffer<std::shared_ptr<ttb_msgs::LogicalCamera>>* getLogicalCameraBuffer();
    const supplementary::InfoBuffer<std::shared_ptr<gazebo_msgs::ModelStates>>* getGazeboModelStatesBuffer();

private:
    TTBWorldModel* wm;
    const alica::AlicaTime maxValidity = alica::AlicaTime::nanoseconds(1000000000);
    tf::TransformListener listener;

    // common stuff
    alica::AlicaTime robotCommandValidityDuration;
    supplementary::InfoBuffer<robot_control::RobotCommand>* robotCommandBuffer;

    alica::AlicaTime serveTaskValidityDuration;
    supplementary::InfoBuffer<ttb_msgs::ServeTask>* serveTaskBuffer;

    // real robots only stuff
    // maps marker id to buffer for this marker
    int alvarMarkerBufferLength;
    alica::AlicaTime alvarMarkerValidityDuration;
    std::map<unsigned int, std::shared_ptr<supplementary::InfoBuffer<geometry_msgs::PoseStamped>>> alvarMarkerMap;

    alica::AlicaTime cliffEventValidityDuration;
    supplementary::InfoBuffer<kobuki_msgs::CliffEvent>* cliffEventBuffer;

    alica::AlicaTime odometryValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<nav_msgs::Odometry>>* odometryBuffer; /* <- contains the next two */

    alica::AlicaTime odomPositionValidityDuration;
    supplementary::InfoBuffer<geometry::CNPositionAllo>* odomPositionBuffer;

    alica::AlicaTime odomVelocityValidityDuration;
    supplementary::InfoBuffer<geometry::CNVecAllo>* odomVelocityBuffer;

    alica::AlicaTime laserScanValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::LaserScan>>* laserScanBuffer;

    alica::AlicaTime bumperEventValidityDuration;
    supplementary::InfoBuffer<kobuki_msgs::BumperEvent>* bumperEventBuffer;

    alica::AlicaTime bumperCloudValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::PointCloud2>>* bumperCloudBuffer;

    alica::AlicaTime depthCameraCloudValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::PointCloud2>>* depthCameraCloudBuffer;

    alica::AlicaTime imuDataValidityDuration;
    supplementary::InfoBuffer<sensor_msgs::Imu>* imuDataBuffer;

    alica::AlicaTime rawCameraImageValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::Image>>* rawCameraImageBuffer;

    alica::AlicaTime mobileBaseSensorStateValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<kobuki_msgs::SensorState>>* mobileBaseSensorStateBuffer;

    alica::AlicaTime dockInfrRedValidityDuration;
    supplementary::InfoBuffer<kobuki_msgs::DockInfraRed>* dockInfrRedBuffer;

    // simulation only stuff
    alica::AlicaTime amclPositionValidityDuration;
    supplementary::InfoBuffer<geometry::CNPositionAllo>* amclPositionBuffer;

    alica::AlicaTime logicalCameraValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<ttb_msgs::LogicalCamera>>* logicalCameraBuffer;

    alica::AlicaTime modelStatesValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<gazebo_msgs::ModelStates>>* modelStatesBuffer;
};
} /* namespace wm */
} /* namespace ttb */
