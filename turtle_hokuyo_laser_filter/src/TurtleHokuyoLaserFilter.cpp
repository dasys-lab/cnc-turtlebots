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

    // brace 1
    float brace1_start = ranges.at(100);
    float brace1_step_size = ranges.at(140) - brace1_start;
    brace1_step_size /= 40;

    // brace 2
    float brace2_start = ranges.at(175);
    float brace2_step_size = ranges.at(210) - brace2_start;
    brace2_step_size /= 35;

    // brace 3
    float brace3_start = ranges.at(520);
    float brace3_step_size = ranges.at(555) - brace3_start;
    brace3_step_size /= 35;

     // brace 4
    float brace4_start = ranges.at(585);
    float brace4_step_size = ranges.at(630) - brace4_start;
    brace4_step_size /= 35;

    // now iterate over all range entries
    for (unsigned int i = 0; i<ranges.size(); i++) {

      if (i >= 630) {
        continue;
      }

//      if (i > 585) {
//
//        // replace with brace 4
//        double curStep = 35-(625-i);
//        double newVal = brace4_start;
//        newVal += curStep*brace4_step_size;
//        ranges.at(i) = NAN;
//        continue;
//      }
//
//      if (i >= 555) {
//        continue;
//      }

      if (i > 520) {

        // replace with brace 3
        double curStep = 35-(555-i);
        double newVal = brace3_start;
        newVal += curStep*brace3_step_size;
        ranges.at(i) = NAN;
        continue;
      }

      if (i >= 210) {
        continue;
      }

      if (i > 175) {

        // replace with brace 2
        double curStep = 35-(210-i);
        double newVal = brace2_start;
        newVal += curStep*brace2_step_size;
        ranges.at(i) = NAN;
        continue;
      }

      if (i >= 140) {
        continue;
      }

      if (i > 100) {

        // replace with brace 1
        double curStep = 40-(140-i);
        double newVal = brace1_start;
        newVal += curStep*brace1_step_size;
        ranges.at(i) = NAN;
        continue;
      }
    }

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
