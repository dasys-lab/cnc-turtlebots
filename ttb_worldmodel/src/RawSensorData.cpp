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

	RawSensorData::RawSensorData(TTBWorldModel* wm, int ringbufferLength)
	{
		this->wm = wm;
		ownID = supplementary::SystemConfig::getOwnRobotID();
		maxInformationAge = 1000000000;
	}

	RawSensorData::~RawSensorData()
	{
	}

	void RawSensorData::processOdometryData(nav_msgs::OdometryConstPtr odometryData)
	{
		//unsigned long time = wm->getTime();

		//Motion
		shared_ptr<geometry::CNPosition> position = make_shared<geometry::CNPosition>(odometryData->pose.pose.position.x, odometryData->pose.pose.position.y, odometryData->pose.pose.orientation.z / odometryData->pose.pose.orientation.w);


		// TODO go on with data integration

		/*shared_ptr < InformationElement < CNPosition >> odometryMotion = make_shared<InformationElement<CNPosition>>(posMotion, time);

		 odometryMotion->certainty = data->odometry.certainty;

		 ownPositionMotion.add(odometryMotion);

		 shared_ptr<msl_msgs::MotionInfo> velMotion = make_shared<msl_msgs::MotionInfo>(data->odometry.motion);
		 shared_ptr<InformationElement<msl_msgs::MotionInfo>> vMotion = make_shared<InformationElement<msl_msgs::MotionInfo>>(velMotion, time);
		 vMotion->certainty = data->odometry.certainty;
		 ownVelocityMotion.add(vMotion);*/

	}

} /* namespace ttb */

