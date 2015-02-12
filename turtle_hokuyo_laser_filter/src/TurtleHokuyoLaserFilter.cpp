/*
 * TurtleHokuyoLaserFilter.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: Jonas Scherbaum
 */

#include "../include/TurtleHokuyoLaserFilter.h"
#include <thread>
#include <chrono>

namespace turtle
{

  TurtleHokuyoLaserFilter::TurtleHokuyoLaserFilter()
  {

    this->laserScanSubscriber = this->nodeHandle.subscribe("/scan_hokuyo", 1, &TurtleHokuyoLaserFilter::laserScanCallback, this);
    this->laserScanFilteredPublisher = this->nodeHandle.advertise<sensor_msgs::LaserScan>("/scan_filtered", 10);
  }

  TurtleHokuyoLaserFilter::~TurtleHokuyoLaserFilter()
  {
    this->laserScanSubscriber.shutdown();
  }

  void TurtleHokuyoLaserFilter::laserScanCallback(sensor_msgs::LaserScanPtr msg)
  {
    // do not call in production mode
//    printLaserScan(msg);

    // start Interpolation here ...
    sensor_msgs::LaserScan::_ranges_type& ranges = msg->ranges;

//
//    sensor_msgs::LaserScan filteredLaserScan = new sensor_msgs::LaserScan();
//    filteredLaserScan.header = msg->header;
//    filteredLaserScan.angle_increment = msg->angle_increment;
//    filteredLaserScan.angle_max = msg->angle_max;
//    filteredLaserScan.angle_min = msg->angle_min;
//    filteredLaserScan.intensities = msg->intensities;
//    filteredLaserScan.range_max = msg->range_max;
//    filteredLaserScan.range_min = msg->range_min;
//    filteredLaserScan.ranges = newRanges;
//    filteredLaserScan.scan_time = msg->scan_time;
//    filteredLaserScan.time_increment = msg->time_increment;
//
//    sensor_msgs::LaserScan::_ranges_type newRanges = new sensor_msgs::LaserScan::_ranges_type(ranges.size());

    // Change angles to match large front view
    
    const double old_angle_min = msg->angle_min;
    const double old_angle_max = msg->angle_max;
    const double angle_increment = msg->angle_increment;

    // Angles of the large segment between the two front braces
    const double ls_angle_min = old_angle_min + 0.658861792628;
    //const double ls_angle_max = old_angle_max + 0.706858347058;

    // Calculate the position of laser data in the large segment
    const double min_start = ls_angle_min / angle_increment; 
    //const double max_start = (ls_angle_min - ls_angle_max)*-1 / angle_increment;
   
    const int min_start_index = (static_cast<int>(min_start)*-1) - 1;
    //const int max_start_index = min_start_index + static_cast<int>(max_start) + 1;
    const int max_start_index = min_start_index + 314;

    const int new_ranges_size = max_start_index - min_start_index;
    ROS_INFO("%d, %d", min_start_index, max_start_index); 
    sensor_msgs::LaserScan::_ranges_type* newRanges = new sensor_msgs::LaserScan::_ranges_type(new_ranges_size);
    int i = 0; 
    for(int j = min_start_index; j < max_start_index; j++) {
        newRanges->at(i) = ranges.at(j); 
        i++;
    }

    // Modify message to match front area
    msg->angle_min = -0.658861792628;
    msg->angle_max =  0.706858347058;
    
    // Inverse range array as sensor is upside down 
    std::reverse(newRanges->begin(), newRanges->end());
    msg->ranges = *newRanges;
    // republish the filtered LaserScan
//    sensor_msgs::LaserScanConstPtr sendMsg = msg;
    this->laserScanFilteredPublisher.publish(msg);
  }

  void TurtleHokuyoLaserFilter::printLaserScan(sensor_msgs::LaserScanPtr msg)
  {
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
    for (std::vector<float>::iterator it = intensities.begin(); it != intensities.end(); it++) {
      out << "it: " << *it;
    }
    out << std::endl;

    unsigned int count = 0;
    out << "Ranges: " << std::endl;
    for (std::vector<float>::iterator it = ranges.begin(); it != ranges.end(); it++) {
      out << "range[" << count << "]: "<< *it;
      count++;
    }
    out << std::endl;

    ROS_INFO("%s\n", out.str().c_str());
  }

} /* namespace turtle */

/**
 * The main EntryPoint of the turtle_base Node
 */
int main(int argc, char** argv)
{
    // start the Node with the name AlicaEngine
    ROS_DEBUG("Initializing Ros");
    ros::init(argc, argv, "TurtleHokuyoLaserFilter");

    ROS_DEBUG("Starting Base");

    // Read the argv Arguments for the Settings

    // node intialization comes here
    turtle::TurtleHokuyoLaserFilter* node = new turtle::TurtleHokuyoLaserFilter();

    ros::Rate publishRate(10);
    // While ROS is active, do the Node Stuff
    while (ros::ok())
    {
            // At the moment we are only waiting
            ros::spinOnce();
            publishRate.sleep();
    }

    return 0;
}
