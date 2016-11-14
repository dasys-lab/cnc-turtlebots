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

		randomDriveController_pub = n.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity",1000);
		sub = n.subscribe("drive", 1000, &RandomDrive::chatterCallback, (RandomDrive*)this);
		this->t1=new std::thread(&RandomDrive::run,(RandomDrive*)this);

		msgBool = false;
	}
	void RandomDrive::chatterCallback(const std_msgs::Bool::ConstPtr& msg)
	{
	   msgBool = msg->data;
	}
	void RandomDrive::run(){
	while(ros::ok())
			{
				geometry_msgs::Twist msg;
				msg.linear.x = 0.5;
				msg.angular.z = 0;
				int count = 0;

				if (msgBool || count > 0){

					msg.linear.x = 0;
					msg.angular.z = 0.5;
					count ++;
					if (count >= 50)
					{
						count = 0;
					}

				}

				randomDriveController_pub.publish(msg);


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
