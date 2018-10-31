
#include <string>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include "ros/ros.h"
#include <ros/transport_hints.h>
#include <stdio.h>

#include <SystemConfig.h>
#include <Configuration.h>
#include <exception>

#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "alica_ros_proxy/PlanTreeInfo.h"
#include "process_manager/ProcessCommand.h"
#include "process_manager/ProcessStats.h"
#include "ttb_msgs/AMCLPoseWrapped.h"
#include "ttb_msgs/GoalWrapped.h"
#include "ttb_msgs/InitialPoseWrapped.h"
#include "tf2_msgs/TFMessage.h"
#include "tf2_msgs/TFMessage.h"
#include "visualization_msgs/Marker.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "kobuki_msgs/SensorState.h"
#include "nav_msgs/Path.h"
#include "visualization_msgs/Marker.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "kobuki_msgs/SensorState.h"
#include "nav_msgs/Path.h"
#include "visualization_msgs/Marker.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "kobuki_msgs/SensorState.h"
#include "nav_msgs/Path.h"

using namespace supplementary;

using boost::asio::ip::udp;

std::string ownRosName;
udp::socket* insocket;
udp::endpoint otherEndPoint;
udp::endpoint destEndPoint;
boost::asio::ip::address multiCastAddress;
boost::asio::io_service io_service;
void handleUdpPacket(const boost::system::error_code& error, std::size_t bytes_transferred);
void listenForPacket();

void onRosPlanTreeInfo3767756765(const ros::MessageEvent<alica_ros_proxy::PlanTreeInfo>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const alica_ros_proxy::PlanTreeInfo::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3767756765u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosProcessCommand3108117629(const ros::MessageEvent<process_manager::ProcessCommand>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const process_manager::ProcessCommand::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3108117629u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosProcessStats2783514677(const ros::MessageEvent<process_manager::ProcessStats>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const process_manager::ProcessStats::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2783514677u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosAMCLPoseWrapped2611391888(const ros::MessageEvent<ttb_msgs::AMCLPoseWrapped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const ttb_msgs::AMCLPoseWrapped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2611391888u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosGoalWrapped3867808201(const ros::MessageEvent<ttb_msgs::GoalWrapped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const ttb_msgs::GoalWrapped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3867808201u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosInitialPoseWrapped1388158846(const ros::MessageEvent<ttb_msgs::InitialPoseWrapped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const ttb_msgs::InitialPoseWrapped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 1388158846u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosTFMessage491265(const ros::MessageEvent<tf2_msgs::TFMessage>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const tf2_msgs::TFMessage::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 491265u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosTFMessage85788968(const ros::MessageEvent<tf2_msgs::TFMessage>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const tf2_msgs::TFMessage::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 85788968u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosMarker52450053(const ros::MessageEvent<visualization_msgs::Marker>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const visualization_msgs::Marker::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 52450053u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseWithCovarianceStamped3236539441(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3236539441u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseStamped674080570(const ros::MessageEvent<geometry_msgs::PoseStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 674080570u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseWithCovarianceStamped491912439(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 491912439u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosSensorState2224094020(const ros::MessageEvent<kobuki_msgs::SensorState>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const kobuki_msgs::SensorState::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2224094020u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPath1915029401(const ros::MessageEvent<nav_msgs::Path>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const nav_msgs::Path::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 1915029401u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosMarker979314518(const ros::MessageEvent<visualization_msgs::Marker>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const visualization_msgs::Marker::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 979314518u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseWithCovarianceStamped3076792854(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3076792854u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseStamped4093078319(const ros::MessageEvent<geometry_msgs::PoseStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 4093078319u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseWithCovarianceStamped3004550932(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3004550932u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosSensorState4286660741(const ros::MessageEvent<kobuki_msgs::SensorState>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const kobuki_msgs::SensorState::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 4286660741u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPath3976623430(const ros::MessageEvent<nav_msgs::Path>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const nav_msgs::Path::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3976623430u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosMarker3940289819(const ros::MessageEvent<visualization_msgs::Marker>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const visualization_msgs::Marker::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3940289819u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseWithCovarianceStamped736595839(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 736595839u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseStamped2503873000(const ros::MessageEvent<geometry_msgs::PoseStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2503873000u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseWithCovarianceStamped2083032085(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2083032085u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosSensorState1954641914(const ros::MessageEvent<kobuki_msgs::SensorState>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const kobuki_msgs::SensorState::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 1954641914u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPath1699739415(const ros::MessageEvent<nav_msgs::Path>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const nav_msgs::Path::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 1699739415u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}

ros::Publisher pub3767756765;
ros::Publisher pub3108117629;
ros::Publisher pub2783514677;
ros::Publisher pub2611391888;
ros::Publisher pub3867808201;
ros::Publisher pub1388158846;
ros::Publisher pub491265;
ros::Publisher pub85788968;
ros::Publisher pub52450053;
ros::Publisher pub3236539441;
ros::Publisher pub674080570;
ros::Publisher pub491912439;
ros::Publisher pub2224094020;
ros::Publisher pub1915029401;
ros::Publisher pub979314518;
ros::Publisher pub3076792854;
ros::Publisher pub4093078319;
ros::Publisher pub3004550932;
ros::Publisher pub4286660741;
ros::Publisher pub3976623430;
ros::Publisher pub3940289819;
ros::Publisher pub736595839;
ros::Publisher pub2503873000;
ros::Publisher pub2083032085;
ros::Publisher pub1954641914;
ros::Publisher pub1699739415;

boost::array<char, 64000> inBuffer;
void listenForPacket() {
    insocket->async_receive_from(boost::asio::buffer(inBuffer), otherEndPoint,
            boost::bind(
                    &handleUdpPacket, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}
void handleUdpPacket(const boost::system::error_code& error, std::size_t bytes_transferred) {
    // std::cout << "From "<<otherEndPoint.address() << std::endl;
    if (bytes_transferred > 64000) {
        return;
    }
    if (!error) {  // && otherEndPoint.address() != localIP) {
        __uint32_t id = *((__uint32_t*) (inBuffer.data()));
        // std::cout << "Got packet"<<std::endl;
        try {
            ros::serialization::IStream stream(
                    ((uint8_t*) inBuffer.data()) + sizeof(__uint32_t), bytes_transferred - sizeof(__uint32_t));
            switch (id) {
case 3767756765ul: {
alica_ros_proxy::PlanTreeInfo m3767756765;
ros::serialization::Serializer<alica_ros_proxy::PlanTreeInfo>::read(stream, m3767756765);
pub3767756765.publish<alica_ros_proxy::PlanTreeInfo>(m3767756765);
break; }
case 3108117629ul: {
process_manager::ProcessCommand m3108117629;
ros::serialization::Serializer<process_manager::ProcessCommand>::read(stream, m3108117629);
pub3108117629.publish<process_manager::ProcessCommand>(m3108117629);
break; }
case 2783514677ul: {
process_manager::ProcessStats m2783514677;
ros::serialization::Serializer<process_manager::ProcessStats>::read(stream, m2783514677);
pub2783514677.publish<process_manager::ProcessStats>(m2783514677);
break; }
case 2611391888ul: {
ttb_msgs::AMCLPoseWrapped m2611391888;
ros::serialization::Serializer<ttb_msgs::AMCLPoseWrapped>::read(stream, m2611391888);
pub2611391888.publish<ttb_msgs::AMCLPoseWrapped>(m2611391888);
break; }
case 3867808201ul: {
ttb_msgs::GoalWrapped m3867808201;
ros::serialization::Serializer<ttb_msgs::GoalWrapped>::read(stream, m3867808201);
pub3867808201.publish<ttb_msgs::GoalWrapped>(m3867808201);
break; }
case 1388158846ul: {
ttb_msgs::InitialPoseWrapped m1388158846;
ros::serialization::Serializer<ttb_msgs::InitialPoseWrapped>::read(stream, m1388158846);
pub1388158846.publish<ttb_msgs::InitialPoseWrapped>(m1388158846);
break; }
case 491265ul: {
tf2_msgs::TFMessage m491265;
ros::serialization::Serializer<tf2_msgs::TFMessage>::read(stream, m491265);
pub491265.publish<tf2_msgs::TFMessage>(m491265);
break; }
case 85788968ul: {
tf2_msgs::TFMessage m85788968;
ros::serialization::Serializer<tf2_msgs::TFMessage>::read(stream, m85788968);
pub85788968.publish<tf2_msgs::TFMessage>(m85788968);
break; }
case 52450053ul: {
visualization_msgs::Marker m52450053;
ros::serialization::Serializer<visualization_msgs::Marker>::read(stream, m52450053);
pub52450053.publish<visualization_msgs::Marker>(m52450053);
break; }
case 3236539441ul: {
geometry_msgs::PoseWithCovarianceStamped m3236539441;
ros::serialization::Serializer<geometry_msgs::PoseWithCovarianceStamped>::read(stream, m3236539441);
pub3236539441.publish<geometry_msgs::PoseWithCovarianceStamped>(m3236539441);
break; }
case 674080570ul: {
geometry_msgs::PoseStamped m674080570;
ros::serialization::Serializer<geometry_msgs::PoseStamped>::read(stream, m674080570);
pub674080570.publish<geometry_msgs::PoseStamped>(m674080570);
break; }
case 491912439ul: {
geometry_msgs::PoseWithCovarianceStamped m491912439;
ros::serialization::Serializer<geometry_msgs::PoseWithCovarianceStamped>::read(stream, m491912439);
pub491912439.publish<geometry_msgs::PoseWithCovarianceStamped>(m491912439);
break; }
case 2224094020ul: {
kobuki_msgs::SensorState m2224094020;
ros::serialization::Serializer<kobuki_msgs::SensorState>::read(stream, m2224094020);
pub2224094020.publish<kobuki_msgs::SensorState>(m2224094020);
break; }
case 1915029401ul: {
nav_msgs::Path m1915029401;
ros::serialization::Serializer<nav_msgs::Path>::read(stream, m1915029401);
pub1915029401.publish<nav_msgs::Path>(m1915029401);
break; }
case 979314518ul: {
visualization_msgs::Marker m979314518;
ros::serialization::Serializer<visualization_msgs::Marker>::read(stream, m979314518);
pub979314518.publish<visualization_msgs::Marker>(m979314518);
break; }
case 3076792854ul: {
geometry_msgs::PoseWithCovarianceStamped m3076792854;
ros::serialization::Serializer<geometry_msgs::PoseWithCovarianceStamped>::read(stream, m3076792854);
pub3076792854.publish<geometry_msgs::PoseWithCovarianceStamped>(m3076792854);
break; }
case 4093078319ul: {
geometry_msgs::PoseStamped m4093078319;
ros::serialization::Serializer<geometry_msgs::PoseStamped>::read(stream, m4093078319);
pub4093078319.publish<geometry_msgs::PoseStamped>(m4093078319);
break; }
case 3004550932ul: {
geometry_msgs::PoseWithCovarianceStamped m3004550932;
ros::serialization::Serializer<geometry_msgs::PoseWithCovarianceStamped>::read(stream, m3004550932);
pub3004550932.publish<geometry_msgs::PoseWithCovarianceStamped>(m3004550932);
break; }
case 4286660741ul: {
kobuki_msgs::SensorState m4286660741;
ros::serialization::Serializer<kobuki_msgs::SensorState>::read(stream, m4286660741);
pub4286660741.publish<kobuki_msgs::SensorState>(m4286660741);
break; }
case 3976623430ul: {
nav_msgs::Path m3976623430;
ros::serialization::Serializer<nav_msgs::Path>::read(stream, m3976623430);
pub3976623430.publish<nav_msgs::Path>(m3976623430);
break; }
case 3940289819ul: {
visualization_msgs::Marker m3940289819;
ros::serialization::Serializer<visualization_msgs::Marker>::read(stream, m3940289819);
pub3940289819.publish<visualization_msgs::Marker>(m3940289819);
break; }
case 736595839ul: {
geometry_msgs::PoseWithCovarianceStamped m736595839;
ros::serialization::Serializer<geometry_msgs::PoseWithCovarianceStamped>::read(stream, m736595839);
pub736595839.publish<geometry_msgs::PoseWithCovarianceStamped>(m736595839);
break; }
case 2503873000ul: {
geometry_msgs::PoseStamped m2503873000;
ros::serialization::Serializer<geometry_msgs::PoseStamped>::read(stream, m2503873000);
pub2503873000.publish<geometry_msgs::PoseStamped>(m2503873000);
break; }
case 2083032085ul: {
geometry_msgs::PoseWithCovarianceStamped m2083032085;
ros::serialization::Serializer<geometry_msgs::PoseWithCovarianceStamped>::read(stream, m2083032085);
pub2083032085.publish<geometry_msgs::PoseWithCovarianceStamped>(m2083032085);
break; }
case 1954641914ul: {
kobuki_msgs::SensorState m1954641914;
ros::serialization::Serializer<kobuki_msgs::SensorState>::read(stream, m1954641914);
pub1954641914.publish<kobuki_msgs::SensorState>(m1954641914);
break; }
case 1699739415ul: {
nav_msgs::Path m1699739415;
ros::serialization::Serializer<nav_msgs::Path>::read(stream, m1699739415);
pub1699739415.publish<nav_msgs::Path>(m1699739415);
break; }
                default: std::cerr << "Cannot find Matching topic:" << id << std::endl;
            }
        } catch (std::exception& e) {
            ROS_ERROR_STREAM_THROTTLE(2, "Exception while receiving DDS message:" << e.what() << " Discarding message!");
        }
    }
    listenForPacket();
    return;
}
void run() {
    io_service.run();
}

int main(int argc, char* argv[]) {
    SystemConfig* sc = SystemConfig::getInstance();

    // Configuration *proxyconf = (*sc)["UdpProxy"];
Configuration *proxyconf = (*sc)["ttb_udp_proxy"];
    // std::string port = proxyconf->get<std::string>("UdpProxy","Port",NULL);

    std::string baddress = proxyconf->get<std::string>("UdpProxy", "MulticastAddress", NULL);

    unsigned short port = (unsigned short) proxyconf->get<int>("UdpProxy", "Port", NULL);

    // udp::resolver resolver(io_service);
    // udp::resolver::query query(udp::v4(), baddress, port);

    // bcastEndPoint = *resolver.resolve(query);

    // myEndPoint = udp::endpoint(udp::v4(),bcastEndPoint.port());

    multiCastAddress = boost::asio::ip::address::from_string(baddress);
    destEndPoint = udp::endpoint(multiCastAddress, port);

    std::cout << "Opening to " << multiCastAddress << std::endl;

    insocket = new udp::socket(io_service, udp::endpoint(multiCastAddress, port));

    insocket->set_option(boost::asio::ip::multicast::enable_loopback(false));
    insocket->set_option(boost::asio::ip::multicast::join_group(multiCastAddress));
    listenForPacket();

ros::init(argc, argv, "ttb_udp_proxy");
    //   ros::init(argc, argv, "udpProxy");

    ros::NodeHandle n;
    ownRosName = ros::this_node::getName();  // n.getNamespace();//n.resolveName("ddsProxy",true);

    std::cout << ownRosName << std::endl;

ros::Subscriber sub0 = n.subscribe("/AlicaEngine/PlanTreeInfo",5, onRosPlanTreeInfo3767756765,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub1 = n.subscribe("/process_manager/ProcessCommand",5, onRosProcessCommand3108117629,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub2 = n.subscribe("/process_manager/ProcessStats",5, onRosProcessStats2783514677,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub3 = n.subscribe("/wrapped/amcl_pose",5, onRosAMCLPoseWrapped2611391888,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub4 = n.subscribe("/wrapped/move_base_simple/goal",5, onRosGoalWrapped3867808201,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub5 = n.subscribe("/wrapped/initialpose",5, onRosInitialPoseWrapped1388158846,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub6 = n.subscribe("/tf",5, onRosTFMessage491265,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub7 = n.subscribe("/tf_static",5, onRosTFMessage85788968,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub8 = n.subscribe("/leonardo/visualization_marker",5, onRosMarker52450053,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub9 = n.subscribe("/leonardo/amcl_pose",5, onRosPoseWithCovarianceStamped3236539441,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub10 = n.subscribe("/leonardo/move_base_simple/goal",5, onRosPoseStamped674080570,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub11 = n.subscribe("/leonardo/initialpose",5, onRosPoseWithCovarianceStamped491912439,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub12 = n.subscribe("/leonardo/mobile_base/sensors/core",5, onRosSensorState2224094020,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub13 = n.subscribe("/leonardo/move_base/NavfnROS/plan",5, onRosPath1915029401,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub14 = n.subscribe("/raphael/visualization_marker",5, onRosMarker979314518,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub15 = n.subscribe("/raphael/amcl_pose",5, onRosPoseWithCovarianceStamped3076792854,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub16 = n.subscribe("/raphael/move_base_simple/goal",5, onRosPoseStamped4093078319,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub17 = n.subscribe("/raphael/initialpose",5, onRosPoseWithCovarianceStamped3004550932,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub18 = n.subscribe("/raphael/mobile_base/sensors/core",5, onRosSensorState4286660741,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub19 = n.subscribe("/raphael/move_base/NavfnROS/plan",5, onRosPath3976623430,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub20 = n.subscribe("/donatello/visualization_marker",5, onRosMarker3940289819,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub21 = n.subscribe("/donatello/amcl_pose",5, onRosPoseWithCovarianceStamped736595839,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub22 = n.subscribe("/donatello/move_base_simple/goal",5, onRosPoseStamped2503873000,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub23 = n.subscribe("/donatello/initialpose",5, onRosPoseWithCovarianceStamped2083032085,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub24 = n.subscribe("/donatello/mobile_base/sensors/core",5, onRosSensorState1954641914,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub25 = n.subscribe("/donatello/move_base/NavfnROS/plan",5, onRosPath1699739415,ros::TransportHints().unreliable().tcpNoDelay().reliable());

pub3767756765 = n.advertise<alica_ros_proxy::PlanTreeInfo>("/AlicaEngine/PlanTreeInfo",5,false);
pub3108117629 = n.advertise<process_manager::ProcessCommand>("/process_manager/ProcessCommand",5,false);
pub2783514677 = n.advertise<process_manager::ProcessStats>("/process_manager/ProcessStats",5,false);
pub2611391888 = n.advertise<ttb_msgs::AMCLPoseWrapped>("/wrapped/amcl_pose",5,false);
pub3867808201 = n.advertise<ttb_msgs::GoalWrapped>("/wrapped/move_base_simple/goal",5,false);
pub1388158846 = n.advertise<ttb_msgs::InitialPoseWrapped>("/wrapped/initialpose",5,false);
pub491265 = n.advertise<tf2_msgs::TFMessage>("/tf",5,false);
pub85788968 = n.advertise<tf2_msgs::TFMessage>("/tf_static",5,false);
pub52450053 = n.advertise<visualization_msgs::Marker>("/leonardo/visualization_marker",5,false);
pub3236539441 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/leonardo/amcl_pose",5,false);
pub674080570 = n.advertise<geometry_msgs::PoseStamped>("/leonardo/move_base_simple/goal",5,false);
pub491912439 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/leonardo/initialpose",5,false);
pub2224094020 = n.advertise<kobuki_msgs::SensorState>("/leonardo/mobile_base/sensors/core",5,false);
pub1915029401 = n.advertise<nav_msgs::Path>("/leonardo/move_base/NavfnROS/plan",5,false);
pub979314518 = n.advertise<visualization_msgs::Marker>("/raphael/visualization_marker",5,false);
pub3076792854 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/raphael/amcl_pose",5,false);
pub4093078319 = n.advertise<geometry_msgs::PoseStamped>("/raphael/move_base_simple/goal",5,false);
pub3004550932 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/raphael/initialpose",5,false);
pub4286660741 = n.advertise<kobuki_msgs::SensorState>("/raphael/mobile_base/sensors/core",5,false);
pub3976623430 = n.advertise<nav_msgs::Path>("/raphael/move_base/NavfnROS/plan",5,false);
pub3940289819 = n.advertise<visualization_msgs::Marker>("/donatello/visualization_marker",5,false);
pub736595839 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/donatello/amcl_pose",5,false);
pub2503873000 = n.advertise<geometry_msgs::PoseStamped>("/donatello/move_base_simple/goal",5,false);
pub2083032085 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/donatello/initialpose",5,false);
pub1954641914 = n.advertise<kobuki_msgs::SensorState>("/donatello/mobile_base/sensors/core",5,false);
pub1699739415 = n.advertise<nav_msgs::Path>("/donatello/move_base/NavfnROS/plan",5,false);

    boost::thread iothread(run);

    // ros::spin();
    ros::AsyncSpinner* spinner;

    spinner = new ros::AsyncSpinner(4);
    spinner->start();

    std::cout << "Ros2Udp Proxy running..." << std::endl;
    while (n.ok()) {
        usleep(300000);
    }
    io_service.stop();
    iothread.join();
    return 0;
}

