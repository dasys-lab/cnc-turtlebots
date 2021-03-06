/*
 * RawSensorData.cpp
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */
#include <RawSensorData.h>

#include <TTBWorldModel.h>
#include <kobuki_msgs/CliffEvent.h>
#include <nav_msgs/Odometry.h>

#include <SystemConfig.h>
#include <ar_track_alvar_msgs/AlvarMarker.h>

#include <exception>
#include <iostream>
#include <map>
#include <memory>
#include <utility>

namespace ttb
{
namespace wm
{

RawSensorData::RawSensorData(TTBWorldModel *wm, int ringBufferLength)
    : ownPositionMotion(ringBufferLength)
    , ownPositionGazebo(ringBufferLength)
    , ownVelocityMotion(ringBufferLength)
    , ownLaserScans(ringBufferLength)
    , ownBumperEvents(ringBufferLength)
    , ownBumperSensors(ringBufferLength)
    , ownImuData(ringBufferLength)
    , ownCameraPcl(ringBufferLength)
    , ownCliffEvent(ringBufferLength)
    , ownCameraImageRaw(ringBufferLength)
    , ownRobotOnOff(ringBufferLength)
    , ownMobileBaseSensorState(ringBufferLength)
    , ownDockInfrRed(ringBufferLength)
    , ownOdom(ringBufferLength)
    , ownServeTasks(ringBufferLength)
    , ownLogicalCamera(ringBufferLength)
{
    this->wm = wm;
    ownID = supplementary::SystemConfig::getOwnRobotID();
    this->ringBufferLength = ringBufferLength;
    maxInformationAge = 1000000000;
}

RawSensorData::~RawSensorData()
{
}

void RawSensorData::processAlvarData(ar_track_alvar_msgs::AlvarMarkersPtr alvarData)
{

    InfoTime time = wm->getTime();

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << alvarData->markers.size() << endl;
    for (auto marker : alvarData->markers)
    {
        geometry_msgs::PoseStamped pose_out;

        //			pose_out.header.frame_id = "/base_link";
        //			cout << "marker frame_id: " << marker << endl;
        //			marker.header.frame_id = "/camera_rgb_optical_frame";
        //			listener.waitForTransform("base_link","camera_rgb_optical_frame", ros::Time(0), ros::Duration(5));

        //			tf::StampedTransform stampedTransform;

        marker.pose.header = marker.header;
        //			marker.pose.header.stamp = ros::Time::now();

        try
        {
            listener.waitForTransform("/base_link", "/camera_rgb_optical_frame", ros::Time(0), ros::Duration(5));
            listener.transformPose("/base_link", marker.pose, pose_out);
        }
        catch (exception &e)
        {
            cout << "Marker Transform Exception: " << e.what() << endl;
            return;
        }
        //			listener.lookupTransform("/base_link",ros::Time(0), "/camera_rgb_optical_frame", ros::Time(0),"/base_link" , stampedTransform);

        //			pose_out.pose.position.x = stampedTransform.getOrigin().x();
        //			pose_out.pose.position.y = stampedTransform.getOrigin().y();
        //			pose_out.pose.position.z = stampedTransform.getOrigin().z();
        //			pose_out.pose.orientation.w = stampedTransform.getRotation().w();
        //			pose_out.pose.orientation.x = stampedTransform.getRotation().x();
        //			pose_out.pose.orientation.y = stampedTransform.getRotation().y();
        //			pose_out.pose.orientation.z = stampedTransform.getRotation().z();

        cout << "marker pos x,y,z: " << pose_out.pose.position.x << " ," << pose_out.pose.position.y << " ," << pose_out.pose.position.z << endl;
        cout << "marker orientation w,x,y,z: " << pose_out.pose.orientation.w << " ," << pose_out.pose.orientation.x << " ," << pose_out.pose.orientation.y
             << " ," << pose_out.pose.orientation.z << endl;

        shared_ptr<geometry_msgs::PoseStamped> poseStampedDataPtr = make_shared<geometry_msgs::PoseStamped>(pose_out);
        shared_ptr<InformationElement<geometry_msgs::PoseStamped>> ownposeStampedInfo =
            make_shared<InformationElement<geometry_msgs::PoseStamped>>(poseStampedDataPtr, time);
        auto markerMapPair = ownAlvarMap.find(marker.id);

        if (markerMapPair != ownAlvarMap.end())
        {
            ownAlvarMap[marker.id]->add(ownposeStampedInfo);
        }
        else
        {
            shared_ptr<RingBuffer<InformationElement<geometry_msgs::PoseStamped>>> bufferptr =
                make_shared<RingBuffer<InformationElement<geometry_msgs::PoseStamped>>>(ringBufferLength);
            ownAlvarMap.insert(std::pair<unsigned int, shared_ptr<RingBuffer<InformationElement<geometry_msgs::PoseStamped>>>>(marker.id, bufferptr));
        }
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
    shared_ptr<kobuki_msgs::CliffEvent> cliffEventPtr =
        shared_ptr<kobuki_msgs::CliffEvent>(cliffEventData.get(), [cliffEventData](kobuki_msgs::CliffEvent *) mutable { cliffEventData.reset(); });
    shared_ptr<InformationElement<kobuki_msgs::CliffEvent>> ownCliffEventInfo = make_shared<InformationElement<kobuki_msgs::CliffEvent>>(cliffEventPtr, time);
    ownCliffEvent.add(ownCliffEventInfo);
}
void RawSensorData::processImuData(sensor_msgs::ImuPtr imuData)
{
    InfoTime time = wm->getTime();
    shared_ptr<sensor_msgs::Imu> imuDataPtr = shared_ptr<sensor_msgs::Imu>(imuData.get(), [imuData](sensor_msgs::Imu *) mutable { imuData.reset(); });
    shared_ptr<InformationElement<sensor_msgs::Imu>> ownImuDataInfo = make_shared<InformationElement<sensor_msgs::Imu>>(imuDataPtr, time);
    ownImuData.add(ownImuDataInfo);
    //		cout << "Imu Ringbuffer first/last: " << ownImuData.getLast()->getInformation()->linear_acceleration << endl;
}
void RawSensorData::processCameraPcl(sensor_msgs::PointCloud2Ptr cameraPclData)
{
    InfoTime time = wm->getTime();
    shared_ptr<sensor_msgs::PointCloud2> cameraPclPtr =
        shared_ptr<sensor_msgs::PointCloud2>(cameraPclData.get(), [cameraPclData](sensor_msgs::PointCloud2 *) mutable { cameraPclData.reset(); });
    shared_ptr<InformationElement<sensor_msgs::PointCloud2>> ownCameraPclInfo = make_shared<InformationElement<sensor_msgs::PointCloud2>>(cameraPclPtr, time);
    ownCameraPcl.add(ownCameraPclInfo);
}
void RawSensorData::processBumperEvents(kobuki_msgs::BumperEventPtr bumperEventsData)
{
    InfoTime time = wm->getTime();
    shared_ptr<kobuki_msgs::BumperEvent> bumperEventsDataPtr =
        shared_ptr<kobuki_msgs::BumperEvent>(bumperEventsData.get(), [bumperEventsData](kobuki_msgs::BumperEvent *) mutable { bumperEventsData.reset(); });
    shared_ptr<InformationElement<kobuki_msgs::BumperEvent>> ownBumperEventsInfo =
        make_shared<InformationElement<kobuki_msgs::BumperEvent>>(bumperEventsDataPtr, time);
    ownBumperEvents.add(ownBumperEventsInfo);
}
void RawSensorData::processBumperSensors(sensor_msgs::PointCloud2Ptr bumperSensorsData)
{
    InfoTime time = wm->getTime();
    shared_ptr<sensor_msgs::PointCloud2> bumperSensorsDataPtr =
        shared_ptr<sensor_msgs::PointCloud2>(bumperSensorsData.get(), [bumperSensorsData](sensor_msgs::PointCloud2 *) mutable { bumperSensorsData.reset(); });
    shared_ptr<InformationElement<sensor_msgs::PointCloud2>> ownBumperSensorsInfo =
        make_shared<InformationElement<sensor_msgs::PointCloud2>>(bumperSensorsDataPtr, time);
    ownBumperSensors.add(ownBumperSensorsInfo);
}
void RawSensorData::processLaserScan(sensor_msgs::LaserScanPtr laserScanData)
{
    InfoTime time = wm->getTime();
    shared_ptr<sensor_msgs::LaserScan> laserScanDataPtr =
        shared_ptr<sensor_msgs::LaserScan>(laserScanData.get(), [laserScanData](sensor_msgs::LaserScan *) mutable { laserScanData.reset(); });
    shared_ptr<InformationElement<sensor_msgs::LaserScan>> ownLaserScanInfo = make_shared<InformationElement<sensor_msgs::LaserScan>>(laserScanDataPtr, time);
    ownLaserScans.add(ownLaserScanInfo);
}

void RawSensorData::processOdometryData(nav_msgs::OdometryPtr odometryData)
{
    InfoTime time = wm->getTime();

    // Position
    shared_ptr<geometry::CNPosition> position = make_shared<geometry::CNPosition>(
        odometryData->pose.pose.position.x, odometryData->pose.pose.position.y, odometryData->pose.pose.orientation.z / odometryData->pose.pose.orientation.w);
    shared_ptr<InformationElement<geometry::CNPosition>> ownPositionMotionInfo = make_shared<InformationElement<geometry::CNPosition>>(position, time);
    ownPositionMotionInfo->certainty = 1.0;
    ownPositionMotion.add(ownPositionMotionInfo);

    // Velocity
    shared_ptr<geometry::CNVelocity2D> velocity = make_shared<geometry::CNVelocity2D>(odometryData->twist.twist.linear.x, odometryData->twist.twist.linear.y);
    shared_ptr<InformationElement<geometry::CNVelocity2D>> ownVelocityMotionInfo = make_shared<InformationElement<geometry::CNVelocity2D>>(velocity, time);
    ownVelocityMotionInfo->certainty = 1.0;
    ownVelocityMotion.add(ownVelocityMotionInfo);

    // Odom
    shared_ptr<nav_msgs::Odometry> odomDataPtr =
        shared_ptr<nav_msgs::Odometry>(odometryData.get(), [odometryData](nav_msgs::Odometry *) mutable { odometryData.reset(); });
    shared_ptr<InformationElement<nav_msgs::Odometry>> ownOdomScanInfo = make_shared<InformationElement<nav_msgs::Odometry>>(odomDataPtr, time);
    ownOdom.add(ownOdomScanInfo);
}

void RawSensorData::processGazeboMsgData(geometry_msgs::Pose gazeboMsgData)
{
    InfoTime time = wm->getTime();

    // Position
    shared_ptr<geometry::CNPosition> position =
        make_shared<geometry::CNPosition>(gazeboMsgData.position.x, gazeboMsgData.position.y, gazeboMsgData.orientation.z / gazeboMsgData.orientation.w);
    shared_ptr<InformationElement<geometry::CNPosition>> ownPositionGazeboInfo = make_shared<InformationElement<geometry::CNPosition>>(position, time);
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

    shared_ptr<sensor_msgs::Image> cameraImageRawDataPtr =
        shared_ptr<sensor_msgs::Image>(cameraImageRawData.get(), [cameraImageRawData](sensor_msgs::Image *) mutable { cameraImageRawData.reset(); });
    shared_ptr<InformationElement<sensor_msgs::Image>> ownCameraImageRawInfo = make_shared<InformationElement<sensor_msgs::Image>>(cameraImageRawDataPtr, time);
    ownCameraImageRaw.add(ownCameraImageRawInfo);
}

void RawSensorData::processRobotOnOff(robot_control::RobotCommandPtr robotOnOffData)
{
    InfoTime time = wm->getTime();

    shared_ptr<robot_control::RobotCommand> robotOnOffDataPtr =
        shared_ptr<robot_control::RobotCommand>(robotOnOffData.get(), [robotOnOffData](robot_control::RobotCommand *) mutable { robotOnOffData.reset(); });
    shared_ptr<InformationElement<robot_control::RobotCommand>> ownRobotOnOffInfo =
        make_shared<InformationElement<robot_control::RobotCommand>>(robotOnOffDataPtr, time);
    ownRobotOnOff.add(ownRobotOnOffInfo);
}

void RawSensorData::processMobileBaseSensorState(kobuki_msgs::SensorStatePtr mobileBaseSensorStateData)
{
    InfoTime time = wm->getTime();

    shared_ptr<kobuki_msgs::SensorState> mobBaseSensStateDataPtr = shared_ptr<kobuki_msgs::SensorState>(
        mobileBaseSensorStateData.get(), [mobileBaseSensorStateData](kobuki_msgs::SensorState *) mutable { mobileBaseSensorStateData.reset(); });
    shared_ptr<InformationElement<kobuki_msgs::SensorState>> ownMobBaseSensorStateInfo =
        make_shared<InformationElement<kobuki_msgs::SensorState>>(mobBaseSensStateDataPtr, time);
    ownMobileBaseSensorState.add(ownMobBaseSensorStateInfo);
}
void RawSensorData::processDockInfrRed(kobuki_msgs::DockInfraRedPtr dockInfrRedData)
{
    InfoTime time = wm->getTime();

    shared_ptr<kobuki_msgs::DockInfraRed> dockInfrRedPtr =
        shared_ptr<kobuki_msgs::DockInfraRed>(dockInfrRedData.get(), [dockInfrRedData](kobuki_msgs::DockInfraRed *) mutable { dockInfrRedData.reset(); });
    shared_ptr<InformationElement<kobuki_msgs::DockInfraRed>> ownDockInfrRedInfo =
        make_shared<InformationElement<kobuki_msgs::DockInfraRed>>(dockInfrRedPtr, time);
    ownDockInfrRed.add(ownDockInfrRedInfo);
}
void RawSensorData::processServeTask(ttb_msgs::ServeTaskPtr serveTask)
{
    InfoTime time = wm->getTime();

    shared_ptr<ttb_msgs::ServeTask> serveTaskPtr =
        shared_ptr<ttb_msgs::ServeTask>(serveTask.get(), [serveTask](ttb_msgs::ServeTask *) mutable { serveTask.reset(); });
    shared_ptr<InformationElement<ttb_msgs::ServeTask>> ownServeTask = make_shared<InformationElement<ttb_msgs::ServeTask>>(serveTaskPtr, time);
    ownServeTasks.add(ownServeTask);
    this->wm->taskManager.pushTask(ownServeTask);
}

void RawSensorData::processLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCamera)
{
    InfoTime time = wm->getTime();

    shared_ptr<ttb_msgs::LogicalCamera> logicalCameraPtr =
        shared_ptr<ttb_msgs::LogicalCamera>(logicalCamera.get(), [logicalCamera](ttb_msgs::LogicalCamera *) mutable { logicalCamera.reset(); });
    shared_ptr<InformationElement<ttb_msgs::LogicalCamera>> ownLogicalCameraInfo =
        make_shared<InformationElement<ttb_msgs::LogicalCamera>>(logicalCameraPtr, time);
    ownLogicalCamera.add(ownLogicalCameraInfo);
}

shared_ptr<geometry::CNPosition> RawSensorData::getOwnOdomPosition(int index)
{
    auto x = ownPositionMotion.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
shared_ptr<geometry::CNPosition> RawSensorData::getOwnPosition(int index)
{
    auto x = ownPositionGazebo.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
shared_ptr<geometry::CNVelocity2D> RawSensorData::getOwnVelocityMotion(int index)
{
    auto x = ownVelocityMotion.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
shared_ptr<sensor_msgs::LaserScan> RawSensorData::getOwnLaserScans(int index)
{
    auto x = ownLaserScans.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
shared_ptr<kobuki_msgs::BumperEvent> RawSensorData::getOwnBumperEvents(int index)
{
    auto x = ownBumperEvents.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
shared_ptr<sensor_msgs::PointCloud2> RawSensorData::getOwnBumperSensors(int index)
{
    auto x = ownBumperSensors.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
shared_ptr<sensor_msgs::PointCloud2> RawSensorData::getOwnCameraPcl(int index)
{
    auto x = ownCameraPcl.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
shared_ptr<sensor_msgs::Imu> RawSensorData::getOwnImuData(int index)
{
    auto x = ownImuData.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
shared_ptr<kobuki_msgs::CliffEvent> RawSensorData::getOwnCliffEvent(int index)
{
    auto x = ownCliffEvent.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
shared_ptr<sensor_msgs::Image> RawSensorData::getOwnCameraImageRaw(int index)
{
    auto x = ownCameraImageRaw.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
shared_ptr<kobuki_msgs::SensorState> RawSensorData::getOwnMobileBaseSensorState(int index)
{
    auto x = ownMobileBaseSensorState.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
shared_ptr<kobuki_msgs::DockInfraRed> RawSensorData::getOwnDockInfrRed(int index)
{
    auto x = ownDockInfrRed.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
shared_ptr<robot_control::RobotCommand> RawSensorData::getOwnRobotOnOff(int index)
{
    auto x = ownRobotOnOff.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
shared_ptr<nav_msgs::Odometry> RawSensorData::getOwnOdom(int index)
{
    auto x = ownOdom.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}

shared_ptr<ttb_msgs::LogicalCamera> RawSensorData::getLogicalCamera(int index)
{
    auto x = ownLogicalCamera.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}
}
} /* namespace ttb */
