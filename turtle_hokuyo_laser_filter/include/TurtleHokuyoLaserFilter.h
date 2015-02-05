/*
 * TurtleHokuyoLaserFilter.h
 *
 *  Created on: Feb 3, 2015
 *      Author: Jonas Scherbaum
 */

#ifndef CNC_TURTLEBOTS_TURTLE_HOKUYO_LASER_FILTER_SRC_TURTLEHOKUYOLASERFILTER_H_
#define CNC_TURTLEBOTS_TURTLE_HOKUYO_LASER_FILTER_SRC_TURTLEHOKUYOLASERFILTER_H_

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include <vector>
#include <iostream>

namespace turtle
{

  class TurtleHokuyoLaserFilter
  {
  public:
    TurtleHokuyoLaserFilter();
    virtual ~TurtleHokuyoLaserFilter();
    void laserScanCallback(const sensor_msgs::LaserScanConstPtr& msg);
  private:
    void printLaserScan(const sensor_msgs::LaserScanConstPtr& msg);

    ros::NodeHandle nodeHandle;
    ros::Subscriber laserScanSubscriber;
    ros::Publisher laserScanFilteredPublisher;
  };

} /* namespace turtle */

#endif /* CNC_TURTLEBOTS_TURTLE_HOKUYO_LASER_FILTER_SRC_TURTLEHOKUYOLASERFILTER_H_ */
