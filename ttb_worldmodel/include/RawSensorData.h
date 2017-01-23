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
#include "robot_control/RobotCommand.h"
#include "kobuki_msgs/SensorState.h"
#include "kobuki_msgs/DockInfraRed.h"
#include "ar_track_alvar_msgs/AlvarMarkers.h"
#include "ttb_msgs/DriveToPOI.h"
#include "ttb_msgs/LogicalCamera.h"
#include "geometry_msgs/Pose.h"

#include "RingBuffer.h"
#include "InformationElement.h"

namespace ttb {
	class TTBWorldModel;
}

namespace ttb { namespace wm
{
	class RawSensorData
	{
	public:
		RawSensorData(TTBWorldModel* wm, int ringBufferLength);
		virtual ~RawSensorData();

		void processOdometryData(nav_msgs::OdometryPtr odometryData);
		void processLaserScan(sensor_msgs::LaserScanPtr laserScanData);
		void processBumperEvents(kobuki_msgs::BumperEventPtr bumperEventsData);
		void processBumperSensors(sensor_msgs::PointCloud2Ptr bumperSensorsData);
		void processImuData(sensor_msgs::ImuPtr imuData);
		void processCameraPcl(sensor_msgs::PointCloud2Ptr);
		void processCommandVel(geometry_msgs::TwistPtr commandVelData);
		void processJointState(sensor_msgs::JointStatePtr jointStateData);
		void processCliffEvent(kobuki_msgs::CliffEventPtr cliffEventData);
		void processCameraImageRaw(sensor_msgs::ImagePtr cameraImageRawData);
		void processRobotOnOff(robot_control::RobotCommandPtr robotOnOffData);
		void processMobileBaseSensorState(kobuki_msgs::SensorStatePtr mobileBaseSensorStateData);
		void processDockInfrRed(kobuki_msgs::DockInfraRedPtr dockInfrRedData);
		void processAlvarData(ar_track_alvar_msgs::AlvarMarkersPtr alvarData);
		void processDriveToPOICommand(ttb_msgs::DriveToPOIPtr driveToPOICommand);
		void processLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCamera);
		void processGazeboMsgData(geometry_msgs::Pose gazeboMsgData);

		shared_ptr<geometry::CNPosition> getOwnOdomPosition(int index = 0);
		shared_ptr<geometry::CNVelocity2D> getOwnVelocityMotion(int index = 0);
		shared_ptr<sensor_msgs::LaserScan> getOwnLaserScans(int index = 0);
		shared_ptr<kobuki_msgs::BumperEvent> getOwnBumperEvents(int index = 0);
		shared_ptr<sensor_msgs::PointCloud2> getOwnBumperSensors(int index = 0);
		shared_ptr<sensor_msgs::PointCloud2> getOwnCameraPcl(int index = 0);
		shared_ptr<sensor_msgs::Imu> getOwnImuData(int index = 0);
		shared_ptr<kobuki_msgs::CliffEvent> getOwnCliffEvent(int index = 0);
		shared_ptr<sensor_msgs::Image> getOwnCameraImageRaw(int index = 0);
		shared_ptr<robot_control::RobotCommand> getOwnRobotOnOff(int index = 0);
		shared_ptr<kobuki_msgs::SensorState> getOwnMobileBaseSensorState(int index = 0);
		shared_ptr<kobuki_msgs::DockInfraRed> getOwnDockInfrRed(int index = 0);
		shared_ptr<nav_msgs::Odometry> getOwnOdom(int index = 0);
		shared_ptr<ar_track_alvar_msgs::AlvarMarkers> getAlvar(int index = 0);
		shared_ptr<ttb_msgs::LogicalCamera> getLogicalCamera(int index = 0);
		shared_ptr<geometry::CNPosition> getOwnPosition(int index = 0);

	private:
		int ownID;
		int ringBufferLength;
		TTBWorldModel* wm;
		unsigned long maxInformationAge;
		tf::TransformListener listener;
		map<unsigned int, shared_ptr<RingBuffer<InformationElement<geometry_msgs::PoseStamped>>>> ownAlvarMap;
		RingBuffer<InformationElement<geometry::CNPosition>> ownPositionMotion;
		RingBuffer<InformationElement<geometry::CNPosition>> ownPositionGazebo;
		RingBuffer<InformationElement<nav_msgs::Odometry>> ownOdom;
		RingBuffer<InformationElement<geometry::CNVelocity2D>> ownVelocityMotion;
		RingBuffer<InformationElement<sensor_msgs::LaserScan>> ownLaserScans;
		RingBuffer<InformationElement<kobuki_msgs::BumperEvent>> ownBumperEvents;
		RingBuffer<InformationElement<sensor_msgs::PointCloud2>> ownBumperSensors;
		RingBuffer<InformationElement<sensor_msgs::PointCloud2>> ownCameraPcl;
		RingBuffer<InformationElement<sensor_msgs::Imu>> ownImuData;
		RingBuffer<InformationElement<kobuki_msgs::CliffEvent>> ownCliffEvent;
		RingBuffer<InformationElement<sensor_msgs::Image>> ownCameraImageRaw;
		RingBuffer<InformationElement<robot_control::RobotCommand>> ownRobotOnOff;
		RingBuffer<InformationElement<kobuki_msgs::SensorState>> ownMobileBaseSensorState;
		RingBuffer<InformationElement<kobuki_msgs::DockInfraRed>> ownDockInfrRed;
		RingBuffer<InformationElement<ttb_msgs::DriveToPOI>> ownDriveToPOICommand;
		RingBuffer<InformationElement<ttb_msgs::LogicalCamera>> ownLogicalCamera;

	};

}} /* namespace ttb */

#endif /* CNC_TTB_TTB_WORLDMODEL_RAWSENSORDATA_H_ */
