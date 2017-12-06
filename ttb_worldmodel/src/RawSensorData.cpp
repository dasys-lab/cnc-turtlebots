#include <RawSensorData.h>

#include <TTBWorldModel.h>
#include <kobuki_msgs/CliffEvent.h>
#include <nav_msgs/Odometry.h>

#include <SystemConfig.h>
#include <ar_track_alvar_msgs/AlvarMarker.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>

#include <exception>
#include <iostream>
#include <map>
#include <memory>
#include <utility>

using supplementary::InfoTime;
using supplementary::InformationElement;
using supplementary::InfoBuffer;
using std::make_shared;
using std::shared_ptr;

namespace ttb
{
namespace wm
{

RawSensorData::RawSensorData(TTBWorldModel *wm)
{
    this->wm = wm;
    auto sc = this->wm->getSystemConfig();

    // common data buffers
    this->serveTaskBuffer =
        new InfoBuffer<ttb_msgs::ServeTask>((*sc)["TTBWorldModel"]->get<int>("Data.ServeTask.BufferLength", NULL));
    this->robotCommandBuffer = new InfoBuffer<robot_control::RobotCommand>(
        (*sc)["TTBWorldModel"]->get<int>("Data.RobotCommand.BufferLength", NULL));

    // real robot data buffers
    this->alvarMarkerBufferLength = (*sc)["TTBWorldModel"]->get<int>("Data.AlvarMarker.BufferLength", NULL);
    this->alvarMarkerValidityDuration = (*sc)["TTBWorldModel"]->get<int>("Data.AlvarMarker.ValidityDuration", NULL);

    this->bumperEventValidityDuration = (*sc)["TTBWorldModel"]->get<int>("Data.BumperEvent.ValidityDuration", NULL);
    this->bumperEventBuffer = new InfoBuffer<kobuki_msgs::BumperEvent>(
        (*sc)["TTBWorldModel"]->get<int>("Data.BumperEvent.BufferLength", NULL));

    this->bumperCloudValidityDuration = (*sc)["TTBWorldModel"]->get<int>("Data.BumperSensor.ValidityDuration", NULL);
    this->bumperCloudBuffer = new InfoBuffer<sensor_msgs::PointCloud2>(
        (*sc)["TTBWorldModel"]->get<int>("Data.BumperSensor.BufferLength", NULL));

    this->cliffEventValidityDuration = (*sc)["TTBWorldModel"]->get<int>("Data.CliffEvent.ValidityDuration", NULL);
    this->cliffEventBuffer =
        new InfoBuffer<kobuki_msgs::CliffEvent>((*sc)["TTBWorldModel"]->get<int>("Data.CliffEvent.BufferLength", NULL));

    this->depthCameraCloudValidityDuration =
        (*sc)["TTBWorldModel"]->get<int>("Data.DepthCameraCloud.ValidityDuration", NULL);
    this->depthCameraCloudBuffer = new InfoBuffer<sensor_msgs::PointCloud2>(
        (*sc)["TTBWorldModel"]->get<int>("Data.DepthCameraCloud.BufferLength", NULL));

    this->dockInfrRedValidityDuration = (*sc)["TTBWorldModel"]->get<int>("Data.DockInfraRed.ValidityDuration", NULL);
    this->dockInfrRedBuffer = new InfoBuffer<kobuki_msgs::DockInfraRed>(
        (*sc)["TTBWorldModel"]->get<int>("Data.DockInfrRed.BufferLength", NULL));

    this->imuDataValidityDuration = (*sc)["TTBWorldModel"]->get<int>("Data.IMUData.ValidityDuration", NULL);
    this->imuDataBuffer =
        new InfoBuffer<sensor_msgs::Imu>((*sc)["TTBWorldModel"]->get<int>("Data.IMUData.BufferLength", NULL));

    this->laserScanValidityDuration = (*sc)["TTBWorldModel"]->get<int>("Data.LaserScan.ValidityDuration", NULL);
    this->laserScanBuffer =
        new InfoBuffer<sensor_msgs::LaserScan>((*sc)["TTBWorldModel"]->get<int>("Data.LaserScan.BufferLength", NULL));

    this->mobileBaseSensorStateValidityDuration =
        (*sc)["TTBWorldModel"]->get<int>("Data.MobileBaseSensorState.ValidityDuration", NULL);
    this->mobileBaseSensorStateBuffer = new InfoBuffer<kobuki_msgs::SensorState>(
        (*sc)["TTBWorldModel"]->get<int>("Data.MobileBaseSensorState.BufferLength", NULL));

    this->odomPositionValidityDuration = (*sc)["TTBWorldModel"]->get<int>("Data.OdomPosition.ValidityDuration", NULL);
    this->odomPositionBuffer = new InfoBuffer<geometry::CNPositionAllo>(
        (*sc)["TTBWorldModel"]->get<int>("Data.OdomPosition.BufferLength", NULL));

    this->odomVelocityValidityDuration = (*sc)["TTBWorldModel"]->get<int>("Data.OdomVelocity.ValidityDuration", NULL);
    this->odomVelocityBuffer =
        new InfoBuffer<geometry::CNVecAllo>((*sc)["TTBWorldModel"]->get<int>("Data.OdomVelocity.BufferLength", NULL));

    this->odometryValidityDuration = (*sc)["TTBWorldModel"]->get<int>("Data.Odometry.ValidityDuration", NULL);
    this->odometryBuffer =
        new InfoBuffer<nav_msgs::Odometry>((*sc)["TTBWorldModel"]->get<int>("Data.Odometry.BufferLength", NULL));

    this->rawCameraImageValidityDuration =
        (*sc)["TTBWorldModel"]->get<int>("Data.RawCameraImage.ValidityDuration", NULL);
    this->rawCameraImageBuffer =
        new InfoBuffer<sensor_msgs::Image>((*sc)["TTBWorldModel"]->get<int>("Data.RawCameraImage.BufferLength", NULL));

    // simulation data buffers
    this->gazeboPositionValidityDuration =
        (*sc)["TTBWorldModel"]->get<int>("Data.GazeboPosition.ValidityDuration", NULL);
    this->gazeboPositionBuffer = new InfoBuffer<geometry::CNPositionAllo>(
        (*sc)["TTBWorldModel"]->get<int>("Data.GazeboPosition.BufferLength", NULL));

    this->logicalCameraValidityDuration = (*sc)["TTBWorldModel"]->get<int>("Data.LogicalCamera.ValidityDuration", NULL);
    this->logicalCameraBuffer = new InfoBuffer<ttb_msgs::LogicalCamera>(
        (*sc)["TTBWorldModel"]->get<int>("Data.LogicalCamera.BufferLength", NULL));
}

RawSensorData::~RawSensorData()
{
}

void RawSensorData::processAlvarMarkers(ar_track_alvar_msgs::AlvarMarkersPtr alvarMarkers)
{
    InfoTime time = wm->getTime();

    for (auto marker : alvarMarkers->markers)
    {
        // transform marker in to suitable coordinate system
        geometry_msgs::PoseStamped pose_out;
        marker.pose.header = marker.header; //< REMARK: why this?
        try
        {
            // TODO: make this topics configuration dependent
            listener.waitForTransform("/base_link", "/camera_rgb_optical_frame", ros::Time(0), ros::Duration(5));
            listener.transformPose("/base_link", marker.pose, pose_out);
        }
        catch (exception &e)
        {
            cout << "RawSensorData::processAlvarData: Marker Transform Exception: " << e.what() << endl;
            return;
        }
#ifdef RAW_SENSOR_DEBUG
        cout << "RawSensorData::processAlvarData: marker pos x,y,z: " << pose_out.pose.position.x << " ,"
             << pose_out.pose.position.y << " ," << pose_out.pose.position.z << endl;
        cout << "RawSensorData::processAlvarData: marker orientation w,x,y,z: " << pose_out.pose.orientation.w << " ,"
             << pose_out.pose.orientation.x << " ," << pose_out.pose.orientation.y << " ,"
             << pose_out.pose.orientation.z << endl;
#endif

        // check whether buffer already exists for given marker id
        auto markerMapPair = alvarMarkerMap.find(marker.id);
        if (markerMapPair == alvarMarkerMap.end())
        {
            alvarMarkerMap.emplace(
                marker.id, std::make_shared<InfoBuffer<geometry_msgs::PoseStamped>>(this->alvarMarkerBufferLength));
        }

        // add detected marker to buffer
        auto alvarPoseStamped = make_shared<const InformationElement<geometry_msgs::PoseStamped>>(
            pose_out, time, this->alvarMarkerValidityDuration, marker.confidence);
        alvarMarkerMap[marker.id]->add(alvarPoseStamped);
    }
}

void RawSensorData::processBumperEvent(kobuki_msgs::BumperEvent bumperEvent)
{
    auto ownBumperEventsInfo = make_shared<InformationElement<kobuki_msgs::BumperEvent>>(
        bumperEvent, wm->getTime(), bumperEventValidityDuration, 1.0);
    bumperEventBuffer->add(ownBumperEventsInfo);
}
void RawSensorData::processBumperCloud(sensor_msgs::PointCloud2Ptr bumperCloud)
{
    auto bumperCloudPtr = shared_ptr<sensor_msgs::PointCloud2>(
        bumperCloud.get(), [bumperCloud](sensor_msgs::PointCloud2 *) mutable { bumperCloud.reset(); });
    auto ownBumperSensorsInfo = make_shared<InformationElement<std::shared_ptr<sensor_msgs::PointCloud2>>>(
        bumperCloudPtr, wm->getTime(), bumperCloudValidityDuration, 1.0);
    bumperCloudBuffer->add(ownBumperSensorsInfo);
}
void RawSensorData::processCliffEvent(kobuki_msgs::CliffEvent cliffEvent)
{
    auto ownCliffEventInfo = make_shared<InformationElement<kobuki_msgs::CliffEvent>>(cliffEvent, wm->getTime(),
                                                                                      cliffEventValidityDuration, 1.0);
    this->cliffEventBuffer->add(ownCliffEventInfo);
}
void RawSensorData::processDepthCameraCloud(sensor_msgs::PointCloud2Ptr depthImageCloud)
{
    auto depthImageCloudPtr = shared_ptr<sensor_msgs::PointCloud2>(
        depthImageCloud.get(), [depthImageCloud](sensor_msgs::PointCloud2 *) mutable { depthImageCloud.reset(); });
    auto depthImageCloudPtrInfo =
        make_shared<InformationElement<sensor_msgs::PointCloud2>>(depthImageCloudPtr, wm->getTime());
    depthCameraCloudBuffer->add(depthImageCloudPtrInfo);
}
void RawSensorData::processImu(sensor_msgs::Imu imuData)
{
    auto ownImuDataInfo = make_shared<InformationElement<sensor_msgs::Imu>>(imuData, wm->getTime());
    imuDataBuffer->add(ownImuDataInfo);
}
void RawSensorData::processLaserScan(sensor_msgs::LaserScanPtr laserScan)
{
    auto laserScanPtr = shared_ptr<sensor_msgs::LaserScan>(
        laserScan.get(), [laserScan](sensor_msgs::LaserScan *) mutable { laserScan.reset(); });
    auto laserScanPtrInfo = make_shared<InformationElement<sensor_msgs::LaserScan>>(laserScanPtr, wm->getTime());
    laserScanBuffer->add(laserScanPtrInfo);
}
void RawSensorData::processOdometryData(nav_msgs::OdometryPtr odometry)
{
    InfoTime time = wm->getTime();

    // Position
    auto odomPosition = make_shared<InformationElement<geometry::CNPositionAllo>>(
        geometry::CNPositionAllo(odometry->pose.pose.position.x, odometry->pose.pose.position.y,
                                 odometry->pose.pose.orientation.z / odometry->pose.pose.orientation.w),
        time, odomPositionValidityDuration, 1.0);
    this->odomPositionBuffer->add(odomPosition);

    // Velocity
    auto odomVelocityPtrInfo = make_shared<InformationElement<geometry::CNVecAllo>>(
        geometry::CNVecAllo(odometry->twist.twist.linear.x, odometry->twist.twist.linear.y), time,
        odomVelocityValidityDuration, 1.0);
    odomVelocityBuffer->add(odomVelocityPtrInfo);

    // Odom
    auto odomDataPtr =
        shared_ptr<nav_msgs::Odometry>(odometry.get(), [odometry](nav_msgs::Odometry *) mutable { odometry.reset(); });
    auto ownOdomScanInfo = make_shared<InformationElement<std::shared_ptr<nav_msgs::Odometry>>>(
        odomDataPtr, time, odometryValidityDuration, 1.0);
    odometryBuffer->add(ownOdomScanInfo);
}
void RawSensorData::processGazeboMsg(geometry_msgs::Pose gazeboMsg)
{
    // Position
    auto position = geometry::CNPositionAllo(gazeboMsg.position.x, gazeboMsg.position.y,
                                             gazeboMsg.orientation.z / gazeboMsg.orientation.w);
    auto positionInfo = make_shared<InformationElement<geometry::CNPositionAllo>>(position, wm->getTime(),
                                                                                  gazeboPositionValidityDuration, 1.0);
    gazeboPositionBuffer->add(positionInfo);
}
void RawSensorData::processCameraImageRaw(sensor_msgs::ImagePtr cameraImageRaw)
{
    auto cameraImageRawDataPtr = shared_ptr<sensor_msgs::Image>(
        cameraImageRaw.get(), [cameraImageRaw](sensor_msgs::Image *) mutable { cameraImageRaw.reset(); });
    auto ownCameraImageRawInfo = make_shared<InformationElement<shared_ptr<sensor_msgs::Image>>>(
        cameraImageRawDataPtr, wm->getTime(), this->rawCameraImageValidityDuration, 1.0);
    rawCameraImageBuffer->add(ownCameraImageRawInfo);
}
void RawSensorData::processRobotOnOff(robot_control::RobotCommandPtr robotOnOffData)
{
    shared_ptr<robot_control::RobotCommand> robotOnOffDataPtr = shared_ptr<robot_control::RobotCommand>(
        robotOnOffData.get(), [robotOnOffData](robot_control::RobotCommand *) mutable { robotOnOffData.reset(); });
    shared_ptr<InformationElement<robot_control::RobotCommand>> ownRobotOnOffInfo =
        make_shared<InformationElement<robot_control::RobotCommand>>(robotOnOffDataPtr, wm->getTime());
    robotCommandBuffer->add(ownRobotOnOffInfo);
}

void RawSensorData::processMobileBaseSensorState(kobuki_msgs::SensorStatePtr mobileBaseSensorStateData)
{
    shared_ptr<kobuki_msgs::SensorState> mobBaseSensStateDataPtr = shared_ptr<kobuki_msgs::SensorState>(
        mobileBaseSensorStateData.get(),
        [mobileBaseSensorStateData](kobuki_msgs::SensorState *) mutable { mobileBaseSensorStateData.reset(); });
    shared_ptr<InformationElement<kobuki_msgs::SensorState>> ownMobBaseSensorStateInfo =
        make_shared<InformationElement<kobuki_msgs::SensorState>>(mobBaseSensStateDataPtr, wm->getTime());
    mobileBaseSensorStateBuffer->add(ownMobBaseSensorStateInfo);
}
void RawSensorData::processDockInfrRed(kobuki_msgs::DockInfraRedPtr dockInfrRedData)
{
    shared_ptr<kobuki_msgs::DockInfraRed> dockInfrRedPtr = shared_ptr<kobuki_msgs::DockInfraRed>(
        dockInfrRedData.get(), [dockInfrRedData](kobuki_msgs::DockInfraRed *) mutable { dockInfrRedData.reset(); });
    shared_ptr<InformationElement<kobuki_msgs::DockInfraRed>> ownDockInfrRedInfo =
        make_shared<InformationElement<kobuki_msgs::DockInfraRed>>(dockInfrRedPtr, wm->getTime());
    dockInfrRedBuffer->add(ownDockInfrRedInfo);
}
void RawSensorData::processServeTask(ttb_msgs::ServeTaskPtr serveTask)
{
    shared_ptr<ttb_msgs::ServeTask> serveTaskPtr = shared_ptr<ttb_msgs::ServeTask>(
        serveTask.get(), [serveTask](ttb_msgs::ServeTask *) mutable { serveTask.reset(); });
    shared_ptr<InformationElement<ttb_msgs::ServeTask>> ownServeTask =
        make_shared<InformationElement<ttb_msgs::ServeTask>>(serveTaskPtr, wm->getTime());
    serveTaskBuffer->add(ownServeTask);
    this->wm->taskManager.pushTask(ownServeTask);
}

void RawSensorData::processLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCamera)
{
    shared_ptr<ttb_msgs::LogicalCamera> logicalCameraPtr = shared_ptr<ttb_msgs::LogicalCamera>(
        logicalCamera.get(), [logicalCamera](ttb_msgs::LogicalCamera *) mutable { logicalCamera.reset(); });
    shared_ptr<InformationElement<ttb_msgs::LogicalCamera>> ownLogicalCameraInfo =
        make_shared<InformationElement<ttb_msgs::LogicalCamera>>(logicalCameraPtr, wm->getTime());
    logicalCameraBuffer->add(ownLogicalCameraInfo);
}
}
} /* namespace ttb */
