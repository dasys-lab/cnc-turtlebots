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
			ownPositionMotion(ringBufferLength), ownVelocityMotion(ringBufferLength), ownLaserScans(ringBufferLength)
	{
		this->wm = wm;
		ownID = supplementary::SystemConfig::getOwnRobotID();
	}

	RawSensorData::~RawSensorData()
	{
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

} /* namespace ttb */

