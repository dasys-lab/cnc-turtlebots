/*
 * TTBWorldModel.cpp
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */

#include "TTBWorldModel.h"

#include <nav_msgs/Odometry.h>
#include "engine/AlicaEngine.h"
#include "engine/IAlicaClock.h"

#include "RawSensorData.h"

namespace ttb
{

	TTBWorldModel* TTBWorldModel::get()
	{
		static TTBWorldModel instance;
		return &instance;
	}

	TTBWorldModel::TTBWorldModel() :
			ringBufferLength(10), rawSensorData(this, 10), robots(this, 10), alicaEngine(nullptr)
	{
		ownID = supplementary::SystemConfig::getOwnRobotID();

		// READ PARAMS
		sc = supplementary::SystemConfig::getInstance();
		odometryTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.OdometryTopic", NULL);
		laserScanTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.LaserScanerTopic", NULL);
		bumperEventTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.BumperEventsTopic", NULL);
		bumperSensorTopic= (*sc)["TTBWorldModel"]->get<string>("Sensors.BumperSensorsTopic", NULL);
		imuDataTopic= (*sc)["TTBWorldModel"]->get<string>("Sensors.ImuDataTopic", NULL);
		cameraPclTopic= (*sc)["TTBWorldModel"]->get<string>("Sensors.CameraPclTopic", NULL);
		commandVelTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.CommandVelocity", NULL);
		jointStateTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.JointState", NULL);
		cliffEventsTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.CliffEvents", NULL);
		cameraImageRawTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.CameraImageRaw", NULL);
		robotOnOffTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.RobotOnOff", NULL);

		// SET ROS STUFF
		odometrySub = n.subscribe(odometryTopic, 10, &TTBWorldModel::onOdometryData,(TTBWorldModel*)this);
		laserScanSub =n.subscribe(laserScanTopic, 10, &TTBWorldModel::onLaserScanData, (TTBWorldModel*)this);
		bumperEventSub = n.subscribe(bumperEventTopic, 10, &TTBWorldModel::onBumperEventData, (TTBWorldModel*)this);
		bumperSensorSub = n.subscribe(bumperSensorTopic, 10, &TTBWorldModel::onBumperSensorData, (TTBWorldModel*)this);
		imuDataSub = n.subscribe(imuDataTopic, 10, &TTBWorldModel::onImuData, (TTBWorldModel*)this);
		cameraPclSub = n.subscribe(cameraPclTopic, 10, &TTBWorldModel::onCameraPclData, (TTBWorldModel*)this);
		commandVelocitySub = n.subscribe(commandVelTopic, 10, &TTBWorldModel::onCommandVelData, (TTBWorldModel*)this);
		jointStateSub = n.subscribe(jointStateTopic, 10, &TTBWorldModel::onJointStateData, (TTBWorldModel*)this);
		cliffEventsSub = n.subscribe(cliffEventsTopic, 10, &TTBWorldModel::onCliffEventsData, (TTBWorldModel*)this);
		cameraImageRawSub = n.subscribe(cameraImageRawTopic, 10, &TTBWorldModel::onCameraImageRawData, (TTBWorldModel*)this);
		robotOnOffSub = n.subscribe(robotOnOffTopic, 10, &TTBWorldModel::onRobotOnOff, (TTBWorldModel*)this);

		spinner = new ros::AsyncSpinner(4);
		spinner->start();
	}

	TTBWorldModel::~TTBWorldModel()
	{
		spinner->stop();
		delete spinner;
	}

	bool TTBWorldModel::setEngine(alica::AlicaEngine* ae)
	{
		if (this->alicaEngine != nullptr)
		{
			this->alicaEngine = ae;
			return true;
		}
		else
		{
			return false;
		}
	}

	InfoTime TTBWorldModel::getTime()
	{
		if (this->alicaEngine != nullptr)
		{
			return this->alicaEngine->getIAlicaClock()->now();
		}
		else
		{
			return 0;
		}
	}
	void TTBWorldModel::onCommandVelData(geometry_msgs::TwistPtr commandVelData) {
//		cout << "WM: Received command velocity Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processCommandVel(commandVelData);
	}
	void TTBWorldModel::onJointStateData(sensor_msgs::JointStatePtr jointStateData) {
//		cout << "WM: Received joint state Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processJointState(jointStateData);
	}
	void TTBWorldModel::onCliffEventsData(kobuki_msgs::CliffEventPtr clifEventData) {
//		cout << "WM: Received cliff event Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processCliffEvent(clifEventData);
	}
	void TTBWorldModel::onImuData(sensor_msgs::ImuPtr imuData) {
//		cout << "WM: Received IMU Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processImuData(imuData);
	}
	void TTBWorldModel::onCameraPclData(sensor_msgs::PointCloud2Ptr pclData) {
//		cout << "WM: Received camera PCL Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processCameraPcl(pclData);
	}
	void TTBWorldModel::onOdometryData(nav_msgs::OdometryConstPtr odometryData)
	{
//		cout << "WM: Received Odometry Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processOdometryData(odometryData);

	}
	void TTBWorldModel::onLaserScanData(sensor_msgs::LaserScanPtr laserScanData) {
//		cout << "WM: Received LaserScan Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processLaserScan(laserScanData);
	}
	void TTBWorldModel::onBumperSensorData(sensor_msgs::PointCloud2Ptr bumperSensorData) {
//		cout << "WM: Received BumperSensors Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processBumperSensors(bumperSensorData);
	}
	void TTBWorldModel::onBumperEventData(kobuki_msgs::BumperEventPtr bumperEventData) {
//		cout << "WM: Received BumperEvents Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processBumperEvents(bumperEventData);
	}

	void TTBWorldModel::onCameraImageRawData(sensor_msgs::ImagePtr cameraImageRawData) {
//		cout << "WM: Received CameraImageRaw Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processCameraImageRaw(cameraImageRawData);
	}

	void TTBWorldModel::onRobotOnOff(rqt_robot_control::RobotCommandPtr robotOnOffData)
	{
//		cout << "WM: Received RobotOnOff Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processRobotOnOff(robotOnOffData);
	}


	int TTBWorldModel::getRingBufferLength()
	{
		return ringBufferLength;
	}

} /* namespace ttb */


