/*
 * RandomDrive.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: lab-user
 */

#include "random_drive/RandomDrive.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include "geometry_msgs/Twist.h"

namespace random_drive
{

	RandomDrive::RandomDrive()
	{

		randomDriveController_pub = n.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/teleop", 1000);
		sub = n.subscribe("drive", 1000, &RandomDrive::chatterCallback, (RandomDrive*)this);
		this->t1 = new std::thread(&RandomDrive::run, (RandomDrive*)this);

		wayIsFree = false;
	}

	void RandomDrive::chatterCallback(const std_msgs::Bool::ConstPtr& msg)
	{
		wayIsFree = msg->data;
	}

	void RandomDrive::run()
	{

		int count = 0;


		while (ros::ok())
		{
			geometry_msgs::Twist msg;
			msg.linear.x = 0.5;
			msg.angular.z = 0;

			if (!wayIsFree || count > 0)
			{

				msg.linear.x = 0;
				msg.angular.z = 0.5;
				count++;
				if (count >= 50)
				{
					count = 0;
				}
				//std::cout<<count;
			}
//			std::cout<<"sending msg"<<msg.linear.x<<msg.angular.z;
			randomDriveController_pub.publish(msg);
			sleep(0.01);

		}
	}
	RandomDrive::~RandomDrive()
	{
		// TODO Auto-generated destructor stub
	}

} /* namespace random_drive */

int main(int argc, char **argv)
{
	ros::init(argc, argv, "randomDriveController");

	random_drive::RandomDrive randomDrive;
	ros::Rate loop_rate(10);

	while (ros::ok())
	{
		ros::spinOnce();
		loop_rate.sleep();
	}

}
