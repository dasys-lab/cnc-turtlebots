/*
 * RandomDrive.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: lab-user
 */

#include "random_drive/RandomDrive.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

namespace random_drive
{

	RandomDrive::RandomDrive()
	{

		// TODO Auto-generated constructor stub

	}

	RandomDrive::~RandomDrive()
	{
		// TODO Auto-generated destructor stub
	}



} /* namespace random_drive */

int main(int argc, char **argv)
	{
		ros::init(argc, argv, "randomDriveController");
		ros::NodeHandle n;
		ros::Publisher randomDriveController_pub = n.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity",1000);
		ros::Rate loop_rate(10);

		while(ros::ok())
		{
			geometry_msgs::Twist msg;
//			msg.data= "[0.5, 0.0, 0.0] [0.0, 0.0, 0.0]";
			msg.linear.x = 1.0;
			randomDriveController_pub.publish(msg);
//			msg.data= "[0.0, 0.0, 0.0] [0.0, 0.0, 1.0]";
			msg.angular.z = 0;
			randomDriveController_pub.publish(msg);

		}


	}
