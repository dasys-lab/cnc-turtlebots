/*
 * RangeScan.h
 *
 *  Created on: Nov 7, 2016
 *      Author: lab-user
 */

#ifndef SRC_RANGESCAN_H_
#define SRC_RANGESCAN_H_

#include "sensor_msgs/LaserScan.h"
#include "ros/ros.h"
#include <thread>

namespace range_scan
{

	class RangeScan
	{
	public:
		RangeScan();
		virtual ~RangeScan();
		void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
		std::string getEnv(const std::string & var);

		void run();

	private:
		bool passfree;
		bool running;
		double dist;
		double roboradius;
		ros::Publisher direction_pub;
		ros::Subscriber laser_sub;
		ros::NodeHandle n;
		std::thread* t1;
	};

} /* namespace range_scan */

#endif /* SRC_RANGESCAN_H_ */
