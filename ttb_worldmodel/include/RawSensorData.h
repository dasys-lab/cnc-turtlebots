/*
 * RawSensorData.h
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */

#ifndef CNC_TTB_TTB_WORLDMODEL_RAWSENSORDATA_H_
#define CNC_TTB_TTB_WORLDMODEL_RAWSENSORDATA_H_

#include <vector>
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/Image.h"
#include "container/CNPosition.h"
#include "container/CNVelocity2D.h"
#include "rqt_robot_control/RobotCommand.h"

#include "RingBuffer.h"
#include "InformationElement.h"


using namespace std;

namespace ttb
{

	class TTBWorldModel;
	class RawSensorData
	{
	public:
		RawSensorData(TTBWorldModel* wm, int ringBufferLength);
		virtual ~RawSensorData();

		void processOdometryData(nav_msgs::OdometryConstPtr odometryData);
		void processLaserScan(sensor_msgs::LaserScanPtr laserScanData);
		void processBumperEvents(kobuki_msgs::BumperEventPtr bumperEventsData);
		void processBumperSensors(sensor_msgs::PointCloud2Ptr bumperSensorsData);
		void processImuData(sensor_msgs::ImuPtr imuData);
		void processCameraPcl(sensor_msgs::PointCloud2Ptr);
		void processCommandVel(geometry_msgs::TwistPtr commandVelData);
		void processJointState(sensor_msgs::JointStatePtr jointStateData);
		void processCliffEvent(kobuki_msgs::CliffEventPtr cliffEventData);
		void processCameraImageRaw(sensor_msgs::ImagePtr cameraImageRawData);
		void processRobotOnOff(rqt_robot_control::RobotCommandPtr robotOnOffData);

		shared_ptr<geometry::CNPosition> getOwnPosition(int index = 0);
		shared_ptr<geometry::CNVelocity2D> getOwnVelocityMotion(int index = 0);
		shared_ptr<sensor_msgs::LaserScan> getOwnLaserScans(int index = 0);
		shared_ptr<kobuki_msgs::BumperEvent> getOwnBumperEvents(int index = 0);
		shared_ptr<sensor_msgs::PointCloud2> getOwnBumperSensors(int index = 0);
		shared_ptr<sensor_msgs::PointCloud2> getOwnCameraPcl(int index = 0);
		shared_ptr<sensor_msgs::Imu> getOwnImuData(int index = 0);
		shared_ptr<kobuki_msgs::CliffEvent> getOwnCliffEvent(int index = 0);
		shared_ptr<sensor_msgs::Image> getOwnCameraImageRaw(int index = 0);
		shared_ptr<rqt_robot_control::RobotCommand> getOwnRobotOnOff(int index = 0);

	private:
		int ownID;
		TTBWorldModel* wm;
		unsigned long maxInformationAge;
		RingBuffer<InformationElement<geometry::CNPosition>> ownPositionMotion;
		RingBuffer<InformationElement<geometry::CNVelocity2D>> ownVelocityMotion;
		RingBuffer<InformationElement<sensor_msgs::LaserScan>> ownLaserScans;
		RingBuffer<InformationElement<kobuki_msgs::BumperEvent>> ownBumperEvents;
		RingBuffer<InformationElement<sensor_msgs::PointCloud2>> ownBumperSensors;
		RingBuffer<InformationElement<sensor_msgs::PointCloud2>> ownCameraPcl;
		RingBuffer<InformationElement<sensor_msgs::Imu>> ownImuData;
		RingBuffer<InformationElement<kobuki_msgs::CliffEvent>> ownCliffEvent;
		RingBuffer<InformationElement<sensor_msgs::Image>> ownCameraImageRaw;
		RingBuffer<InformationElement<rqt_robot_control::RobotCommand>> ownRobotOnOff;

	};

} /* namespace ttb */

#endif /* CNC_TTB_TTB_WORLDMODEL_RAWSENSORDATA_H_ */
