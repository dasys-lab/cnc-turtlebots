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
#include "container/CNPosition.h"
#include "container/CNVelocity2D.h"

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

	private:
		int ownID;
		TTBWorldModel* wm;
		RingBuffer<InformationElement<geometry::CNPosition>> ownPositionMotion;
		RingBuffer<InformationElement<geometry::CNVelocity2D>> ownVelocityMotion;
		RingBuffer<InformationElement<sensor_msgs::LaserScan>> ownLaserScans;
		RingBuffer<InformationElement<kobuki_msgs::BumperEvent>> ownBumperEvents;
		RingBuffer<InformationElement<sensor_msgs::PointCloud2>> ownBumperSensors;
		RingBuffer<InformationElement<sensor_msgs::PointCloud2>> ownCameraPcl;
		RingBuffer<InformationElement<sensor_msgs::Imu>> ownImuData;
		RingBuffer<InformationElement<kobuki_msgs::CliffEvent>> ownCliffEvent;

	};

} /* namespace ttb */

#endif /* CNC_TTB_TTB_WORLDMODEL_RAWSENSORDATA_H_ */
