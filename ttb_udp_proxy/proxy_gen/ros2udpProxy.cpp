
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
#include "alica_ros_proxy/AlicaEngineInfo.h"
#include "alica_ros_proxy/SyncTalk.h"
#include "alica_ros_proxy/SyncReady.h"
#include "alica_ros_proxy/AllocationAuthorityInfo.h"
#include "alica_ros_proxy/SolverResult.h"
#include "process_manager/ProcessCommand.h"
#include "process_manager/ProcessStats.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "sensor_msgs/PointCloud.h"

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

ros::Publisher pub3767756765;
ros::Publisher pub238666206;
ros::Publisher pub4175715375;
ros::Publisher pub636345472;
ros::Publisher pub690246385;
ros::Publisher pub2276189600;
ros::Publisher pub3108117629;
ros::Publisher pub2783514677;
ros::Publisher pub2852345798;
ros::Publisher pub2242425699;

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
case 2852345798ul: {
geometry_msgs::PoseWithCovarianceStamped m2852345798;
ros::serialization::Serializer<geometry_msgs::PoseWithCovarianceStamped>::read(stream, m2852345798);
pub2852345798.publish<geometry_msgs::PoseWithCovarianceStamped>(m2852345798);
break; }
case 2242425699ul: {
sensor_msgs::PointCloud m2242425699;
ros::serialization::Serializer<sensor_msgs::PointCloud>::read(stream, m2242425699);
pub2242425699.publish<sensor_msgs::PointCloud>(m2242425699);
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
ros::Subscriber sub1 = n.subscribe("/AlicaEngine/AlicaEngineInfo",5, onRosAlicaEngineInfo238666206,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub2 = n.subscribe("/AlicaEngine/SyncTalk",5, onRosSyncTalk4175715375,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub3 = n.subscribe("/AlicaEngine/SyncReady",5, onRosSyncReady636345472,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub4 = n.subscribe("/AlicaEngine/AllocationAuthorityInfo",5, onRosAllocationAuthorityInfo690246385,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub5 = n.subscribe("/AlicaEngine/SolverResult",5, onRosSolverResult2276189600,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub6 = n.subscribe("/process_manager/ProcessCommand",5, onRosProcessCommand3108117629,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub7 = n.subscribe("/process_manager/ProcessStats",5, onRosProcessStats2783514677,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub8 = n.subscribe("/amcl_pose",5, onRosPoseWithCovarianceStamped2852345798,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub9 = n.subscribe("/obstacles",5, onRosPointCloud2242425699,ros::TransportHints().unreliable().tcpNoDelay().reliable());
	
pub3767756765 = n.advertise<alica_ros_proxy::PlanTreeInfo>("/AlicaEngine/PlanTreeInfo",5,false);
pub238666206 = n.advertise<alica_ros_proxy::AlicaEngineInfo>("/AlicaEngine/AlicaEngineInfo",5,false);
pub4175715375 = n.advertise<alica_ros_proxy::SyncTalk>("/AlicaEngine/SyncTalk",5,false);
pub636345472 = n.advertise<alica_ros_proxy::SyncReady>("/AlicaEngine/SyncReady",5,false);
pub690246385 = n.advertise<alica_ros_proxy::AllocationAuthorityInfo>("/AlicaEngine/AllocationAuthorityInfo",5,false);
pub2276189600 = n.advertise<alica_ros_proxy::SolverResult>("/AlicaEngine/SolverResult",5,false);
pub3108117629 = n.advertise<process_manager::ProcessCommand>("/process_manager/ProcessCommand",5,false);
pub2783514677 = n.advertise<process_manager::ProcessStats>("/process_manager/ProcessStats",5,false);
pub2852345798 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/amcl_pose",5,false);
pub2242425699 = n.advertise<sensor_msgs::PointCloud>("/obstacles",5,false);
	
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


