/*
 * RawSensorData.cpp
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */

#include "TTBWorldModel.h"

#include "RawSensorData.h"

#include <SystemConfig.h>
#include <container/CNPosition.h>

namespace ttb
{

	RawSensorData::RawSensorData(TTBWorldModel* wm, int ringBufferLength) :
			ownPositionMotion(ringBufferLength), ownVelocityMotion(ringBufferLength), ownLaserScans(ringBufferLength), ownBumperEvents(ringBufferLength),
			ownBumperSensors(ringBufferLength), ownImuData(ringBufferLength), ownCameraPcl(ringBufferLength), ownCliffEvent(ringBufferLength),
			ownCameraImageRaw(ringBufferLength), ownRobotOnOff(ringBufferLength)
	{
		this->wm = wm;
		ownID = supplementary::SystemConfig::getOwnRobotID();

		maxInformationAge = 1000000000;
	}

	RawSensorData::~RawSensorData()
	{

	}

	void RawSensorData::processCommandVel(geometry_msgs::TwistPtr commandVelData) {
		InfoTime time = wm->getTime();
	}
	void RawSensorData::processJointState(sensor_msgs::JointStatePtr jointStateData) {
		InfoTime time = wm->getTime();
	}
	void RawSensorData::processCliffEvent(kobuki_msgs::CliffEventPtr cliffEventData) {
		InfoTime time = wm->getTime();
		shared_ptr<kobuki_msgs::CliffEvent> cliffEventPtr = shared_ptr<kobuki_msgs::CliffEvent>(cliffEventData.get(), [cliffEventData](kobuki_msgs::CliffEvent*) mutable {cliffEventData.reset();});
		shared_ptr<InformationElement<kobuki_msgs::CliffEvent>> ownCliffEventInfo = make_shared<InformationElement<kobuki_msgs::CliffEvent>>(cliffEventPtr, time);
		ownCliffEvent.add(ownCliffEventInfo);
	}
	void RawSensorData::processImuData(sensor_msgs::ImuPtr imuData) {
		InfoTime time = wm->getTime();
		shared_ptr<sensor_msgs::Imu> imuDataPtr = shared_ptr<sensor_msgs::Imu>(imuData.get(), [imuData](sensor_msgs::Imu*) mutable {imuData.reset();});
		shared_ptr<InformationElement<sensor_msgs::Imu>> ownImuDataInfo = make_shared<InformationElement<sensor_msgs::Imu>>(imuDataPtr, time);
		ownImuData.add(ownImuDataInfo);
//		cout << "Imu Ringbuffer first/last: " << ownImuData.getLast()->getInformation()->linear_acceleration << endl;
	}
	void RawSensorData::processCameraPcl(sensor_msgs::PointCloud2Ptr cameraPclData) {
		InfoTime time = wm->getTime();
		shared_ptr<sensor_msgs::PointCloud2> cameraPclPtr = shared_ptr<sensor_msgs::PointCloud2>(cameraPclData.get(), [cameraPclData](sensor_msgs::PointCloud2*) mutable {cameraPclData.reset();});
		shared_ptr<InformationElement<sensor_msgs::PointCloud2>> ownCameraPclInfo = make_shared<InformationElement<sensor_msgs::PointCloud2>>(cameraPclPtr, time);
		ownCameraPcl.add(ownCameraPclInfo);
	}
	void RawSensorData::processBumperEvents(kobuki_msgs::BumperEventPtr bumperEventsData) {
		InfoTime time = wm->getTime();
		shared_ptr<kobuki_msgs::BumperEvent> bumperEventsDataPtr = shared_ptr<kobuki_msgs::BumperEvent>(bumperEventsData.get(), [bumperEventsData](kobuki_msgs::BumperEvent*) mutable {bumperEventsData.reset();});
		shared_ptr<InformationElement<kobuki_msgs::BumperEvent>> ownBumperEventsInfo = make_shared<InformationElement<kobuki_msgs::BumperEvent>>(bumperEventsDataPtr, time);
		ownBumperEvents.add(ownBumperEventsInfo);
	}
	void RawSensorData::processBumperSensors(sensor_msgs::PointCloud2Ptr bumperSensorsData) {
		InfoTime time = wm->getTime();
		shared_ptr<sensor_msgs::PointCloud2> bumperSensorsDataPtr = shared_ptr<sensor_msgs::PointCloud2>(bumperSensorsData.get(), [bumperSensorsData](sensor_msgs::PointCloud2*) mutable {bumperSensorsData.reset();});
		shared_ptr<InformationElement<sensor_msgs::PointCloud2>> ownBumperSensorsInfo = make_shared<InformationElement<sensor_msgs::PointCloud2>>(bumperSensorsDataPtr, time);
		ownBumperSensors.add(ownBumperSensorsInfo);
	}
	void RawSensorData::processLaserScan(sensor_msgs::LaserScanPtr laserScanData) {
		InfoTime time = wm->getTime();
		shared_ptr<sensor_msgs::LaserScan> laserScanDataPtr = shared_ptr<sensor_msgs::LaserScan>(laserScanData.get(), [laserScanData](sensor_msgs::LaserScan*) mutable {laserScanData.reset();});
		shared_ptr<InformationElement<sensor_msgs::LaserScan>> ownLaserScanInfo = make_shared<InformationElement<sensor_msgs::LaserScan>>(laserScanDataPtr, time);
		ownLaserScans.add(ownLaserScanInfo);
	}

	void RawSensorData::processOdometryData(nav_msgs::OdometryConstPtr odometryData)
	{
		InfoTime time = wm->getTime();

		// Position
		shared_ptr<geometry::CNPosition> position = make_shared<geometry::CNPosition>(
				odometryData->pose.pose.position.x, odometryData->pose.pose.position.y,
				odometryData->pose.pose.orientation.z / odometryData->pose.pose.orientation.w);
		shared_ptr<InformationElement<geometry::CNPosition>> ownPositionMotionInfo = make_shared<InformationElement<geometry::CNPosition>>(position,
																																			time);
		ownPositionMotionInfo->certainty = 1.0;
		ownPositionMotion.add(ownPositionMotionInfo);

		// Velocity
		shared_ptr<geometry::CNVelocity2D> velocity = make_shared<geometry::CNVelocity2D>(odometryData->twist.twist.linear.x,
																							odometryData->twist.twist.linear.y);
		shared_ptr<InformationElement<geometry::CNVelocity2D>> ownVelocityMotionInfo = make_shared<InformationElement<geometry::CNVelocity2D>>(velocity, time);
		ownVelocityMotionInfo->certainty = 1.0;
		ownVelocityMotion.add(ownVelocityMotionInfo);

	}

	void RawSensorData::processCameraImageRaw(sensor_msgs::ImagePtr cameraImageRawData)
	{
		InfoTime time = wm->getTime();

		shared_ptr<sensor_msgs::Image> cameraImageRawDataPtr = shared_ptr<sensor_msgs::Image>(cameraImageRawData.get(), [cameraImageRawData](sensor_msgs::Image*) mutable {cameraImageRawData.reset();});
		shared_ptr<InformationElement<sensor_msgs::Image>> ownCameraImageRawInfo = make_shared<InformationElement<sensor_msgs::Image>>(cameraImageRawDataPtr, time);
		ownCameraImageRaw.add(ownCameraImageRawInfo);	
	}

	void RawSensorData::processRobotOnOff(rqt_robot_control::RobotCommandPtr robotOnOffData)
	{
		InfoTime time = wm->getTime();

		shared_ptr<rqt_robot_control::RobotCommand> robotOnOffDataPtr = shared_ptr<rqt_robot_control::RobotCommand>(robotOnOffData.get(), [robotOnOffData](rqt_robot_control::RobotCommand*) mutable {robotOnOffData.reset();});
		shared_ptr<InformationElement<rqt_robot_control::RobotCommand>> ownRobotOnOffInfo = make_shared<InformationElement<rqt_robot_control::RobotCommand>>(robotOnOffDataPtr, time);
		ownRobotOnOff.add(ownRobotOnOffInfo);
	}

	shared_ptr<geometry::CNPosition> RawSensorData::getOwnPosition(int index)
	{
		auto x = ownPositionMotion.getLast(index);

		if( x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge )
		{
			return nullptr;
		}

		return x->getInformation();
	}

	shared_ptr<geometry::CNVelocity2D> RawSensorData::getOwnVelocityMotion(int index)
	{
		auto x = ownVelocityMotion.getLast(index);

		if( x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge )
		{
			return nullptr;
		}

		return x->getInformation();
	}

	shared_ptr<sensor_msgs::LaserScan> RawSensorData::getOwnLaserScans(int index)
	{
		auto x = ownLaserScans.getLast(index);

		if( x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge )
		{
			return nullptr;
		}

		return x->getInformation();
	}

	shared_ptr<kobuki_msgs::BumperEvent> RawSensorData::getOwnBumperEvents(int index)
	{
		auto x = ownBumperEvents.getLast(index);

		if( x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge )
		{
			return nullptr;
		}

		return x->getInformation();
	}

	shared_ptr<sensor_msgs::PointCloud2> RawSensorData::getOwnBumperSensors(int index)
	{
		auto x = ownBumperSensors.getLast(index);

		if( x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge )
		{
			return nullptr;
		}

		return x->getInformation();
	}

	shared_ptr<sensor_msgs::PointCloud2> RawSensorData::getOwnCameraPcl(int index)
	{
		auto x = ownCameraPcl.getLast(index);

		if( x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge )
		{
			return nullptr;
		}

		return x->getInformation();
	}

	shared_ptr<sensor_msgs::Imu> RawSensorData::getOwnImuData(int index)
	{
		auto x = ownImuData.getLast(index);

		if( x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge )
		{
			return nullptr;
		}

		return x->getInformation();
	}

	shared_ptr<kobuki_msgs::CliffEvent> RawSensorData::getOwnCliffEvent(int index)
	{
		auto x = ownCliffEvent.getLast(index);

		if( x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge )
		{
			return nullptr;
		}

		return x->getInformation();
	}

	shared_ptr<sensor_msgs::Image> RawSensorData::getOwnCameraImageRaw(int index)
	{
		auto x = ownCameraImageRaw.getLast(index);

		if( x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge )
		{
			return nullptr;
		}

		return x->getInformation();
	}

	shared_ptr<rqt_robot_control::RobotCommand> RawSensorData::getOwnRobotOnOff(int index)
	{
		auto x = ownRobotOnOff.getLast(index);

		if( x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge )
		{
			return nullptr;
		}

		return x->getInformation();
	}

} /* namespace ttb */

