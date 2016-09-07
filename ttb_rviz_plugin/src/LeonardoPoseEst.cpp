#include <ros/console.h>

#include <rviz/display_context.h>

#include <tf/transform_listener.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

#include "LeonardoPoseEst.h"

#define ROBOT "leonardo"
#define TOPIC "initialpose"
#define DESC "Pose Estimate"

namespace ttb_rviz_plugin
{

LeonardoPoseEst::LeonardoPoseEst()
{
}

LeonardoPoseEst::~LeonardoPoseEst()
{
}

void LeonardoPoseEst::onInitialize()
{
	PoseTool::onInitialize();
	setName(DESC "(" ROBOT ")");
	pub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>(ROBOT "/" TOPIC, 1);
}

// protected
void LeonardoPoseEst::onPoseSet(double x, double y, double theta) {
	std::string fixed_frame = context_->getFixedFrame().toStdString();
	geometry_msgs::PoseWithCovarianceStamped pose;

	pose.header.frame_id = std::string("/") + fixed_frame;
	pose.header.stamp = ros::Time::now(); 
	pose.pose.pose.position.x = x; 
	pose.pose.pose.position.y = y; 

	tf::Quaternion quat; 
	quat.setRPY(0.0, 0.0, theta); 
	tf::quaternionTFToMsg(quat, 
	                      pose.pose.pose.orientation); 

	pose.pose.covariance[6*0+0] = 0.5 * 0.5; 
	pose.pose.covariance[6*1+1] = 0.5 * 0.5; 
	pose.pose.covariance[6*5+5] = M_PI/12.0 * M_PI/12.0; 
	ROS_INFO("Setting pose of " ROBOT "to : %.3f %.3f %.3f [frame=%s]", x, y, theta, fixed_frame.c_str(
));

	pub.publish(pose);
}

} // namepsace

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(ttb_rviz_plugin::LeonardoPoseEst, rviz::Tool)

