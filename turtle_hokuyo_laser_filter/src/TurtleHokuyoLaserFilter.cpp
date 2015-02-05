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

  void TurtleHokuyoLaserFilter::laserScanCallback(const sensor_msgs::LaserScanConstPtr& msg)
  {
    // do not call in production mode
//    printLaserScan(msg);

    // start Interpolation here ...
    sensor_msgs::LaserScan::_ranges_type ranges = msg->ranges;

    // brace 1
    float brace1_start = ranges.at(102);
    float brace1_step_size = ranges.at(137) - brace1_start;
    brace1_step_size /= 35;

    // brace 2
    float brace2_start = ranges.at(180);
    float brace2_step_size = ranges.at(205) - brace2_start;
    brace2_step_size /= 25;

    // brace 3
    float brace3_start = ranges.at(525);
    float brace3_step_size = ranges.at(550) - brace3_start;
    brace3_step_size /= 25;

     // brace 4
    float brace4_start = ranges.at(590);
    float brace4_step_size = ranges.at(625) - brace4_start;
    brace4_step_size /= 35;

    // now iterate over all range entries
    for (unsigned int i = 0; i<ranges.size(); i++) {

      if (i >= 625) {
        continue;
      }

      if (i > 590) {

        // replace with brace 4
        double curStep = 35-(625-i);
        double newVal = brace4_start;
        newVal += curStep*brace4_step_size;
        ranges.at(i) = newVal;
        continue;
      }

      if (i >= 550) {
        continue;
      }

      if (i > 525) {

        // replace with brace 3
        double curStep = 25-(550-i);
        double newVal = brace3_start;
        newVal += curStep*brace3_step_size;
        ranges.at(i) = newVal;
        continue;
      }

      if (i >= 205) {
        continue;
      }

      if (i > 180) {

        // replace with brace 2
        double curStep = 25-(205-i);
        double newVal = brace2_start;
        newVal += curStep*brace2_step_size;
        ranges.at(i) = newVal;
        continue;
      }

      if (i >= 137) {
        continue;
      }

      if (i > 102) {

        // replace with brace 1
        double curStep = 35-(137-i);
        double newVal = brace1_start;
        newVal += curStep*brace1_step_size;
        ranges.at(i) = newVal;
        continue;
      }
    }

//    sensor_msgs::LaserScan filteredLaserScan;
//    filteredLaserScan.header = msg->header;
//    filteredLaserScan.angle_increment = msg->angle_increment;
//    filteredLaserScan.angle_max = msg->angle_max;
//    filteredLaserScan.angle_min = msg->angle_min;
//    filteredLaserScan.intensities = msg->intensities;
//    filteredLaserScan.range_max = msg->range_max;
//    filteredLaserScan.range_min = msg->range_min;
//    filteredLaserScan.ranges = ranges;
//    filteredLaserScan.scan_time = msg->scan_time;
//    filteredLaserScan.time_increment = msg->time_increment;

    // republish the filtered LaserScan
    this->laserScanFilteredPublisher.publish(msg);
  }

  void TurtleHokuyoLaserFilter::printLaserScan(const sensor_msgs::LaserScanConstPtr& msg)
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

    // While ROS is active, do the Node Stuff
    while (ros::ok())
    {
            // At the moment we are only waiting
            std::chrono::milliseconds dura(500);
            std::this_thread::sleep_for(dura);
            ros::spinOnce();
    }

    return 0;
}
