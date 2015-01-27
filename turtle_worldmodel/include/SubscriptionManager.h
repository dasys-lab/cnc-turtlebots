/*
 * SubscriptionManager.h
 *
 *  Created on: 11.11.2014
 *      Author: Jonas Scherbaum
 */

#ifndef CNC_TURTLEBOTS_TURTLE_WORLDMODEL_SRC_SUBSCRIPTIONMANAGER_H_
#define CNC_TURTLEBOTS_TURTLE_WORLDMODEL_SRC_SUBSCRIPTIONMANAGER_H_

#include "nav_msgs/Odometry.h"
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/JointState.h"
#include <ros/ros.h>
#include "TurtleWorldModel.h"

using namespace nav_msgs;
using namespace sensor_msgs;

namespace turtle
{

  class SubscriptionManager
  {
  public:
    static SubscriptionManager* get();
    SubscriptionManager();
    virtual ~SubscriptionManager();
    void odometryCallback(const OdometryConstPtr& msg);
    void imuDataCallback(const ImuConstPtr& msg);
    void jointStateCallback(const JointStateConstPtr& msg);
  private:
    ros::NodeHandle n;
    ros::Subscriber odometrySubscriber;
    ros::Subscriber imuDataSubscriber;
    ros::Subscriber jointStateSubscriber;
  };

} /* namespace turtle */

#endif /* CNC_TURTLEBOTS_TURTLE_WORLDMODEL_SRC_SUBSCRIPTIONMANAGER_H_ */
