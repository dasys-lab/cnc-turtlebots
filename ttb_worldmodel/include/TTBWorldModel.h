/*
 * TTBWorldModel.h
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */

#ifndef TTBWORLDMODEL_H_
#define TTBWORLDMODEL_H_


#include <list>
#include <iostream>
#include <tuple>
#include <mutex>
#include <string>

#include <ros/ros.h>

#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/PointCloud2.h"
#include "kobuki_msgs/BumperEvent.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/JointState.h"
#include "kobuki_msgs/CliffEvent.h"
#include "sensor_msgs/Image.h"
#include "robot_control/RobotCommand.h"
#include "kobuki_msgs/SensorState.h"
#include "kobuki_msgs/DockInfraRed.h"
#include "ar_track_alvar_msgs/AlvarMarkers.h"
#include "tf/transform_listener.h"
#include "ttb_msgs/DriveToPOI.h"

#include "SystemConfig.h"
#include "RawSensorData.h"
#include "Robots.h"
#include "TaskManager.h"
#include "EventTrigger.h"

namespace supplementary {
	class SystemConfig;
}

namespace alica {
	class AlicaEngine;
}

using namespace std;

namespace ttb
{
	class WrappedMessageHandler;

	class TTBWorldModel
	{
	public:
		static TTBWorldModel* get(); /**< Singleton Getter */

		bool setEngine(alica::AlicaEngine* ae);
		virtual ~TTBWorldModel();
		InfoTime getTime();
		int getRingBufferLength();

		// Public Data Access Classes
		RawSensorData rawSensorData;
		TaskManager taskManager;
		Robots robots;


	private:

		TTBWorldModel(); /**< Private Singleton Constructor */

		supplementary::SystemConfig* sc;
		alica::AlicaEngine* alicaEngine;
		WrappedMessageHandler* wrappedMessageHandler;

		int ownID;
		int ringBufferLength;

		mutex wmMutex;


		// ROS Stuff
		ros::NodeHandle n;
		ros::AsyncSpinner* spinner;

		string drivePOITopic;
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

		ros::Subscriber odometrySub;
		ros::Subscriber alvarSub;
		ros::Subscriber driveToPOISub;
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
		void onDriveToPOICommand(ttb_msgs::DriveToPOIPtr driveToPOICommand);

	protected:

	};

} /* namespace ttb */

#endif /* TTBWORLDMODEL_H_ */
