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
#include "rqt_robot_control/RobotCommand.h"

#include "SystemConfig.h"
#include "RawSensorData.h"
#include "Robots.h"
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
		Robots robots;

	private:

		TTBWorldModel(); /**< Private Singleton Constructor */

		supplementary::SystemConfig* sc;
		alica::AlicaEngine* alicaEngine;

		int ownID;
		int ringBufferLength;

		mutex wmMutex;


		// ROS Stuff
		ros::NodeHandle n;
		ros::AsyncSpinner* spinner;

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

		ros::Subscriber odometrySub;
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

		void onOdometryData(nav_msgs::OdometryConstPtr odometryData);
		void onLaserScanData(sensor_msgs::LaserScanPtr laserScanData);
		void onBumperSensorData(sensor_msgs::PointCloud2Ptr bumperSensorData);
		void onBumperEventData(kobuki_msgs::BumperEventPtr bumperEventData);
		void onImuData(sensor_msgs::ImuPtr imuData);
		void onCameraPclData(sensor_msgs::PointCloud2Ptr pclData);
		void onCommandVelData(geometry_msgs::TwistPtr commandVelData);
		void onJointStateData(sensor_msgs::JointStatePtr jointStateData);
		void onCliffEventsData(kobuki_msgs::CliffEventPtr clifEventData);
		void onCameraImageRawData(sensor_msgs::ImagePtr cameraImageRawData);
		void onRobotOnOff(rqt_robot_control::RobotCommandPtr robotOnOffData);

	protected:

	};

} /* namespace ttb */

#endif /* TTBWORLDMODEL_H_ */