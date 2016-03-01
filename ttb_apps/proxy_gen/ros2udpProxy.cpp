
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


#include "sensor_msgs/PointCloud.h"
#include "sensor_msgs/PointCloud.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "sensor_msgs/PointCloud.h"
#include "sensor_msgs/PointCloud.h"
#include "msl_sensor_msgs/VisionDebug.h"
#include "msl_sensor_msgs/VisionControl.h"
#include "msl_sensor_msgs/VisionImage.h"
#include "msl_actuator_msgs/KickerStatInfo.h"
#include "msl_actuator_msgs/MotionStatInfo.h"
#include "msl_helper_msgs/PassMsg.h"
#include "std_msgs/String.h"
#include "msl_msgs/RefBoxCommand.h"
#include "msl_msgs/JoystickCommand.h"
#include "msl_sensor_msgs/SharedWorldInfo.h"
#include "msl_msgs/PathPlanner.h"
#include "msl_msgs/VoronoiNetInfo.h"
#include "msl_msgs/CorridorCheck.h"
#include "alica_ros_proxy/PlanTreeInfo.h"
#include "alica_ros_proxy/AlicaEngineInfo.h"
#include "alica_ros_proxy/SyncTalk.h"
#include "alica_ros_proxy/SyncReady.h"
#include "alica_ros_proxy/AllocationAuthorityInfo.h"
#include "alica_ros_proxy/SolverResult.h"
#include "msl_sensor_msgs/CameraSettings.h"
#include "msl_sensor_msgs/CameraSettingsRequest.h"
#include "process_manager/ProcessCommand.h"
#include "process_manager/ProcessStats.h"

using namespace supplementary;



using boost::asio::ip::udp;



std::string ownRosName;
udp::socket* insocket;
udp::endpoint otherEndPoint;
udp::endpoint destEndPoint;
boost::asio::ip::address multiCastAddress;
boost::asio::io_service io_service;
void handleUdpPacket(const boost::system::error_code& error,   std::size_t bytes_transferred);
void listenForPacket();



void onRosPointCloud697841562(const ros::MessageEvent<sensor_msgs::PointCloud>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const sensor_msgs::PointCloud::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 697841562u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPointCloud715397477(const ros::MessageEvent<sensor_msgs::PointCloud>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const sensor_msgs::PointCloud::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 715397477u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseWithCovarianceStamped2852345798(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2852345798u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPointCloud2644558886(const ros::MessageEvent<sensor_msgs::PointCloud>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const sensor_msgs::PointCloud::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2644558886u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPointCloud2242425699(const ros::MessageEvent<sensor_msgs::PointCloud>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const sensor_msgs::PointCloud::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2242425699u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosVisionDebug4287086446(const ros::MessageEvent<msl_sensor_msgs::VisionDebug>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_sensor_msgs::VisionDebug::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 4287086446u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosVisionControl3818207232(const ros::MessageEvent<msl_sensor_msgs::VisionControl>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_sensor_msgs::VisionControl::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3818207232u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosVisionImage520651946(const ros::MessageEvent<msl_sensor_msgs::VisionImage>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_sensor_msgs::VisionImage::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 520651946u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosKickerStatInfo3915861504(const ros::MessageEvent<msl_actuator_msgs::KickerStatInfo>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_actuator_msgs::KickerStatInfo::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3915861504u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosMotionStatInfo825806425(const ros::MessageEvent<msl_actuator_msgs::MotionStatInfo>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_actuator_msgs::MotionStatInfo::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 825806425u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPassMsg888918809(const ros::MessageEvent<msl_helper_msgs::PassMsg>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_helper_msgs::PassMsg::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 888918809u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosString4022577436(const ros::MessageEvent<std_msgs::String>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const std_msgs::String::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 4022577436u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosRefBoxCommand1841334100(const ros::MessageEvent<msl_msgs::RefBoxCommand>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_msgs::RefBoxCommand::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 1841334100u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosJoystickCommand1506505735(const ros::MessageEvent<msl_msgs::JoystickCommand>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_msgs::JoystickCommand::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 1506505735u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosSharedWorldInfo2791795402(const ros::MessageEvent<msl_sensor_msgs::SharedWorldInfo>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_sensor_msgs::SharedWorldInfo::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2791795402u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPathPlanner709768768(const ros::MessageEvent<msl_msgs::PathPlanner>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_msgs::PathPlanner::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 709768768u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosVoronoiNetInfo179313306(const ros::MessageEvent<msl_msgs::VoronoiNetInfo>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_msgs::VoronoiNetInfo::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 179313306u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosCorridorCheck2924935533(const ros::MessageEvent<msl_msgs::CorridorCheck>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_msgs::CorridorCheck::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2924935533u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
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
void onRosAlicaEngineInfo238666206(const ros::MessageEvent<alica_ros_proxy::AlicaEngineInfo>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const alica_ros_proxy::AlicaEngineInfo::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 238666206u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosSyncTalk4175715375(const ros::MessageEvent<alica_ros_proxy::SyncTalk>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const alica_ros_proxy::SyncTalk::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 4175715375u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosSyncReady636345472(const ros::MessageEvent<alica_ros_proxy::SyncReady>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const alica_ros_proxy::SyncReady::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 636345472u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosAllocationAuthorityInfo690246385(const ros::MessageEvent<alica_ros_proxy::AllocationAuthorityInfo>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const alica_ros_proxy::AllocationAuthorityInfo::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 690246385u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosSolverResult2276189600(const ros::MessageEvent<alica_ros_proxy::SolverResult>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const alica_ros_proxy::SolverResult::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2276189600u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosCameraSettings2163940045(const ros::MessageEvent<msl_sensor_msgs::CameraSettings>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_sensor_msgs::CameraSettings::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2163940045u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosCameraSettingsRequest3170299750(const ros::MessageEvent<msl_sensor_msgs::CameraSettingsRequest>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const msl_sensor_msgs::CameraSettingsRequest::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3170299750u;
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

ros::Publisher pub697841562;
ros::Publisher pub715397477;
ros::Publisher pub2852345798;
ros::Publisher pub2644558886;
ros::Publisher pub2242425699;
ros::Publisher pub4287086446;
ros::Publisher pub3818207232;
ros::Publisher pub520651946;
ros::Publisher pub3915861504;
ros::Publisher pub825806425;
ros::Publisher pub888918809;
ros::Publisher pub4022577436;
ros::Publisher pub1841334100;
ros::Publisher pub1506505735;
ros::Publisher pub2791795402;
ros::Publisher pub709768768;
ros::Publisher pub179313306;
ros::Publisher pub2924935533;
ros::Publisher pub3767756765;
ros::Publisher pub238666206;
ros::Publisher pub4175715375;
ros::Publisher pub636345472;
ros::Publisher pub690246385;
ros::Publisher pub2276189600;
ros::Publisher pub2163940045;
ros::Publisher pub3170299750;
ros::Publisher pub3108117629;
ros::Publisher pub2783514677;

boost::array<char,64000> inBuffer;
void listenForPacket() {
	insocket->async_receive_from(boost::asio::buffer(inBuffer), otherEndPoint,
        boost::bind(&handleUdpPacket, boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
}
void handleUdpPacket(const boost::system::error_code& error,   std::size_t bytes_transferred) {
	//std::cout << "From "<<otherEndPoint.address() << std::endl;
	if (!error) { // && otherEndPoint.address() != localIP) {
		__uint32_t id = *((__uint32_t*)(inBuffer.data()));
		//std::cout << "Got packet"<<std::endl;
		try {	
			ros::serialization::IStream stream(((uint8_t*)inBuffer.data())+sizeof(__uint32_t),bytes_transferred-sizeof(__uint32_t));
			switch(id) {
case 697841562ul: {
sensor_msgs::PointCloud m697841562;
ros::serialization::Serializer<sensor_msgs::PointCloud>::read(stream, m697841562);
pub697841562.publish<sensor_msgs::PointCloud>(m697841562);
break; }
case 715397477ul: {
sensor_msgs::PointCloud m715397477;
ros::serialization::Serializer<sensor_msgs::PointCloud>::read(stream, m715397477);
pub715397477.publish<sensor_msgs::PointCloud>(m715397477);
break; }
case 2852345798ul: {
geometry_msgs::PoseWithCovarianceStamped m2852345798;
ros::serialization::Serializer<geometry_msgs::PoseWithCovarianceStamped>::read(stream, m2852345798);
pub2852345798.publish<geometry_msgs::PoseWithCovarianceStamped>(m2852345798);
break; }
case 2644558886ul: {
sensor_msgs::PointCloud m2644558886;
ros::serialization::Serializer<sensor_msgs::PointCloud>::read(stream, m2644558886);
pub2644558886.publish<sensor_msgs::PointCloud>(m2644558886);
break; }
case 2242425699ul: {
sensor_msgs::PointCloud m2242425699;
ros::serialization::Serializer<sensor_msgs::PointCloud>::read(stream, m2242425699);
pub2242425699.publish<sensor_msgs::PointCloud>(m2242425699);
break; }
case 4287086446ul: {
msl_sensor_msgs::VisionDebug m4287086446;
ros::serialization::Serializer<msl_sensor_msgs::VisionDebug>::read(stream, m4287086446);
pub4287086446.publish<msl_sensor_msgs::VisionDebug>(m4287086446);
break; }
case 3818207232ul: {
msl_sensor_msgs::VisionControl m3818207232;
ros::serialization::Serializer<msl_sensor_msgs::VisionControl>::read(stream, m3818207232);
pub3818207232.publish<msl_sensor_msgs::VisionControl>(m3818207232);
break; }
case 520651946ul: {
msl_sensor_msgs::VisionImage m520651946;
ros::serialization::Serializer<msl_sensor_msgs::VisionImage>::read(stream, m520651946);
pub520651946.publish<msl_sensor_msgs::VisionImage>(m520651946);
break; }
case 3915861504ul: {
msl_actuator_msgs::KickerStatInfo m3915861504;
ros::serialization::Serializer<msl_actuator_msgs::KickerStatInfo>::read(stream, m3915861504);
pub3915861504.publish<msl_actuator_msgs::KickerStatInfo>(m3915861504);
break; }
case 825806425ul: {
msl_actuator_msgs::MotionStatInfo m825806425;
ros::serialization::Serializer<msl_actuator_msgs::MotionStatInfo>::read(stream, m825806425);
pub825806425.publish<msl_actuator_msgs::MotionStatInfo>(m825806425);
break; }
case 888918809ul: {
msl_helper_msgs::PassMsg m888918809;
ros::serialization::Serializer<msl_helper_msgs::PassMsg>::read(stream, m888918809);
pub888918809.publish<msl_helper_msgs::PassMsg>(m888918809);
break; }
case 4022577436ul: {
std_msgs::String m4022577436;
ros::serialization::Serializer<std_msgs::String>::read(stream, m4022577436);
pub4022577436.publish<std_msgs::String>(m4022577436);
break; }
case 1841334100ul: {
msl_msgs::RefBoxCommand m1841334100;
ros::serialization::Serializer<msl_msgs::RefBoxCommand>::read(stream, m1841334100);
pub1841334100.publish<msl_msgs::RefBoxCommand>(m1841334100);
break; }
case 1506505735ul: {
msl_msgs::JoystickCommand m1506505735;
ros::serialization::Serializer<msl_msgs::JoystickCommand>::read(stream, m1506505735);
pub1506505735.publish<msl_msgs::JoystickCommand>(m1506505735);
break; }
case 2791795402ul: {
msl_sensor_msgs::SharedWorldInfo m2791795402;
ros::serialization::Serializer<msl_sensor_msgs::SharedWorldInfo>::read(stream, m2791795402);
pub2791795402.publish<msl_sensor_msgs::SharedWorldInfo>(m2791795402);
break; }
case 709768768ul: {
msl_msgs::PathPlanner m709768768;
ros::serialization::Serializer<msl_msgs::PathPlanner>::read(stream, m709768768);
pub709768768.publish<msl_msgs::PathPlanner>(m709768768);
break; }
case 179313306ul: {
msl_msgs::VoronoiNetInfo m179313306;
ros::serialization::Serializer<msl_msgs::VoronoiNetInfo>::read(stream, m179313306);
pub179313306.publish<msl_msgs::VoronoiNetInfo>(m179313306);
break; }
case 2924935533ul: {
msl_msgs::CorridorCheck m2924935533;
ros::serialization::Serializer<msl_msgs::CorridorCheck>::read(stream, m2924935533);
pub2924935533.publish<msl_msgs::CorridorCheck>(m2924935533);
break; }
case 3767756765ul: {
alica_ros_proxy::PlanTreeInfo m3767756765;
ros::serialization::Serializer<alica_ros_proxy::PlanTreeInfo>::read(stream, m3767756765);
pub3767756765.publish<alica_ros_proxy::PlanTreeInfo>(m3767756765);
break; }
case 238666206ul: {
alica_ros_proxy::AlicaEngineInfo m238666206;
ros::serialization::Serializer<alica_ros_proxy::AlicaEngineInfo>::read(stream, m238666206);
pub238666206.publish<alica_ros_proxy::AlicaEngineInfo>(m238666206);
break; }
case 4175715375ul: {
alica_ros_proxy::SyncTalk m4175715375;
ros::serialization::Serializer<alica_ros_proxy::SyncTalk>::read(stream, m4175715375);
pub4175715375.publish<alica_ros_proxy::SyncTalk>(m4175715375);
break; }
case 636345472ul: {
alica_ros_proxy::SyncReady m636345472;
ros::serialization::Serializer<alica_ros_proxy::SyncReady>::read(stream, m636345472);
pub636345472.publish<alica_ros_proxy::SyncReady>(m636345472);
break; }
case 690246385ul: {
alica_ros_proxy::AllocationAuthorityInfo m690246385;
ros::serialization::Serializer<alica_ros_proxy::AllocationAuthorityInfo>::read(stream, m690246385);
pub690246385.publish<alica_ros_proxy::AllocationAuthorityInfo>(m690246385);
break; }
case 2276189600ul: {
alica_ros_proxy::SolverResult m2276189600;
ros::serialization::Serializer<alica_ros_proxy::SolverResult>::read(stream, m2276189600);
pub2276189600.publish<alica_ros_proxy::SolverResult>(m2276189600);
break; }
case 2163940045ul: {
msl_sensor_msgs::CameraSettings m2163940045;
ros::serialization::Serializer<msl_sensor_msgs::CameraSettings>::read(stream, m2163940045);
pub2163940045.publish<msl_sensor_msgs::CameraSettings>(m2163940045);
break; }
case 3170299750ul: {
msl_sensor_msgs::CameraSettingsRequest m3170299750;
ros::serialization::Serializer<msl_sensor_msgs::CameraSettingsRequest>::read(stream, m3170299750);
pub3170299750.publish<msl_sensor_msgs::CameraSettingsRequest>(m3170299750);
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
			
				default:
					std::cerr << "Cannot find Matching topic:" << id << std::endl;
			}
		}
		catch(std::exception& e) {
			ROS_ERROR_STREAM_THROTTLE(2,"Exception while receiving DDS message:"<<e.what()<< " Discarding message!");
		}
		
	}
	listenForPacket();
	return;
}
void run() {
	io_service.run();
}

int main (int argc, char *argv[])
{
	
	SystemConfig* sc = SystemConfig::getInstance();

	//Configuration *proxyconf = (*sc)["UdpProxy"];
Configuration *proxyconf = (*sc)["ttb_apps"];	
	//std::string port = proxyconf->get<std::string>("UdpProxy","Port",NULL);
	
	std::string baddress = proxyconf->get<std::string>("UdpProxy","MulticastAddress",NULL);
	
	unsigned short port = (unsigned short)proxyconf->get<int>("UdpProxy","Port",NULL);
	
	//udp::resolver resolver(io_service);
    //udp::resolver::query query(udp::v4(), baddress, port);

	//bcastEndPoint = *resolver.resolve(query);
	
	
	
	
	
  
	//myEndPoint = udp::endpoint(udp::v4(),bcastEndPoint.port());
	
	multiCastAddress = boost::asio::ip::address::from_string(baddress);
	destEndPoint = udp::endpoint(multiCastAddress,port);
	
	std::cout<<"Opening to "<<multiCastAddress <<std::endl;
	
	
	
	insocket = new udp::socket(io_service,udp::endpoint(multiCastAddress,port));
	
	insocket->set_option(boost::asio::ip::multicast::enable_loopback(false));
	insocket->set_option(boost::asio::ip::multicast::join_group(multiCastAddress));
	listenForPacket();
	
	
ros::init(argc, argv, "ttb_apps"); //   ros::init(argc, argv, "udpProxy");

    ros::NodeHandle n;
    ownRosName = ros::this_node::getName();//n.getNamespace();//n.resolveName("ddsProxy",true);
    
    std::cout << ownRosName << std::endl;
    
ros::Subscriber sub0 = n.subscribe("/ball",5, onRosPointCloud697841562,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub1 = n.subscribe("/self",5, onRosPointCloud715397477,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub2 = n.subscribe("/amcl_pose",5, onRosPoseWithCovarianceStamped2852345798,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub3 = n.subscribe("/particlecloud",5, onRosPointCloud2644558886,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub4 = n.subscribe("/obstacles",5, onRosPointCloud2242425699,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub5 = n.subscribe("/CNVision/VisionDebug",5, onRosVisionDebug4287086446,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub6 = n.subscribe("/CNVision/VisionControl",5, onRosVisionControl3818207232,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub7 = n.subscribe("/CNVision/VisionImage",5, onRosVisionImage520651946,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub8 = n.subscribe("/KickerStatInfo",5, onRosKickerStatInfo3915861504,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub9 = n.subscribe("/MotionStatInfo",5, onRosMotionStatInfo825806425,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub10 = n.subscribe("/WorldModel/PassMsg",5, onRosPassMsg888918809,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub11 = n.subscribe("/mmTalker",5, onRosString4022577436,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub12 = n.subscribe("/RefereeBoxInfoBody",5, onRosRefBoxCommand1841334100,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub13 = n.subscribe("/Joystick",5, onRosJoystickCommand1506505735,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub14 = n.subscribe("/WorldModel/SharedWorldInfo",5, onRosSharedWorldInfo2791795402,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub15 = n.subscribe("/PathPlanner/PathPlanner",5, onRosPathPlanner709768768,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub16 = n.subscribe("/PathPlanner/VoronoiNet",5, onRosVoronoiNetInfo179313306,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub17 = n.subscribe("/PathPlanner/CorridorCheck",5, onRosCorridorCheck2924935533,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub18 = n.subscribe("/AlicaEngine/PlanTreeInfo",5, onRosPlanTreeInfo3767756765,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub19 = n.subscribe("/AlicaEngine/AlicaEngineInfo",5, onRosAlicaEngineInfo238666206,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub20 = n.subscribe("/AlicaEngine/SyncTalk",5, onRosSyncTalk4175715375,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub21 = n.subscribe("/AlicaEngine/SyncReady",5, onRosSyncReady636345472,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub22 = n.subscribe("/AlicaEngine/AllocationAuthorityInfo",5, onRosAllocationAuthorityInfo690246385,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub23 = n.subscribe("/AlicaEngine/SolverResult",5, onRosSolverResult2276189600,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub24 = n.subscribe("/CNCalibration/CameraSettings",5, onRosCameraSettings2163940045,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub25 = n.subscribe("/CNCalibration/CameraSettingsRequest",5, onRosCameraSettingsRequest3170299750,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub26 = n.subscribe("/process_manager/ProcessCommand",5, onRosProcessCommand3108117629,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub27 = n.subscribe("/process_manager/ProcessStats",5, onRosProcessStats2783514677,ros::TransportHints().unreliable().tcpNoDelay().reliable());
	
pub697841562 = n.advertise<sensor_msgs::PointCloud>("/ball",5,false);
pub715397477 = n.advertise<sensor_msgs::PointCloud>("/self",5,false);
pub2852345798 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/amcl_pose",5,false);
pub2644558886 = n.advertise<sensor_msgs::PointCloud>("/particlecloud",5,false);
pub2242425699 = n.advertise<sensor_msgs::PointCloud>("/obstacles",5,false);
pub4287086446 = n.advertise<msl_sensor_msgs::VisionDebug>("/CNVision/VisionDebug",5,false);
pub3818207232 = n.advertise<msl_sensor_msgs::VisionControl>("/CNVision/VisionControl",5,false);
pub520651946 = n.advertise<msl_sensor_msgs::VisionImage>("/CNVision/VisionImage",5,false);
pub3915861504 = n.advertise<msl_actuator_msgs::KickerStatInfo>("/KickerStatInfo",5,false);
pub825806425 = n.advertise<msl_actuator_msgs::MotionStatInfo>("/MotionStatInfo",5,false);
pub888918809 = n.advertise<msl_helper_msgs::PassMsg>("/WorldModel/PassMsg",5,false);
pub4022577436 = n.advertise<std_msgs::String>("/mmTalker",5,false);
pub1841334100 = n.advertise<msl_msgs::RefBoxCommand>("/RefereeBoxInfoBody",5,false);
pub1506505735 = n.advertise<msl_msgs::JoystickCommand>("/Joystick",5,false);
pub2791795402 = n.advertise<msl_sensor_msgs::SharedWorldInfo>("/WorldModel/SharedWorldInfo",5,false);
pub709768768 = n.advertise<msl_msgs::PathPlanner>("/PathPlanner/PathPlanner",5,false);
pub179313306 = n.advertise<msl_msgs::VoronoiNetInfo>("/PathPlanner/VoronoiNet",5,false);
pub2924935533 = n.advertise<msl_msgs::CorridorCheck>("/PathPlanner/CorridorCheck",5,false);
pub3767756765 = n.advertise<alica_ros_proxy::PlanTreeInfo>("/AlicaEngine/PlanTreeInfo",5,false);
pub238666206 = n.advertise<alica_ros_proxy::AlicaEngineInfo>("/AlicaEngine/AlicaEngineInfo",5,false);
pub4175715375 = n.advertise<alica_ros_proxy::SyncTalk>("/AlicaEngine/SyncTalk",5,false);
pub636345472 = n.advertise<alica_ros_proxy::SyncReady>("/AlicaEngine/SyncReady",5,false);
pub690246385 = n.advertise<alica_ros_proxy::AllocationAuthorityInfo>("/AlicaEngine/AllocationAuthorityInfo",5,false);
pub2276189600 = n.advertise<alica_ros_proxy::SolverResult>("/AlicaEngine/SolverResult",5,false);
pub2163940045 = n.advertise<msl_sensor_msgs::CameraSettings>("/CNCalibration/CameraSettings",5,false);
pub3170299750 = n.advertise<msl_sensor_msgs::CameraSettingsRequest>("/CNCalibration/CameraSettingsRequest",5,false);
pub3108117629 = n.advertise<process_manager::ProcessCommand>("/process_manager/ProcessCommand",5,false);
pub2783514677 = n.advertise<process_manager::ProcessStats>("/process_manager/ProcessStats",5,false);
	
	boost::thread iothread(run);
    
    //ros::spin();
	ros::AsyncSpinner *spinner;
	
	spinner = new ros::AsyncSpinner(4);
	spinner->start();
	
	std::cout << "Ros2Udp Proxy running..." <<std::endl;
    while(n.ok()) {
	    usleep(300000);
    }
    io_service.stop();
    iothread.join();
    return 0;
}


