/*
 * TTBWorldModel.cpp
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */

#include "TTBWorldModel.h"
#include "sharedworldmodel/TTBSharedWorldModel.h"
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
		kickerVoltage = 0;
		ownID = supplementary::SystemConfig::getOwnRobotID();
		spinner = new ros::AsyncSpinner(4);
		spinner->start();
		//rawOdomSub = n.subscribe("/RawOdometry", 10, &TTBWorldModel::onRawOdometryInfo, (TTBWorldModel*)this);

		this->sharedWolrdModel = new TTBSharedWorldModel(this);
	}

	void TTBWorldModel::getWorldModelData()
	{
//		lock_guard<mutex> lock(wmMutex);
//		if (wmData.size() == 0)
//		{
//			return nullptr;
//		}
//		return wmData.front();
	}

	TTBWorldModel::~TTBWorldModel()
	{
		spinner->stop();
		delete spinner;
		delete this->sharedWolrdModel;
	}

	TTBSharedWorldModel* TTBWorldModel::getSharedWolrdModel()
	{
		return this->sharedWolrdModel;
	}

	unsigned long TTBWorldModel::getTime()
	{
		return (unsigned long)ros::Time::now().sec * (unsigned long)1000000000 + (unsigned long)ros::Time::now().nsec;
	}

	void TTBWorldModel::sendSharedWorldModelData()
	{
//		msl_sensor_msgs::SharedWorldInfo msg;
//		msg.senderID = 9;
//		auto ball = rawSensorData.getBallPositionAndCertaincy();
//		auto pos = rawSensorData.getOwnPositionVision();
//		if(pos == nullptr)
//		{
//			return;
//		}
//		if (ball != nullptr)
//		{
//			shared_ptr<CNPoint2D> point = make_shared<CNPoint2D>(ball->first->x, ball->first->y);
//			auto p = point->egoToAllo(*pos);
//			msg.ball.point.x = p->x;
//			msg.ball.point.y = p->y;
//			msg.ball.confidence = ball->second;
// 		}
//
//		auto ballVel = rawSensorData.getBallVelocity();
//		if (ballVel != nullptr)
//		{
//
//			msg.ball.velocity.vx = ballVel->x;
//			msg.ball.velocity.vy = ballVel->y;
//		}
//
//		auto ownPos = rawSensorData.getOwnPositionVisionAndCertaincy();
//		if (ownPos != nullptr)
//		{
//			msg.odom.position.x = ownPos->first->x;
//			msg.odom.position.y = ownPos->first->y;
//			msg.odom.position.angle = ownPos->first->theta;
//			msg.odom.certainty = ownPos->second;
//		}
//
//		auto ownVel = rawSensorData.getOwnVelocityVision();
//		if (ownVel != nullptr)
//		{
//			msg.odom.motion.angle = ownVel->angle;
//			msg.odom.motion.rotation = ownVel->rotation;
//			msg.odom.motion.translation = ownVel->translation;
//		}
//
//		auto obstacles = robots.getObstacles();
//		{
//			if(obstacles != nullptr)
//			{
//				msg.obstacles.reserve(obstacles->size());
//				for(auto& x : *obstacles)
//				{
//					shared_ptr<CNPoint2D> point = make_shared<CNPoint2D>(x.x, x.y);
//					auto p = point->egoToAllo(*pos);
//					msl_msgs::Point2dInfo info;
//					info.x = p->x;
//					info.y = p->y;
//					msg.obstacles.push_back(info);
//				}
//			}
//		}
//		if(ownPos != nullptr)
//		{
//			sharedWorldPub.publish(msg);
//		}
	}

	int TTBWorldModel::getRingBufferLength()
	{
		return ringBufferLength;
	}

} /* namespace ttb */

