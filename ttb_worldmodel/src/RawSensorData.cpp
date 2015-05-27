/*
 * RawSensorData.cpp
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */

#include <SystemConfig.h>
#include "RawSensorData.h"
#include "TTBWorldModel.h"

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

	void RawSensorData::processWorldModelData()
	{
//		unsigned long time = wm->getTime();
//
//		if (data->odometry.certainty > 0)
//		{
//			//Vision
//			shared_ptr<CNPosition> pos = make_shared<CNPosition>(data->odometry.position.x, data->odometry.position.y,
//																	data->odometry.position.angle);
//			shared_ptr<InformationElement<CNPosition>> odometry = make_shared<InformationElement<CNPosition>>(pos,
//																												time);
//			odometry->certainty = data->odometry.certainty;
//			ownPositionVision.add(odometry);
//
//			shared_ptr<msl_msgs::MotionInfo> vel = make_shared<msl_msgs::MotionInfo>(data->odometry.motion);
//			shared_ptr<InformationElement<msl_msgs::MotionInfo>> v = make_shared<
//					InformationElement<msl_msgs::MotionInfo>>(vel, time);
//			v->certainty = data->odometry.certainty;
//			ownVelocityVision.add(v);
//
//			//Motion
//			shared_ptr<CNPosition> posMotion = make_shared<CNPosition>(data->odometry.position.x,
//																		data->odometry.position.y,
//																		data->odometry.position.angle);
//			shared_ptr<InformationElement<CNPosition>> odometryMotion = make_shared<InformationElement<CNPosition>>(
//					posMotion, time);
//			odometryMotion->certainty = data->odometry.certainty;
//			ownPositionMotion.add(odometryMotion);
//
//			shared_ptr<msl_msgs::MotionInfo> velMotion = make_shared<msl_msgs::MotionInfo>(data->odometry.motion);
//			shared_ptr<InformationElement<msl_msgs::MotionInfo>> vMotion = make_shared<
//					InformationElement<msl_msgs::MotionInfo>>(velMotion, time);
//			vMotion->certainty = data->odometry.certainty;
//			ownVelocityMotion.add(vMotion);
//		}
//
//		if (data->ball.confidence > 0)
//		{
//			shared_ptr<CNPoint2D> ballPos = make_shared<CNPoint2D>(data->ball.point.x, data->ball.point.y);
//			shared_ptr<InformationElement<CNPoint2D>> ball = make_shared<InformationElement<CNPoint2D>>(ballPos, time);
//			ball->certainty = data->ball.confidence;
//			ballPosition.add(ball);
//
//			shared_ptr<CNVelocity2D> ballVel = make_shared<CNVelocity2D>(data->ball.velocity.vx,
//																			data->ball.velocity.vy);
//			shared_ptr<InformationElement<CNVelocity2D>> ballV = make_shared<InformationElement<CNVelocity2D>>(ballVel,
//																												time);
//			ballV->certainty = data->ball.confidence;
//			ballVelocity.add(ballV);
//		}
//
//		shared_ptr<vector<double>> dist = make_shared<vector<double>>(data->distanceScan.sectors);
//		shared_ptr<InformationElement<vector<double>>> distance = make_shared<InformationElement<vector<double>>>(dist,
//				time);
//		distance->certainty = data->ball.confidence;
//		distanceScan.add(distance);
//
//		this->wm->ball.updateOnWorldModelData();
	}

} /* namespace ttb */

