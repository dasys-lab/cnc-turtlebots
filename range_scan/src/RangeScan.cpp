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
		std::string robot = this->getEnv("ROBOT");
		this->laser_sub = this->n.subscribe(robot+"/scan_hokuyo", 1000, &RangeScan::laserCallback, (RangeScan*)this);

		this->t1=new std::thread(&RangeScan::run,(RangeScan*)this);
	}

	RangeScan::~RangeScan()
	{
		delete this->t1;
	}

	void RangeScan::laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
	{

	double minDist;
	for(int i = 0; i <= 720; i++){
		double angle = (i/4)*180/M_PI;
		if (i < 320)
		{ // left edge
			minDist = roboradius/cos(angle);
		}
		else if (i < 400)
		{ // front edge
			minDist = 1/cos(M_PI/2-angle);
		}
		else
		{ // right edge
			minDist = roboradius/cos(M_PI-angle);
		}

		if(msg->ranges[180+i] < minDist){
			std::cout << "RS: Is NOT free!" << std::endl;
			passfree=false;
		}else{
			std::cout << "RS: Is FREE!" << std::endl;
			passfree=true;
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

	std::string RangeScan::getEnv(const std::string & var)
	{
		const char * val = ::getenv(var.c_str());
		if (val == 0)
		{
			std::cerr << "RS: Environment Variable " << var << " is null" << std::endl;
			return "";
		}
		else
		{
			std::cout << "RS: Environment Variable " << var << " is " << val << std::endl;
			return val;
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
