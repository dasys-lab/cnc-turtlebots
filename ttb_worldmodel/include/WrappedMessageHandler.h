//
// Created by marci on 17.04.16.
//

#ifndef SUPPLEMENTARY_WRAPPEDMESSAGEHANDLER_H
#define SUPPLEMENTARY_WRAPPEDMESSAGEHANDLER_H

#include <ros/ros.h>

#include "TTBWorldModel.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "ttb_msgs/AMCLPoseWrapped.h"
#include "geometry_msgs/PoseStamped.h"
#include "ttb_msgs/GoalWrapped.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "ttb_msgs/InitialPoseWrapped.h"

namespace ttb
{

    class WrappedMessageHandler
    {
    private:
        int robotID;
        ros::NodeHandle n;
        // get incoming wrapped messages and publish them (unwrapped) on the local ros core





    public:
ros::Publisher pubPoseWithCovarianceStamped_amcl_pose;
ros::Publisher pubAMCLPoseWrapped_amcl_pose;
ros::Subscriber sub0;
ros::Subscriber sub1;
ros::Publisher pubPoseStamped_move_base_simple_goal;
ros::Publisher pubGoalWrapped_move_base_simple_goal;
ros::Subscriber sub2;
ros::Subscriber sub3;
ros::Publisher pubPoseWithCovarianceStamped_initialpose;
ros::Publisher pubInitialPoseWrapped_initialpose;
ros::Subscriber sub4;
ros::Subscriber sub5;

void onRosPoseWithCovarianceStamped2852345798(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event) {
	ttb_msgs::AMCLPoseWrapped message;
	message.receiverId = robotID;
	message.msg = *event.getMessage();
	pubAMCLPoseWrapped_amcl_pose.publish(message);
}
void onRosGoalWrapped3037331423(const ros::MessageEvent<ttb_msgs::GoalWrapped>& event) {
	const ttb_msgs::GoalWrapped::ConstPtr& message = event.getMessage();
	if(message->receiverId == robotID && event.getPublisherName().compare(ros::this_node::getName()) != 0)
	{		pubPoseStamped_move_base_simple_goal.publish(message->msg);
	}
}
void onRosInitialPoseWrapped2637701444(const ros::MessageEvent<ttb_msgs::InitialPoseWrapped>& event) {
	const ttb_msgs::InitialPoseWrapped::ConstPtr& message = event.getMessage();
	if(message->receiverId == robotID && event.getPublisherName().compare(ros::this_node::getName()) != 0)
	{		pubPoseWithCovarianceStamped_initialpose.publish(message->msg);
	}
}        void init(int& id)
        {
            this->robotID = id;

sub1 = n.subscribe("/amcl_pose",5, &WrappedMessageHandler::onRosPoseWithCovarianceStamped2852345798,this);
sub2 = n.subscribe("/wrapped/move_base_simple/goal",5, &WrappedMessageHandler::onRosGoalWrapped3037331423,this);
sub4 = n.subscribe("/wrapped/initialpose",5, &WrappedMessageHandler::onRosInitialPoseWrapped2637701444,this);

pubAMCLPoseWrapped_amcl_pose = n.advertise<ttb_msgs::AMCLPoseWrapped>("/wrapped/amcl_pose",5,false);
pubPoseWithCovarianceStamped_amcl_pose = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/amcl_pose",5,false);
pubGoalWrapped_move_base_simple_goal = n.advertise<ttb_msgs::GoalWrapped>("/wrapped/move_base_simple/goal",5,false);
pubPoseStamped_move_base_simple_goal = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal",5,false);
pubInitialPoseWrapped_initialpose = n.advertise<ttb_msgs::InitialPoseWrapped>("/wrapped/initialpose",5,false);
pubPoseWithCovarianceStamped_initialpose = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose",5,false);

            //wrappedMessagesSubscribers.push_back(nh.subscribe("/wrapped", 10, &WrappedMessageHandler::onWrappedMessage, (TTBWorldModel*)those));
        }


    };

}

#endif //SUPPLEMENTARY_WRAPPEDMESSAGEHANDLER_H

