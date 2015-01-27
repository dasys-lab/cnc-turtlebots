/*
 * variancer.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: Jonas Scherbaum
 */

#include "ros/ros.h"
#include <nav_msgs/Odometry.h>

using namespace turtle;

namespace turtle
{


}

int main(int argc, char** argv)
{

  // Init Ros and his rate
  ros::init(argc, argv, "TurtleVariancer");
  ros::Rate loop_rate(10);

  // create Handle for this node
  ros::NodeHandle variancerHandle;

  // create subscriber and publisher

  // Processing loop
  while(ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }
}


