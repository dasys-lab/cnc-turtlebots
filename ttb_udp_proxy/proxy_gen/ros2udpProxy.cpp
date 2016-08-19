
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
#include "visualization_msgs/Marker.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "nav_msgs/OccupancyGrid.h"
#include "tf2_msgs/TFMessage.h"
#include "visualization_msgs/Marker.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "nav_msgs/OccupancyGrid.h"
#include "tf2_msgs/TFMessage.h"

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
void onRosOccupancyGrid1773545984(const ros::MessageEvent<nav_msgs::OccupancyGrid>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const nav_msgs::OccupancyGrid::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 1773545984u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosTFMessage3547088152(const ros::MessageEvent<tf2_msgs::TFMessage>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const tf2_msgs::TFMessage::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3547088152u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosMarker3651293756(const ros::MessageEvent<visualization_msgs::Marker>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const visualization_msgs::Marker::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3651293756u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseWithCovarianceStamped2944150132(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2944150132u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseStamped3380041709(const ros::MessageEvent<geometry_msgs::PoseStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3380041709u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseWithCovarianceStamped2830842050(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2830842050u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosOccupancyGrid3354647595(const ros::MessageEvent<nav_msgs::OccupancyGrid>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const nav_msgs::OccupancyGrid::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3354647595u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosTFMessage1011276903(const ros::MessageEvent<tf2_msgs::TFMessage>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const tf2_msgs::TFMessage::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 1011276903u;
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
ros::Publisher pub52450053;
ros::Publisher pub3236539441;
ros::Publisher pub674080570;
ros::Publisher pub491912439;
ros::Publisher pub1773545984;
ros::Publisher pub3547088152;
ros::Publisher pub3651293756;
ros::Publisher pub2944150132;
ros::Publisher pub3380041709;
ros::Publisher pub2830842050;
ros::Publisher pub3354647595;
ros::Publisher pub1011276903;

boost::array<char,64000> inBuffer;
void listenForPacket() {
	insocket->async_receive_from(boost::asio::buffer(inBuffer), otherEndPoint,
        boost::bind(&handleUdpPacket, boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
}
void handleUdpPacket(const boost::system::error_code& error,   std::size_t bytes_transferred) {
	//std::cout << "From "<<otherEndPoint.address() << std::endl;
	if (bytes_transferred > 64000) {
		return;
	}
	if (!error) { // && otherEndPoint.address() != localIP) {
		__uint32_t id = *((__uint32_t*)(inBuffer.data()));
		//std::cout << "Got packet"<<std::endl;
		try {	
			ros::serialization::IStream stream(((uint8_t*)inBuffer.data())+sizeof(__uint32_t),bytes_transferred-sizeof(__uint32_t));
			switch(id) {
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
case 1773545984ul: {
nav_msgs::OccupancyGrid m1773545984;
ros::serialization::Serializer<nav_msgs::OccupancyGrid>::read(stream, m1773545984);
pub1773545984.publish<nav_msgs::OccupancyGrid>(m1773545984);
break; }
case 3547088152ul: {
tf2_msgs::TFMessage m3547088152;
ros::serialization::Serializer<tf2_msgs::TFMessage>::read(stream, m3547088152);
pub3547088152.publish<tf2_msgs::TFMessage>(m3547088152);
break; }
case 3651293756ul: {
visualization_msgs::Marker m3651293756;
ros::serialization::Serializer<visualization_msgs::Marker>::read(stream, m3651293756);
pub3651293756.publish<visualization_msgs::Marker>(m3651293756);
break; }
case 2944150132ul: {
geometry_msgs::PoseWithCovarianceStamped m2944150132;
ros::serialization::Serializer<geometry_msgs::PoseWithCovarianceStamped>::read(stream, m2944150132);
pub2944150132.publish<geometry_msgs::PoseWithCovarianceStamped>(m2944150132);
break; }
case 3380041709ul: {
geometry_msgs::PoseStamped m3380041709;
ros::serialization::Serializer<geometry_msgs::PoseStamped>::read(stream, m3380041709);
pub3380041709.publish<geometry_msgs::PoseStamped>(m3380041709);
break; }
case 2830842050ul: {
geometry_msgs::PoseWithCovarianceStamped m2830842050;
ros::serialization::Serializer<geometry_msgs::PoseWithCovarianceStamped>::read(stream, m2830842050);
pub2830842050.publish<geometry_msgs::PoseWithCovarianceStamped>(m2830842050);
break; }
case 3354647595ul: {
nav_msgs::OccupancyGrid m3354647595;
ros::serialization::Serializer<nav_msgs::OccupancyGrid>::read(stream, m3354647595);
pub3354647595.publish<nav_msgs::OccupancyGrid>(m3354647595);
break; }
case 1011276903ul: {
tf2_msgs::TFMessage m1011276903;
ros::serialization::Serializer<tf2_msgs::TFMessage>::read(stream, m1011276903);
pub1011276903.publish<tf2_msgs::TFMessage>(m1011276903);
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
Configuration *proxyconf = (*sc)["ttb_udp_proxy"];	
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
	
	
ros::init(argc, argv, "ttb_udp_proxy"); //   ros::init(argc, argv, "udpProxy");

    ros::NodeHandle n;
    ownRosName = ros::this_node::getName();//n.getNamespace();//n.resolveName("ddsProxy",true);
    
    std::cout << ownRosName << std::endl;
    
ros::Subscriber sub0 = n.subscribe("/AlicaEngine/PlanTreeInfo",5, onRosPlanTreeInfo3767756765,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub1 = n.subscribe("/process_manager/ProcessCommand",5, onRosProcessCommand3108117629,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub2 = n.subscribe("/process_manager/ProcessStats",5, onRosProcessStats2783514677,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub3 = n.subscribe("/wrapped/amcl_pose",5, onRosAMCLPoseWrapped2611391888,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub4 = n.subscribe("/wrapped/move_base_simple/goal",5, onRosGoalWrapped3867808201,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub5 = n.subscribe("/wrapped/initialpose",5, onRosInitialPoseWrapped1388158846,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub6 = n.subscribe("/leonardo/visualization_marker",5, onRosMarker52450053,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub7 = n.subscribe("/leonardo/amcl_pose",5, onRosPoseWithCovarianceStamped3236539441,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub8 = n.subscribe("/leonardo/move_base_simple/goal",5, onRosPoseStamped674080570,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub9 = n.subscribe("/leonardo/initialpose",5, onRosPoseWithCovarianceStamped491912439,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub10 = n.subscribe("/leonardo/map",5, onRosOccupancyGrid1773545984,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub11 = n.subscribe("/leonardo/tf",5, onRosTFMessage3547088152,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub12 = n.subscribe("/rafael/visualization_marker",5, onRosMarker3651293756,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub13 = n.subscribe("/rafael/amcl_pose",5, onRosPoseWithCovarianceStamped2944150132,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub14 = n.subscribe("/rafael/move_base_simple/goal",5, onRosPoseStamped3380041709,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub15 = n.subscribe("/rafael/initialpose",5, onRosPoseWithCovarianceStamped2830842050,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub16 = n.subscribe("/rafael/map",5, onRosOccupancyGrid3354647595,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub17 = n.subscribe("/rafael/tf",5, onRosTFMessage1011276903,ros::TransportHints().unreliable().tcpNoDelay().reliable());
	
pub3767756765 = n.advertise<alica_ros_proxy::PlanTreeInfo>("/AlicaEngine/PlanTreeInfo",5,false);
pub3108117629 = n.advertise<process_manager::ProcessCommand>("/process_manager/ProcessCommand",5,false);
pub2783514677 = n.advertise<process_manager::ProcessStats>("/process_manager/ProcessStats",5,false);
pub2611391888 = n.advertise<ttb_msgs::AMCLPoseWrapped>("/wrapped/amcl_pose",5,false);
pub3867808201 = n.advertise<ttb_msgs::GoalWrapped>("/wrapped/move_base_simple/goal",5,false);
pub1388158846 = n.advertise<ttb_msgs::InitialPoseWrapped>("/wrapped/initialpose",5,false);
pub52450053 = n.advertise<visualization_msgs::Marker>("/leonardo/visualization_marker",5,false);
pub3236539441 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/leonardo/amcl_pose",5,false);
pub674080570 = n.advertise<geometry_msgs::PoseStamped>("/leonardo/move_base_simple/goal",5,false);
pub491912439 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/leonardo/initialpose",5,false);
pub1773545984 = n.advertise<nav_msgs::OccupancyGrid>("/leonardo/map",5,false);
pub3547088152 = n.advertise<tf2_msgs::TFMessage>("/leonardo/tf",5,false);
pub3651293756 = n.advertise<visualization_msgs::Marker>("/rafael/visualization_marker",5,false);
pub2944150132 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/rafael/amcl_pose",5,false);
pub3380041709 = n.advertise<geometry_msgs::PoseStamped>("/rafael/move_base_simple/goal",5,false);
pub2830842050 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/rafael/initialpose",5,false);
pub3354647595 = n.advertise<nav_msgs::OccupancyGrid>("/rafael/map",5,false);
pub1011276903 = n.advertise<tf2_msgs::TFMessage>("/rafael/tf",5,false);
	
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


