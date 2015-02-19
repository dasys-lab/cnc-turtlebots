/*
 * TurtleHokuyoLaserFilter.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: Jonas Scherbaum
 */

#include "../include/TurtleHokuyoLaserFilter.h"
#include <thread>
#include <chrono>
#include <cmath>

using std::abs;

namespace turtle {

TurtleHokuyoLaserFilter::TurtleHokuyoLaserFilter() {

	laserScanSubscriber = nodeHandle.subscribe("/scan_hokuyo", 1, &TurtleHokuyoLaserFilter::laserScanCallback, this);
	laserScanFilteredPublisher = nodeHandle.advertise<sensor_msgs::LaserScan>("/scan_filtered", 10);

	// Default values for parameters
	newAngleMin = -0.658861792628;
	newAngleMax = 0.706858347058;
	reverseArray = true;

	// Read parameters if available
	this->nodeHandle.getParam("reverse_array", this->reverseArray);
	this->nodeHandle.getParam("angle_min", this->newAngleMin);
	this->nodeHandle.getParam("angle_max", this->newAngleMax);

	rangesStartIndex = 0;
	rangesEndIndex = 0;
	newRangesSize = 0;
}

TurtleHokuyoLaserFilter::~TurtleHokuyoLaserFilter() {
	this->laserScanSubscriber.shutdown();
}

void TurtleHokuyoLaserFilter::laserScanCallback(sensor_msgs::LaserScanPtr msg) {

	// Only calculate once at start
	if (!calculated) {
		// Calculate the number of sensor reading in the new range array
		newRangesSize = static_cast<int>((abs(newAngleMax) + abs(newAngleMin)) / msg->angle_increment) + 1;

		// Determine the start and end index
		rangesStartIndex = static_cast<int>((abs((msg->angle_min + abs(newAngleMin)) / msg->angle_increment)));
		rangesEndIndex = rangesStartIndex + newRangesSize;
		calculated = true;
	}

	// Cut out the range data of our original laser scan and put it in our new one
	sensor_msgs::LaserScan::_ranges_type* newRanges = new sensor_msgs::LaserScan::_ranges_type(newRangesSize);
	int i = 0;
	for (int j = rangesStartIndex; j < rangesEndIndex; j++) {
		newRanges->at(i) = msg->ranges.at(j);
		i++;
	}

	// Inverse range array as sensor is upside down
	if(reverseArray) {
		std::reverse(newRanges->begin(), newRanges->end());
	}

	// Modify message to match our cut out segment
	msg->angle_min = newAngleMin;
	msg->angle_max = newAngleMax;
	msg->ranges = *newRanges;

	laserScanFilteredPublisher.publish(msg);
}

void TurtleHokuyoLaserFilter::printLaserScan(sensor_msgs::LaserScanPtr msg) {
	float angle_inc = msg->angle_increment;
	float angle_max = msg->angle_max;
	float angle_min = msg->angle_min;
	sensor_msgs::LaserScan::_intensities_type intensities = msg->intensities;
	float range_max = msg->range_max;
	float range_min = msg->range_min;
	sensor_msgs::LaserScan::_ranges_type ranges = msg->ranges;
	float scan_time = msg->scan_time;
	float time_inc = msg->time_increment;

	// constructing human readable format
	std::ostringstream out;
	out << "Laser-Scan Message:" << std::endl;
	out << "Angle-Increment: " << angle_inc << std::endl;
	out << "Angle Maximum: " << angle_max << std::endl;
	out << "Angle Minimum: " << angle_min << std::endl;
	out << "Range Maximum: " << range_max << std::endl;
	out << "Range Minimum: " << range_min << std::endl;
	out << "Scan Time: " << scan_time << std::endl;
	out << "Time-Increment: " << time_inc << std::endl;

	out << "Intensities: " << std::endl;
	for (std::vector<float>::iterator it = intensities.begin();
			it != intensities.end(); it++) {
		out << "it: " << *it;
	}
	out << std::endl;

	unsigned int count = 0;
	out << "Ranges: " << std::endl;
	for (std::vector<float>::iterator it = ranges.begin(); it != ranges.end();
			it++) {
		out << "range[" << count << "]: " << *it;
		count++;
	}
	out << std::endl;

	ROS_INFO("%s\n", out.str().c_str());
}

} /* namespace turtle */

/**
 * The main EntryPoint of the turtle_base Node
 */
int main(int argc, char** argv) {
	ros::init(argc, argv, "TurtleHokuyoLaserFilter");

	// node intialization comes here
	turtle::TurtleHokuyoLaserFilter* node = new turtle::TurtleHokuyoLaserFilter();

	ros::Rate publishRate(10);
	// While ROS is active, do the Node Stuff
	while (ros::ok()) {
		// At the moment we are only waiting
		ros::spinOnce();
		publishRate.sleep();
	}

	return 0;
}
