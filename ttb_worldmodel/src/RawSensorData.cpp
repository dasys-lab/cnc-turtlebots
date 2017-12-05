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
    this->bumperEventBuffer = new InfoBuffer<kobuki_msgs::BumperEvent>(
        (*sc)["TTBWorldModel"]->get<int>("Data.BumperEvent.BufferLength", NULL));
    this->bumperSensorBuffer = new InfoBuffer<sensor_msgs::PointCloud2>(
        (*sc)["TTBWorldModel"]->get<int>("Data.BumperSensor.BufferLength", NULL));
    this->cliffEventBuffer =
        new InfoBuffer<kobuki_msgs::CliffEvent>((*sc)["TTBWorldModel"]->get<int>("Data.CliffEvent.BufferLength", NULL));
    this->depthCameraCloudBuffer = new InfoBuffer<sensor_msgs::PointCloud2>(
        (*sc)["TTBWorldModel"]->get<int>("Data.DepthCameraCloud.BufferLength", NULL));
    this->dockInfrRedBuffer = new InfoBuffer<kobuki_msgs::DockInfraRed>(
        (*sc)["TTBWorldModel"]->get<int>("Data.DockInfrRed.BufferLength", NULL));
    this->imuDataBuffer =
        new InfoBuffer<sensor_msgs::Imu>((*sc)["TTBWorldModel"]->get<int>("Data.IMUData.BufferLength", NULL));
    this->laserScanBuffer =
        new InfoBuffer<sensor_msgs::LaserScan>((*sc)["TTBWorldModel"]->get<int>("Data.LaserScan.BufferLength", NULL));
    this->mobileBaseSensorStateBuffer = new InfoBuffer<kobuki_msgs::SensorState>(
        (*sc)["TTBWorldModel"]->get<int>("Data.MobileBaseSensorState.BufferLength", NULL));
    this->odomPositionBuffer = new InfoBuffer<geometry::CNPositionAllo>(
        (*sc)["TTBWorldModel"]->get<int>("Data.OdomPosition.BufferLength", NULL));
    this->odomVelocityBuffer =
        new InfoBuffer<geometry::CNVecAllo>((*sc)["TTBWorldModel"]->get<int>("Data.OdomVelocity.BufferLength", NULL));
    this->odometryBuffer =
        new InfoBuffer<nav_msgs::Odometry>((*sc)["TTBWorldModel"]->get<int>("Data.Odometry.BufferLength", NULL));
    this->rawCameraImageBuffer =
        new InfoBuffer<sensor_msgs::Image>((*sc)["TTBWorldModel"]->get<int>("Data.RawCameraImage.BufferLength", NULL));

    // simulation data buffers
    this->gazeboPositionBuffer = new InfoBuffer<geometry::CNPositionAllo>(
        (*sc)["TTBWorldModel"]->get<int>("Data.GazeboPosition.BufferLength", NULL));
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

void RawSensorData::processCommandVel(geometry_msgs::TwistPtr commandVelData)
{
    InfoTime time = wm->getTime();
}
void RawSensorData::processJointState(sensor_msgs::JointStatePtr jointStateData)
{
    InfoTime time = wm->getTime();
}
void RawSensorData::processCliffEvent(kobuki_msgs::CliffEventPtr cliffEventData)
{
    InfoTime time = wm->getTime();
    shared_ptr<kobuki_msgs::CliffEvent> cliffEventPtr = shared_ptr<kobuki_msgs::CliffEvent>(
        cliffEventData.get(), [cliffEventData](kobuki_msgs::CliffEvent *) mutable { cliffEventData.reset(); });
    shared_ptr<InformationElement<kobuki_msgs::CliffEvent>> ownCliffEventInfo =
        make_shared<InformationElement<kobuki_msgs::CliffEvent>>(cliffEventPtr, time);
    ownCliffEvent.add(ownCliffEventInfo);
}
void RawSensorData::processImuData(sensor_msgs::ImuPtr imuData)
{
    InfoTime time = wm->getTime();
    shared_ptr<sensor_msgs::Imu> imuDataPtr =
        shared_ptr<sensor_msgs::Imu>(imuData.get(), [imuData](sensor_msgs::Imu *) mutable { imuData.reset(); });
    shared_ptr<InformationElement<sensor_msgs::Imu>> ownImuDataInfo =
        make_shared<InformationElement<sensor_msgs::Imu>>(imuDataPtr, time);
    ownImuData.add(ownImuDataInfo);
    //		cout << "Imu Ringbuffer first/last: " << ownImuData.getLast()->getInformation()->linear_acceleration <<
    // endl;
}
void RawSensorData::processCameraPcl(sensor_msgs::PointCloud2Ptr cameraPclData)
{
    InfoTime time = wm->getTime();
    shared_ptr<sensor_msgs::PointCloud2> cameraPclPtr = shared_ptr<sensor_msgs::PointCloud2>(
        cameraPclData.get(), [cameraPclData](sensor_msgs::PointCloud2 *) mutable { cameraPclData.reset(); });
    shared_ptr<InformationElement<sensor_msgs::PointCloud2>> ownCameraPclInfo =
        make_shared<InformationElement<sensor_msgs::PointCloud2>>(cameraPclPtr, time);
    ownCameraPcl.add(ownCameraPclInfo);
}
void RawSensorData::processBumperEvents(kobuki_msgs::BumperEventPtr bumperEventsData)
{
    InfoTime time = wm->getTime();
    shared_ptr<kobuki_msgs::BumperEvent> bumperEventsDataPtr = shared_ptr<kobuki_msgs::BumperEvent>(
        bumperEventsData.get(), [bumperEventsData](kobuki_msgs::BumperEvent *) mutable { bumperEventsData.reset(); });
    shared_ptr<InformationElement<kobuki_msgs::BumperEvent>> ownBumperEventsInfo =
        make_shared<InformationElement<kobuki_msgs::BumperEvent>>(bumperEventsDataPtr, time);
    ownBumperEvents.add(ownBumperEventsInfo);
}
void RawSensorData::processBumperSensors(sensor_msgs::PointCloud2Ptr bumperSensorsData)
{
    InfoTime time = wm->getTime();
    shared_ptr<sensor_msgs::PointCloud2> bumperSensorsDataPtr = shared_ptr<sensor_msgs::PointCloud2>(
        bumperSensorsData.get(),
        [bumperSensorsData](sensor_msgs::PointCloud2 *) mutable { bumperSensorsData.reset(); });
    shared_ptr<InformationElement<sensor_msgs::PointCloud2>> ownBumperSensorsInfo =
        make_shared<InformationElement<sensor_msgs::PointCloud2>>(bumperSensorsDataPtr, time);
    ownBumperSensors.add(ownBumperSensorsInfo);
}
void RawSensorData::processLaserScan(sensor_msgs::LaserScanPtr laserScanData)
{
    InfoTime time = wm->getTime();
    shared_ptr<sensor_msgs::LaserScan> laserScanDataPtr = shared_ptr<sensor_msgs::LaserScan>(
        laserScanData.get(), [laserScanData](sensor_msgs::LaserScan *) mutable { laserScanData.reset(); });
    shared_ptr<InformationElement<sensor_msgs::LaserScan>> ownLaserScanInfo =
        make_shared<InformationElement<sensor_msgs::LaserScan>>(laserScanDataPtr, time);
    ownLaserScans.add(ownLaserScanInfo);
}

void RawSensorData::processOdometryData(nav_msgs::OdometryPtr odometryData)
{
    InfoTime time = wm->getTime();

    // Position
    auto odomPosition = make_shared<InformationElement<geometry::CNPositionAllo>>(
        geometry::CNPositionAllo(odometryData->pose.pose.position.x, odometryData->pose.pose.position.y,
                                 odometryData->pose.pose.orientation.z / odometryData->pose.pose.orientation.w),
        time, this->maxValidity, 1.0);
    this->odomPositionBuffer.add(odomPosition);

    // TODO: go on here

    // Velocity
    shared_ptr<geometry::CNVelocity2D> velocity =
        make_shared<geometry::CNVelocity2D>(odometryData->twist.twist.linear.x, odometryData->twist.twist.linear.y);
    shared_ptr<InformationElement<geometry::CNVelocity2D>> ownVelocityMotionInfo =
        make_shared<InformationElement<geometry::CNVelocity2D>>(velocity, time);
    ownVelocityMotionInfo->certainty = 1.0;
    ownVelocityMotion.add(ownVelocityMotionInfo);

    // Odom
    shared_ptr<nav_msgs::Odometry> odomDataPtr = shared_ptr<nav_msgs::Odometry>(
        odometryData.get(), [odometryData](nav_msgs::Odometry *) mutable { odometryData.reset(); });
    shared_ptr<InformationElement<nav_msgs::Odometry>> ownOdomScanInfo =
        make_shared<InformationElement<nav_msgs::Odometry>>(odomDataPtr, time);
    ownOdom.add(ownOdomScanInfo);
}

void RawSensorData::processGazeboMsgData(geometry_msgs::Pose gazeboMsgData)
{
    InfoTime time = wm->getTime();

    // Position
    shared_ptr<geometry::CNPosition> position = make_shared<geometry::CNPosition>(
        gazeboMsgData.position.x, gazeboMsgData.position.y, gazeboMsgData.orientation.z / gazeboMsgData.orientation.w);
    shared_ptr<InformationElement<geometry::CNPosition>> ownPositionGazeboInfo =
        make_shared<InformationElement<geometry::CNPosition>>(position, time);
    ownPositionGazeboInfo->certainty = 1.0;
    ownPositionGazebo.add(ownPositionGazeboInfo);

    //		// Velocity
    //		shared_ptr<geometry::CNVelocity2D> velocity = make_shared<geometry::CNVelocity2D>(
    //				odometryData->twist.twist.linear.x, odometryData->twist.twist.linear.y);
    //		shared_ptr<InformationElement<geometry::CNVelocity2D>> ownVelocityMotionInfo = make_shared<
    //				InformationElement<geometry::CNVelocity2D>>(velocity, time);
    //		ownVelocityMotionInfo->certainty = 1.0;
    //		ownVelocityMotion.add(ownVelocityMotionInfo);
    //
    //		//Odom
    //		shared_ptr<nav_msgs::Odometry> odomDataPtr = shared_ptr<nav_msgs::Odometry>(
    //				odometryData.get(), [odometryData](nav_msgs::Odometry*) mutable
    //				{	odometryData.reset();});
    //		shared_ptr<InformationElement<nav_msgs::Odometry>> ownOdomScanInfo = make_shared<
    //				InformationElement<nav_msgs::Odometry>>(odomDataPtr, time);
    //		ownOdom.add(ownOdomScanInfo);
}

void RawSensorData::processCameraImageRaw(sensor_msgs::ImagePtr cameraImageRawData)
{
    InfoTime time = wm->getTime();

    shared_ptr<sensor_msgs::Image> cameraImageRawDataPtr = shared_ptr<sensor_msgs::Image>(
        cameraImageRawData.get(), [cameraImageRawData](sensor_msgs::Image *) mutable { cameraImageRawData.reset(); });
    shared_ptr<InformationElement<sensor_msgs::Image>> ownCameraImageRawInfo =
        make_shared<InformationElement<sensor_msgs::Image>>(cameraImageRawDataPtr, time);
    ownCameraImageRaw.add(ownCameraImageRawInfo);
}

void RawSensorData::processRobotOnOff(robot_control::RobotCommandPtr robotOnOffData)
{
    InfoTime time = wm->getTime();

    shared_ptr<robot_control::RobotCommand> robotOnOffDataPtr = shared_ptr<robot_control::RobotCommand>(
        robotOnOffData.get(), [robotOnOffData](robot_control::RobotCommand *) mutable { robotOnOffData.reset(); });
    shared_ptr<InformationElement<robot_control::RobotCommand>> ownRobotOnOffInfo =
        make_shared<InformationElement<robot_control::RobotCommand>>(robotOnOffDataPtr, time);
    ownRobotOnOff.add(ownRobotOnOffInfo);
}

void RawSensorData::processMobileBaseSensorState(kobuki_msgs::SensorStatePtr mobileBaseSensorStateData)
{
    InfoTime time = wm->getTime();

    shared_ptr<kobuki_msgs::SensorState> mobBaseSensStateDataPtr = shared_ptr<kobuki_msgs::SensorState>(
        mobileBaseSensorStateData.get(),
        [mobileBaseSensorStateData](kobuki_msgs::SensorState *) mutable { mobileBaseSensorStateData.reset(); });
    shared_ptr<InformationElement<kobuki_msgs::SensorState>> ownMobBaseSensorStateInfo =
        make_shared<InformationElement<kobuki_msgs::SensorState>>(mobBaseSensStateDataPtr, time);
    ownMobileBaseSensorState.add(ownMobBaseSensorStateInfo);
}
void RawSensorData::processDockInfrRed(kobuki_msgs::DockInfraRedPtr dockInfrRedData)
{
    InfoTime time = wm->getTime();

    shared_ptr<kobuki_msgs::DockInfraRed> dockInfrRedPtr = shared_ptr<kobuki_msgs::DockInfraRed>(
        dockInfrRedData.get(), [dockInfrRedData](kobuki_msgs::DockInfraRed *) mutable { dockInfrRedData.reset(); });
    shared_ptr<InformationElement<kobuki_msgs::DockInfraRed>> ownDockInfrRedInfo =
        make_shared<InformationElement<kobuki_msgs::DockInfraRed>>(dockInfrRedPtr, time);
    ownDockInfrRed.add(ownDockInfrRedInfo);
}
void RawSensorData::processServeTask(ttb_msgs::ServeTaskPtr serveTask)
{
    InfoTime time = wm->getTime();

    shared_ptr<ttb_msgs::ServeTask> serveTaskPtr = shared_ptr<ttb_msgs::ServeTask>(
        serveTask.get(), [serveTask](ttb_msgs::ServeTask *) mutable { serveTask.reset(); });
    shared_ptr<InformationElement<ttb_msgs::ServeTask>> ownServeTask =
        make_shared<InformationElement<ttb_msgs::ServeTask>>(serveTaskPtr, time);
    ownServeTasks.add(ownServeTask);
    this->wm->taskManager.pushTask(ownServeTask);
}

void RawSensorData::processLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCamera)
{
    InfoTime time = wm->getTime();

    shared_ptr<ttb_msgs::LogicalCamera> logicalCameraPtr = shared_ptr<ttb_msgs::LogicalCamera>(
        logicalCamera.get(), [logicalCamera](ttb_msgs::LogicalCamera *) mutable { logicalCamera.reset(); });
    shared_ptr<InformationElement<ttb_msgs::LogicalCamera>> ownLogicalCameraInfo =
        make_shared<InformationElement<ttb_msgs::LogicalCamera>>(logicalCameraPtr, time);
    ownLogicalCamera.add(ownLogicalCameraInfo);
}

// shared_ptr<geometry::CNPosition> RawSensorData::getOwnOdomPosition(int index)
//{
//    auto x = ownPositionMotion.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
// shared_ptr<geometry::CNPosition> RawSensorData::getOwnPosition(int index)
//{
//    auto x = ownPositionGazebo.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
// shared_ptr<geometry::CNVelocity2D> RawSensorData::getOwnVelocityMotion(int index)
//{
//    auto x = ownVelocityMotion.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
// shared_ptr<sensor_msgs::LaserScan> RawSensorData::getOwnLaserScans(int index)
//{
//    auto x = ownLaserScans.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
// shared_ptr<kobuki_msgs::BumperEvent> RawSensorData::getOwnBumperEvents(int index)
//{
//    auto x = ownBumperEvents.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
// shared_ptr<sensor_msgs::PointCloud2> RawSensorData::getOwnBumperSensors(int index)
//{
//    auto x = ownBumperSensors.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
// shared_ptr<sensor_msgs::PointCloud2> RawSensorData::getOwnCameraPcl(int index)
//{
//    auto x = ownCameraPcl.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
// shared_ptr<sensor_msgs::Imu> RawSensorData::getOwnImuData(int index)
//{
//    auto x = ownImuData.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
// shared_ptr<kobuki_msgs::CliffEvent> RawSensorData::getOwnCliffEvent(int index)
//{
//    auto x = ownCliffEvent.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
// shared_ptr<sensor_msgs::Image> RawSensorData::getOwnCameraImageRaw(int index)
//{
//    auto x = ownCameraImageRaw.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
// shared_ptr<kobuki_msgs::SensorState> RawSensorData::getOwnMobileBaseSensorState(int index)
//{
//    auto x = ownMobileBaseSensorState.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
// shared_ptr<kobuki_msgs::DockInfraRed> RawSensorData::getOwnDockInfrRed(int index)
//{
//    auto x = ownDockInfrRed.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
// shared_ptr<robot_control::RobotCommand> RawSensorData::getOwnRobotOnOff(int index)
//{
//    auto x = ownRobotOnOff.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
// shared_ptr<nav_msgs::Odometry> RawSensorData::getOwnOdom(int index)
//{
//    auto x = ownOdom.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
//
// shared_ptr<ttb_msgs::LogicalCamera> RawSensorData::getLogicalCamera(int index)
//{
//    auto x = ownLogicalCamera.getLast(index);
//
//    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//    {
//        return nullptr;
//    }
//
//    return x->getInformation();
//}
}
} /* namespace ttb */
