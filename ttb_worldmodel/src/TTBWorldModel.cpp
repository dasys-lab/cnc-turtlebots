/*
 * TTBWorldModel.cpp
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */

#include "TTBWorldModel.h"

#include <nav_msgs/Odometry.h>

#include "RawSensorData.h"

namespace ttb
{

	TTBWorldModel* TTBWorldModel::get()
	{
		static TTBWorldModel instance;
		return &instance;
	}

	TTBWorldModel::TTBWorldModel() :
			ringBufferLength(10), rawSensorData(this, 10), robots(this, 10)
	{
		ownID = supplementary::SystemConfig::getOwnRobotID();

		// READ PARAMS
		sc = supplementary::SystemConfig::getInstance();
		odometryTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.OdometryTopic", NULL);

		// SET ROS STUFF
		odometrySub = n.subscribe(odometryTopic, 10, &TTBWorldModel::onOdometryData,(TTBWorldModel*)this);

		spinner = new ros::AsyncSpinner(4);
		spinner->start();
	}

	TTBWorldModel::~TTBWorldModel()
	{
		spinner->stop();
		delete spinner;
	}

	void TTBWorldModel::onOdometryData(nav_msgs::OdometryConstPtr odometryData)
	{
		cout << "WM: Received Odometry Message!" << endl;
		lock_guard<mutex> lock(wmMutex);
		rawSensorData.processOdometryData(odometryData);

	}

	int TTBWorldModel::getRingBufferLength()
	{
		return ringBufferLength;
	}

} /* namespace ttb */

