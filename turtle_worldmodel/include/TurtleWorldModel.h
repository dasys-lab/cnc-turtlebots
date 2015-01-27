/*
 * TurtleWorldModel.h
 *
 *  Created on: 27.10.2014
 *      Author: endy
 *
 *  Extended on: 04.11.2014
 *      Author: Jonas Scherbaum
 */

#ifndef MSLWORLDMODEL_H_
#define MSLWORLDMODEL_H_

#include <ros/ros.h>
//#include <msl_simulator/messages_robocup_ssl_wrapper.h>
#include <list>
#include <iostream>
#include <tuple>

#include "SystemConfig.h"

#include "nav_msgs/Odometry.h"
#include "sensor_msgs/Imu.h"
#include "../include/SubscriptionManager.h"

using namespace std;

namespace turtle
{

	class TurtleWorldModel
	{
	public:
		static TurtleWorldModel* get();

		TurtleWorldModel();
		virtual ~TurtleWorldModel();

		void setOwnPose(geometry_msgs::PoseWithCovariance* ownPose)
		{
		  this->ownPose = ownPose;
		  cout << "ownPose setted." << std::endl;
		}

		void setOwnTwist(geometry_msgs::TwistWithCovariance* ownTwist)
		{
		  this->ownTwist = ownTwist;
		  cout << "ownTwist setted" << std::endl;
		}

		void setOwnImu(sensor_msgs::Imu* ownImu)
		{
		  this->ownImu = ownImu;
		  cout << "ownImu setted" << std::endl;
		}

	private:
		int ownID;
		ros::AsyncSpinner* spinner;
		ros::Subscriber odometrySubscriber;
		geometry_msgs::PoseWithCovariance* ownPose = NULL;
		geometry_msgs::TwistWithCovariance* ownTwist = NULL;
		sensor_msgs::Imu* ownImu = NULL;
	};

} /* namespace turtle */

#endif /* TURTLEWORLDMODEL_H_ */
