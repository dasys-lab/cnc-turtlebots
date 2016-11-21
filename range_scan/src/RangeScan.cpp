/*
 * RangeScan.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: lab-user
 */

#include "range_scan/RangeScan.h"

#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include "math.h"

#include <sstream>
#include <thread>

namespace range_scan
{

	RangeScan::RangeScan() :
			running(true),
			passfree(true),
			dist(0.5),
			roboradius(0.18)
	{
		this->direction_pub = n.advertise<std_msgs::Bool>("drive", 1000);
		this->laser_sub = this->n.subscribe("donatello/scan_hokuyo", 1000, &RangeScan::laserCallback, (RangeScan*)this);

		this->t1=new std::thread(&RangeScan::run,(RangeScan*)this);
	}

	RangeScan::~RangeScan()
	{
		delete this->t1;
	}

	void RangeScan::laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
	{

	double actualdist;
	for(int i = 0; i <= 720; i++){

		actualdist = roboradius/cos(i/4);		

		if(cos(i/4) == 0){
			if(msg->ranges[180 + i] < dist){
				passfree = false;
			}else{
				passfree=true;
			}		
		}else{
			if(actualdist<dist){
				passfree=false;
			}else{
				passfree=true;
			}
		}
		
	}
//std::cout<<"Range at 135 degrees: " <<msg->ranges[540]<<std::endl; 
//
//		if (msg->ranges[540]<0.5){
//std::cout<<"Range at 135 degrees for <0.5: " <<msg->ranges[540]<<std::endl; 
//
//			passfree=false;
//		}else{
//std::cout<<"Range at 135 degrees for >0.5: " <<msg->ranges[540]<<std::endl; 
//
//			passfree=true;
//		}
	}

	void RangeScan::run()
	{
		while (this->running)
		{
			std_msgs::Bool msg;

			msg.data = passfree;

			this->direction_pub.publish(msg);
			sleep(0.5);
		}
	}

}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "rangeScan");

	range_scan::RangeScan rangeScan;

	ros::Rate loop_rate(10);

	while (ros::ok())
	{
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
} /* namespace range_scan */
