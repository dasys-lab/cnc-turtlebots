#pragma once

#include "TTBWorldModel.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "ttb_msgs/AMCLPoseWrapped.h"
#include "ttb_msgs/GoalWrapped.h"
#include "ttb_msgs/InitialPoseWrapped.h"
#include <engine/AlicaEngine.h>
#include <supplementary/AgentID.h>

#include <ros/ros.h>

namespace ttb
{

class WrappedMessageHandler
{
private:
    const supplementary::AgentID* robotID;
    alica::AlicaEngine* engine;
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

    void onRosPoseWithCovarianceStamped2852345798(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event)
    {
        ttb_msgs::AMCLPoseWrapped message;
        message.receiver.id = robotID->toByteVector();
        message.msg = *event.getMessage();
        pubAMCLPoseWrapped_amcl_pose.publish(message);
    }
    void onRosAMCLPoseWrapped2852345798(const ros::MessageEvent<ttb_msgs::AMCLPoseWrapped>& event)
    {
        const ttb_msgs::AMCLPoseWrapped::ConstPtr& message = event.getMessage();
        auto receiverId = this->engine->getIdFromBytes(message->receiver.id);
        if (*receiverId == *robotID && event.getPublisherName().compare(ros::this_node::getName()) != 0) {
            pubPoseWithCovarianceStamped_amcl_pose.publish(message->msg);
        }
    }
    void onRosPoseStamped3037331423(const ros::MessageEvent<geometry_msgs::PoseStamped>& event)
    {
        ttb_msgs::GoalWrapped message;
        message.receiver.id = robotID->toByteVector();
        message.msg = *event.getMessage();
        pubGoalWrapped_move_base_simple_goal.publish(message);
    }
    void onRosGoalWrapped3037331423(const ros::MessageEvent<ttb_msgs::GoalWrapped>& event)
    {
        const ttb_msgs::GoalWrapped::ConstPtr& message = event.getMessage();
        auto receiverId = this->engine->getIdFromBytes(message->receiver.id);
        if (*receiverId == *robotID && event.getPublisherName().compare(ros::this_node::getName()) != 0) {
            pubPoseStamped_move_base_simple_goal.publish(message->msg);
        }
    }
    void onRosPoseWithCovarianceStamped2637701444(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event)
    {
        ttb_msgs::InitialPoseWrapped message;
        message.receiver.id = robotID->toByteVector();
        message.msg = *event.getMessage();
        pubInitialPoseWrapped_initialpose.publish(message);
    }
    void onRosInitialPoseWrapped2637701444(const ros::MessageEvent<ttb_msgs::InitialPoseWrapped>& event)
    {
        const ttb_msgs::InitialPoseWrapped::ConstPtr& message = event.getMessage();
        auto receiverId = this->engine->getIdFromBytes(message->receiver.id);
        if (*receiverId == *robotID && event.getPublisherName().compare(ros::this_node::getName()) != 0) {
            pubPoseWithCovarianceStamped_initialpose.publish(message->msg);
        }
    }
    void init(const supplementary::AgentID* id, alica::AlicaEngine* engine)
    {
        this->robotID = id;

        sub0 = n.subscribe("/amcl_pose", 5, &WrappedMessageHandler::onRosPoseWithCovarianceStamped2852345798, this);
        sub1 = n.subscribe("/wrapped/move_base_simple/goal", 5, &WrappedMessageHandler::onRosGoalWrapped3037331423, this);
        sub2 = n.subscribe("/wrapped/initialpose", 5, &WrappedMessageHandler::onRosInitialPoseWrapped2637701444, this);

        pubAMCLPoseWrapped_amcl_pose = n.advertise<ttb_msgs::AMCLPoseWrapped>("/wrapped/amcl_pose", 5, false);
        pubPoseWithCovarianceStamped_amcl_pose = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/amcl_pose", 5, false);
        pubGoalWrapped_move_base_simple_goal = n.advertise<ttb_msgs::GoalWrapped>("/wrapped/move_base_simple/goal", 5, false);
        pubPoseStamped_move_base_simple_goal = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 5, false);
        pubInitialPoseWrapped_initialpose = n.advertise<ttb_msgs::InitialPoseWrapped>("/wrapped/initialpose", 5, false);
        pubPoseWithCovarianceStamped_initialpose = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 5, false);

        // wrappedMessagesSubscribers.push_back(nh.subscribe("/wrapped", 10, &WrappedMessageHandler::onWrappedMessage,
        // (TTBWorldModel*)those));
    }
};
} // namespace ttb
