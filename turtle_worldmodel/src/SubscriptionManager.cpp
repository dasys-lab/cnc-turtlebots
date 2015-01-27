/*
 * SubscriptionManager.cpp
 *
 *  Created on: 11.11.2014
 *      Author: Jonas Scherbaum
 */

#include "../include/SubscriptionManager.h"

using namespace turtle;

namespace turtle
{

  /**
   * The only true way of getting a Thread-Save Singleton Pattern in c++
   */
  SubscriptionManager* SubscriptionManager::get()
  {
          static SubscriptionManager instance;
          return &instance;
  }

  /**
   * Constructor
   */
  SubscriptionManager::SubscriptionManager()
  {
    // Subscribe to all necessary Topics of the Turtlebot Base
    odometrySubscriber = n.subscribe("/odom", 10, &SubscriptionManager::odometryCallback, this);
    imuDataSubscriber = n.subscribe("/mobile_base/sensors/imu_data", 10, &SubscriptionManager::imuDataCallback, this);
    jointStateSubscriber = n.subscribe("/joint_states", 10, &SubscriptionManager::jointStateCallback, this);
  }

  SubscriptionManager::~SubscriptionManager()
  {
    // delete all Subscribers to unregister them from listening
    odometrySubscriber.shutdown();
    imuDataSubscriber.shutdown();
    jointStateSubscriber.shutdown();
  }

  void SubscriptionManager::odometryCallback(const OdometryConstPtr& msg)
  {
   Odometry input_odometry;
   input_odometry = *msg;

//   std::basic_string child_frame_id = input_odometry.child_frame_id; // do i need this ?
   geometry_msgs::PoseWithCovariance pose =  input_odometry.pose;
   geometry_msgs::TwistWithCovariance twist = input_odometry.twist;

   TurtleWorldModel* worldModel;
   worldModel = TurtleWorldModel::get();

   worldModel->setOwnPose(&pose);
   worldModel->setOwnTwist(&twist);
  }

  void SubscriptionManager::imuDataCallback(const ImuConstPtr& msg)
  {
    Imu input_imu_data;
    input_imu_data = *msg;

    TurtleWorldModel* worldModel;
    worldModel = TurtleWorldModel::get();

    worldModel->setOwnImu(&input_imu_data);
  }

  void SubscriptionManager::jointStateCallback(const JointStateConstPtr& msg)
  {
    JointState input_joint_state;
    input_joint_state = *msg;

  }

} /* namespace turtle */
