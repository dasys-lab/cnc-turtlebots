
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


import geometry_msgs.PoseWithCovarianceStamped;
import geometry_msgs.PoseArray;
import std_msgs.String;
import alica_ros_proxy.PlanTreeInfo;

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



	private class OnRosPoseWithCovarianceStamped2852345798Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		PoseWithCovarianceStamped converted = (PoseWithCovarianceStamped) o;
		MessageSerializer<PoseWithCovarianceStamped> serializer = node.getMessageSerializationFactory().newMessageSerializer("geometry_msgs/PoseWithCovarianceStamped");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 2852345798l);
		ChannelBuffer finalBuf = ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN, idBuf.array(), buffer.array());
		try {
			MulticastSocket socket = new MulticastSocket();
			socket.send(new DatagramPacket(finalBuf.array(),finalBuf.array().length,group,port));
			socket.close();
		} catch (IOException e) {
			System.err.println("Exception while sending UDP message:" + converted._TYPE + " Discarding message!");
		}

	}
	}

	private class OnRosPoseArray2644558886Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		PoseArray converted = (PoseArray) o;
		MessageSerializer<PoseArray> serializer = node.getMessageSerializationFactory().newMessageSerializer("geometry_msgs/PoseArray");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 2644558886l);
		ChannelBuffer finalBuf = ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN, idBuf.array(), buffer.array());
		try {
			MulticastSocket socket = new MulticastSocket();
			socket.send(new DatagramPacket(finalBuf.array(),finalBuf.array().length,group,port));
			socket.close();
		} catch (IOException e) {
			System.err.println("Exception while sending UDP message:" + converted._TYPE + " Discarding message!");
		}

	}
	}

	private class OnRosString4022577436Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		String converted = (String) o;
		MessageSerializer<String> serializer = node.getMessageSerializationFactory().newMessageSerializer("std_msgs/String");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 4022577436l);
		ChannelBuffer finalBuf = ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN, idBuf.array(), buffer.array());
		try {
			MulticastSocket socket = new MulticastSocket();
			socket.send(new DatagramPacket(finalBuf.array(),finalBuf.array().length,group,port));
			socket.close();
		} catch (IOException e) {
			System.err.println("Exception while sending UDP message:" + converted._TYPE + " Discarding message!");
		}

	}
	}

	private class OnRosPlanTreeInfo3767756765Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		PlanTreeInfo converted = (PlanTreeInfo) o;
		MessageSerializer<PlanTreeInfo> serializer = node.getMessageSerializationFactory().newMessageSerializer("alica_ros_proxy/PlanTreeInfo");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 3767756765l);
		ChannelBuffer finalBuf = ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN, idBuf.array(), buffer.array());
		try {
			MulticastSocket socket = new MulticastSocket();
			socket.send(new DatagramPacket(finalBuf.array(),finalBuf.array().length,group,port));
			socket.close();
		} catch (IOException e) {
			System.err.println("Exception while sending UDP message:" + converted._TYPE + " Discarding message!");
		}

	}
	}


private Publisher<PoseWithCovarianceStamped> pub2852345798;
private Publisher<PoseArray> pub2644558886;
private Publisher<String> pub4022577436;
private Publisher<PlanTreeInfo> pub3767756765;

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
if(id == 2852345798l) {
MessageDeserializer<PoseWithCovarianceStamped> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(PoseWithCovarianceStamped._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
PoseWithCovarianceStamped m2852345798 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub2852345798.publish(m2852345798);
}
else if(id == 2644558886l) {
MessageDeserializer<PoseArray> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(PoseArray._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
PoseArray m2644558886 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub2644558886.publish(m2644558886);
}
else if(id == 4022577436l) {
MessageDeserializer<String> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(String._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
String m4022577436 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub4022577436.publish(m4022577436);
}
else if(id == 3767756765l) {
MessageDeserializer<PlanTreeInfo> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(PlanTreeInfo._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
PlanTreeInfo m3767756765 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub3767756765.publish(m3767756765);
}
			
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
udpConfig.load(getActivity().getResources().openRawResource(R.raw.ttb_apps));
	
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
	
	
 //   ros::init(argc, argv, "udpProxy");

    ros::NodeHandle n;
    ownRosName = ros::this_node::getName();//n.getNamespace();//n.resolveName("ddsProxy",true);
    
    std::cout << ownRosName << std::endl;
    
final Subscriber sub0 = connectedNode.newSubscriber("/amcl_pose", "geometry_msgs/PoseWithCovarianceStamped");
sub0.addMessageListener(new OnRosPoseWithCovarianceStamped2852345798Listener());
final Subscriber sub1 = connectedNode.newSubscriber("/particlecloud", "geometry_msgs/PoseArray");
sub1.addMessageListener(new OnRosPoseArray2644558886Listener());
final Subscriber sub2 = connectedNode.newSubscriber("/mmTalker", "std_msgs/String");
sub2.addMessageListener(new OnRosString4022577436Listener());
final Subscriber sub3 = connectedNode.newSubscriber("/AlicaEngine/PlanTreeInfo", "alica_ros_proxy/PlanTreeInfo");
sub3.addMessageListener(new OnRosPlanTreeInfo3767756765Listener());
	
pub2852345798 = connectedNode.newPublisher("/amcl_pose", "geometry_msgs/PoseWithCovarianceStamped");
pub2644558886 = connectedNode.newPublisher("/particlecloud", "geometry_msgs/PoseArray");
pub4022577436 = connectedNode.newPublisher("/mmTalker", "std_msgs/String");
pub3767756765 = connectedNode.newPublisher("/AlicaEngine/PlanTreeInfo", "alica_ros_proxy/PlanTreeInfo");
	
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


