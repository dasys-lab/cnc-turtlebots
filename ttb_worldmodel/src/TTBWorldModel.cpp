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

		// SET ROS STUFF
		odometrySub = n.subscribe(odometryTopic, 10, &TTBWorldModel::onOdometryData,(TTBWorldModel*)this);
		laserScanSub =n.subscribe(laserScanTopic, 10, &TTBWorldModel::onLaserScanData, (TTBWorldModel*)this);
		bumperEventSub = n.subscribe(bumperEventTopic, 10, &TTBWorldModel::onBumperEventData, (TTBWorldModel*)this);
		bumperSensorSub = n.subscribe(bumperSensorTopic, 10, &TTBWorldModel::onBumperSensorData, (TTBWorldModel*)this);

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

	void TTBWorldModel::onOdometryData(nav_msgs::OdometryConstPtr odometryData)
	{
		cout << "WM: Received Odometry Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processOdometryData(odometryData);

	}
	void TTBWorldModel::onLaserScanData(sensor_msgs::LaserScanPtr laserScanData) {
		cout << "WM: Received LaserScan Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processLaserScan(laserScanData);
	}
	void TTBWorldModel::onBumperSensorData(sensor_msgs::PointCloud2Ptr bumperSensorData) {
		cout << "WM: Received BumperSensors Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processBumperSensors(bumperSensorData);
	}
	void TTBWorldModel::onBumperEventData(kobuki_msgs::BumperEventPtr bumperEventData) {
		cout << "WM: Received BumperEvents Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processBumperEvents(bumperEventData);
	}

	int TTBWorldModel::getRingBufferLength()
	{
		return ringBufferLength;
	}

} /* namespace ttb */


