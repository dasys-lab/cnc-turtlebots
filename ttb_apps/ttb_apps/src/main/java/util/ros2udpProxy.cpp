
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


import sensor_msgs.PointCloud;
import sensor_msgs.PointCloud;
import geometry_msgs.PoseWithCovarianceStamped;
import geometry_msgs.PoseArray;
import sensor_msgs.PointCloud;
import msl_sensor_msgs.VisionDebug;
import msl_sensor_msgs.VisionControl;
import msl_sensor_msgs.VisionImage;
import msl_actuator_msgs.KickerStatInfo;
import msl_actuator_msgs.MotionStatInfo;
import msl_helper_msgs.PassMsg;
import std_msgs.String;
import msl_msgs.RefBoxCommand;
import msl_msgs.JoystickCommand;
import msl_sensor_msgs.SharedWorldInfo;
import msl_msgs.PathPlanner;
import msl_msgs.VoronoiNetInfo;
import msl_msgs.CorridorCheck;
import alica_ros_proxy.PlanTreeInfo;
import alica_ros_proxy.AlicaEngineInfo;
import alica_ros_proxy.SyncTalk;
import alica_ros_proxy.SyncReady;
import alica_ros_proxy.AllocationAuthorityInfo;
import alica_ros_proxy.SolverResult;
import msl_sensor_msgs.CameraSettings;
import msl_sensor_msgs.CameraSettingsRequest;
import process_manager.ProcessCommand;
import process_manager.ProcessStats;

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



	private class OnRosPointCloud697841562Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		PointCloud converted = (PointCloud) o;
		MessageSerializer<PointCloud> serializer = node.getMessageSerializationFactory().newMessageSerializer("sensor_msgs/PointCloud");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 697841562l);
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

	private class OnRosPointCloud715397477Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		PointCloud converted = (PointCloud) o;
		MessageSerializer<PointCloud> serializer = node.getMessageSerializationFactory().newMessageSerializer("sensor_msgs/PointCloud");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 715397477l);
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

	private class OnRosPointCloud2242425699Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		PointCloud converted = (PointCloud) o;
		MessageSerializer<PointCloud> serializer = node.getMessageSerializationFactory().newMessageSerializer("sensor_msgs/PointCloud");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 2242425699l);
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

	private class OnRosVisionDebug4287086446Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		VisionDebug converted = (VisionDebug) o;
		MessageSerializer<VisionDebug> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_sensor_msgs/VisionDebug");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 4287086446l);
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

	private class OnRosVisionControl3818207232Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		VisionControl converted = (VisionControl) o;
		MessageSerializer<VisionControl> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_sensor_msgs/VisionControl");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 3818207232l);
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

	private class OnRosVisionImage520651946Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		VisionImage converted = (VisionImage) o;
		MessageSerializer<VisionImage> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_sensor_msgs/VisionImage");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 520651946l);
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

	private class OnRosKickerStatInfo3915861504Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		KickerStatInfo converted = (KickerStatInfo) o;
		MessageSerializer<KickerStatInfo> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_actuator_msgs/KickerStatInfo");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 3915861504l);
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

	private class OnRosMotionStatInfo825806425Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		MotionStatInfo converted = (MotionStatInfo) o;
		MessageSerializer<MotionStatInfo> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_actuator_msgs/MotionStatInfo");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 825806425l);
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

	private class OnRosPassMsg888918809Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		PassMsg converted = (PassMsg) o;
		MessageSerializer<PassMsg> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_helper_msgs/PassMsg");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 888918809l);
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

	private class OnRosRefBoxCommand1841334100Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		RefBoxCommand converted = (RefBoxCommand) o;
		MessageSerializer<RefBoxCommand> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_msgs/RefBoxCommand");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 1841334100l);
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

	private class OnRosJoystickCommand1506505735Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		JoystickCommand converted = (JoystickCommand) o;
		MessageSerializer<JoystickCommand> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_msgs/JoystickCommand");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 1506505735l);
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

	private class OnRosSharedWorldInfo2791795402Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		SharedWorldInfo converted = (SharedWorldInfo) o;
		MessageSerializer<SharedWorldInfo> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_sensor_msgs/SharedWorldInfo");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 2791795402l);
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

	private class OnRosPathPlanner709768768Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		PathPlanner converted = (PathPlanner) o;
		MessageSerializer<PathPlanner> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_msgs/PathPlanner");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 709768768l);
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

	private class OnRosVoronoiNetInfo179313306Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		VoronoiNetInfo converted = (VoronoiNetInfo) o;
		MessageSerializer<VoronoiNetInfo> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_msgs/VoronoiNetInfo");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 179313306l);
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

	private class OnRosCorridorCheck2924935533Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		CorridorCheck converted = (CorridorCheck) o;
		MessageSerializer<CorridorCheck> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_msgs/CorridorCheck");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 2924935533l);
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

	private class OnRosAlicaEngineInfo238666206Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		AlicaEngineInfo converted = (AlicaEngineInfo) o;
		MessageSerializer<AlicaEngineInfo> serializer = node.getMessageSerializationFactory().newMessageSerializer("alica_ros_proxy/AlicaEngineInfo");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 238666206l);
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

	private class OnRosSyncTalk4175715375Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		SyncTalk converted = (SyncTalk) o;
		MessageSerializer<SyncTalk> serializer = node.getMessageSerializationFactory().newMessageSerializer("alica_ros_proxy/SyncTalk");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 4175715375l);
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

	private class OnRosSyncReady636345472Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		SyncReady converted = (SyncReady) o;
		MessageSerializer<SyncReady> serializer = node.getMessageSerializationFactory().newMessageSerializer("alica_ros_proxy/SyncReady");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 636345472l);
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

	private class OnRosAllocationAuthorityInfo690246385Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		AllocationAuthorityInfo converted = (AllocationAuthorityInfo) o;
		MessageSerializer<AllocationAuthorityInfo> serializer = node.getMessageSerializationFactory().newMessageSerializer("alica_ros_proxy/AllocationAuthorityInfo");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 690246385l);
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

	private class OnRosSolverResult2276189600Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		SolverResult converted = (SolverResult) o;
		MessageSerializer<SolverResult> serializer = node.getMessageSerializationFactory().newMessageSerializer("alica_ros_proxy/SolverResult");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 2276189600l);
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

	private class OnRosCameraSettings2163940045Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		CameraSettings converted = (CameraSettings) o;
		MessageSerializer<CameraSettings> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_sensor_msgs/CameraSettings");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 2163940045l);
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

	private class OnRosCameraSettingsRequest3170299750Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		CameraSettingsRequest converted = (CameraSettingsRequest) o;
		MessageSerializer<CameraSettingsRequest> serializer = node.getMessageSerializationFactory().newMessageSerializer("msl_sensor_msgs/CameraSettingsRequest");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 3170299750l);
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

	private class OnRosProcessCommand3108117629Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		ProcessCommand converted = (ProcessCommand) o;
		MessageSerializer<ProcessCommand> serializer = node.getMessageSerializationFactory().newMessageSerializer("process_manager/ProcessCommand");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 3108117629l);
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

	private class OnRosProcessStats2783514677Listener implements MessageListener {
	@Override
public void onNewMessage(Object o) {
		ProcessStats converted = (ProcessStats) o;
		MessageSerializer<ProcessStats> serializer = node.getMessageSerializationFactory().newMessageSerializer("process_manager/ProcessStats");
		ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
		serializer.serialize(converted,buffer);
		ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 2783514677l);
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


private Publisher<PointCloud> pub697841562;
private Publisher<PointCloud> pub715397477;
private Publisher<PoseWithCovarianceStamped> pub2852345798;
private Publisher<PoseArray> pub2644558886;
private Publisher<PointCloud> pub2242425699;
private Publisher<VisionDebug> pub4287086446;
private Publisher<VisionControl> pub3818207232;
private Publisher<VisionImage> pub520651946;
private Publisher<KickerStatInfo> pub3915861504;
private Publisher<MotionStatInfo> pub825806425;
private Publisher<PassMsg> pub888918809;
private Publisher<String> pub4022577436;
private Publisher<RefBoxCommand> pub1841334100;
private Publisher<JoystickCommand> pub1506505735;
private Publisher<SharedWorldInfo> pub2791795402;
private Publisher<PathPlanner> pub709768768;
private Publisher<VoronoiNetInfo> pub179313306;
private Publisher<CorridorCheck> pub2924935533;
private Publisher<PlanTreeInfo> pub3767756765;
private Publisher<AlicaEngineInfo> pub238666206;
private Publisher<SyncTalk> pub4175715375;
private Publisher<SyncReady> pub636345472;
private Publisher<AllocationAuthorityInfo> pub690246385;
private Publisher<SolverResult> pub2276189600;
private Publisher<CameraSettings> pub2163940045;
private Publisher<CameraSettingsRequest> pub3170299750;
private Publisher<ProcessCommand> pub3108117629;
private Publisher<ProcessStats> pub2783514677;

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
if(id == 697841562l) {
MessageDeserializer<PointCloud> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(PointCloud._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
PointCloud m697841562 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub697841562.publish(m697841562);
}
else if(id == 715397477l) {
MessageDeserializer<PointCloud> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(PointCloud._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
PointCloud m715397477 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub715397477.publish(m715397477);
}
else if(id == 2852345798l) {
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
else if(id == 2242425699l) {
MessageDeserializer<PointCloud> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(PointCloud._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
PointCloud m2242425699 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub2242425699.publish(m2242425699);
}
else if(id == 4287086446l) {
MessageDeserializer<VisionDebug> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(VisionDebug._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
VisionDebug m4287086446 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub4287086446.publish(m4287086446);
}
else if(id == 3818207232l) {
MessageDeserializer<VisionControl> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(VisionControl._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
VisionControl m3818207232 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub3818207232.publish(m3818207232);
}
else if(id == 520651946l) {
MessageDeserializer<VisionImage> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(VisionImage._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
VisionImage m520651946 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub520651946.publish(m520651946);
}
else if(id == 3915861504l) {
MessageDeserializer<KickerStatInfo> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(KickerStatInfo._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
KickerStatInfo m3915861504 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub3915861504.publish(m3915861504);
}
else if(id == 825806425l) {
MessageDeserializer<MotionStatInfo> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(MotionStatInfo._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
MotionStatInfo m825806425 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub825806425.publish(m825806425);
}
else if(id == 888918809l) {
MessageDeserializer<PassMsg> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(PassMsg._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
PassMsg m888918809 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub888918809.publish(m888918809);
}
else if(id == 4022577436l) {
MessageDeserializer<String> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(String._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
String m4022577436 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub4022577436.publish(m4022577436);
}
else if(id == 1841334100l) {
MessageDeserializer<RefBoxCommand> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(RefBoxCommand._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
RefBoxCommand m1841334100 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub1841334100.publish(m1841334100);
}
else if(id == 1506505735l) {
MessageDeserializer<JoystickCommand> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(JoystickCommand._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
JoystickCommand m1506505735 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub1506505735.publish(m1506505735);
}
else if(id == 2791795402l) {
MessageDeserializer<SharedWorldInfo> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(SharedWorldInfo._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
SharedWorldInfo m2791795402 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub2791795402.publish(m2791795402);
}
else if(id == 709768768l) {
MessageDeserializer<PathPlanner> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(PathPlanner._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
PathPlanner m709768768 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub709768768.publish(m709768768);
}
else if(id == 179313306l) {
MessageDeserializer<VoronoiNetInfo> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(VoronoiNetInfo._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
VoronoiNetInfo m179313306 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub179313306.publish(m179313306);
}
else if(id == 2924935533l) {
MessageDeserializer<CorridorCheck> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(CorridorCheck._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
CorridorCheck m2924935533 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub2924935533.publish(m2924935533);
}
else if(id == 3767756765l) {
MessageDeserializer<PlanTreeInfo> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(PlanTreeInfo._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
PlanTreeInfo m3767756765 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub3767756765.publish(m3767756765);
}
else if(id == 238666206l) {
MessageDeserializer<AlicaEngineInfo> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(AlicaEngineInfo._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
AlicaEngineInfo m238666206 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub238666206.publish(m238666206);
}
else if(id == 4175715375l) {
MessageDeserializer<SyncTalk> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(SyncTalk._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
SyncTalk m4175715375 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub4175715375.publish(m4175715375);
}
else if(id == 636345472l) {
MessageDeserializer<SyncReady> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(SyncReady._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
SyncReady m636345472 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub636345472.publish(m636345472);
}
else if(id == 690246385l) {
MessageDeserializer<AllocationAuthorityInfo> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(AllocationAuthorityInfo._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
AllocationAuthorityInfo m690246385 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub690246385.publish(m690246385);
}
else if(id == 2276189600l) {
MessageDeserializer<SolverResult> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(SolverResult._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
SolverResult m2276189600 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub2276189600.publish(m2276189600);
}
else if(id == 2163940045l) {
MessageDeserializer<CameraSettings> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(CameraSettings._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
CameraSettings m2163940045 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub2163940045.publish(m2163940045);
}
else if(id == 3170299750l) {
MessageDeserializer<CameraSettingsRequest> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(CameraSettingsRequest._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
CameraSettingsRequest m3170299750 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub3170299750.publish(m3170299750);
}
else if(id == 3108117629l) {
MessageDeserializer<ProcessCommand> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(ProcessCommand._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
ProcessCommand m3108117629 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub3108117629.publish(m3108117629);
}
else if(id == 2783514677l) {
MessageDeserializer<ProcessStats> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(ProcessStats._TYPE);
byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
ProcessStats m2783514677 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
pub2783514677.publish(m2783514677);
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
    
final Subscriber sub0 = connectedNode.newSubscriber("/ball", "sensor_msgs/PointCloud");
sub0.addMessageListener(new OnRosPointCloud697841562Listener());
final Subscriber sub1 = connectedNode.newSubscriber("/self", "sensor_msgs/PointCloud");
sub1.addMessageListener(new OnRosPointCloud715397477Listener());
final Subscriber sub2 = connectedNode.newSubscriber("/amcl_pose", "geometry_msgs/PoseWithCovarianceStamped");
sub2.addMessageListener(new OnRosPoseWithCovarianceStamped2852345798Listener());
final Subscriber sub3 = connectedNode.newSubscriber("/particlecloud", "geometry_msgs/PoseArray");
sub3.addMessageListener(new OnRosPoseArray2644558886Listener());
final Subscriber sub4 = connectedNode.newSubscriber("/obstacles", "sensor_msgs/PointCloud");
sub4.addMessageListener(new OnRosPointCloud2242425699Listener());
final Subscriber sub5 = connectedNode.newSubscriber("/CNVision/VisionDebug", "msl_sensor_msgs/VisionDebug");
sub5.addMessageListener(new OnRosVisionDebug4287086446Listener());
final Subscriber sub6 = connectedNode.newSubscriber("/CNVision/VisionControl", "msl_sensor_msgs/VisionControl");
sub6.addMessageListener(new OnRosVisionControl3818207232Listener());
final Subscriber sub7 = connectedNode.newSubscriber("/CNVision/VisionImage", "msl_sensor_msgs/VisionImage");
sub7.addMessageListener(new OnRosVisionImage520651946Listener());
final Subscriber sub8 = connectedNode.newSubscriber("/KickerStatInfo", "msl_actuator_msgs/KickerStatInfo");
sub8.addMessageListener(new OnRosKickerStatInfo3915861504Listener());
final Subscriber sub9 = connectedNode.newSubscriber("/MotionStatInfo", "msl_actuator_msgs/MotionStatInfo");
sub9.addMessageListener(new OnRosMotionStatInfo825806425Listener());
final Subscriber sub10 = connectedNode.newSubscriber("/WorldModel/PassMsg", "msl_helper_msgs/PassMsg");
sub10.addMessageListener(new OnRosPassMsg888918809Listener());
final Subscriber sub11 = connectedNode.newSubscriber("/mmTalker", "std_msgs/String");
sub11.addMessageListener(new OnRosString4022577436Listener());
final Subscriber sub12 = connectedNode.newSubscriber("/RefereeBoxInfoBody", "msl_msgs/RefBoxCommand");
sub12.addMessageListener(new OnRosRefBoxCommand1841334100Listener());
final Subscriber sub13 = connectedNode.newSubscriber("/Joystick", "msl_msgs/JoystickCommand");
sub13.addMessageListener(new OnRosJoystickCommand1506505735Listener());
final Subscriber sub14 = connectedNode.newSubscriber("/WorldModel/SharedWorldInfo", "msl_sensor_msgs/SharedWorldInfo");
sub14.addMessageListener(new OnRosSharedWorldInfo2791795402Listener());
final Subscriber sub15 = connectedNode.newSubscriber("/PathPlanner/PathPlanner", "msl_msgs/PathPlanner");
sub15.addMessageListener(new OnRosPathPlanner709768768Listener());
final Subscriber sub16 = connectedNode.newSubscriber("/PathPlanner/VoronoiNet", "msl_msgs/VoronoiNetInfo");
sub16.addMessageListener(new OnRosVoronoiNetInfo179313306Listener());
final Subscriber sub17 = connectedNode.newSubscriber("/PathPlanner/CorridorCheck", "msl_msgs/CorridorCheck");
sub17.addMessageListener(new OnRosCorridorCheck2924935533Listener());
final Subscriber sub18 = connectedNode.newSubscriber("/AlicaEngine/PlanTreeInfo", "alica_ros_proxy/PlanTreeInfo");
sub18.addMessageListener(new OnRosPlanTreeInfo3767756765Listener());
final Subscriber sub19 = connectedNode.newSubscriber("/AlicaEngine/AlicaEngineInfo", "alica_ros_proxy/AlicaEngineInfo");
sub19.addMessageListener(new OnRosAlicaEngineInfo238666206Listener());
final Subscriber sub20 = connectedNode.newSubscriber("/AlicaEngine/SyncTalk", "alica_ros_proxy/SyncTalk");
sub20.addMessageListener(new OnRosSyncTalk4175715375Listener());
final Subscriber sub21 = connectedNode.newSubscriber("/AlicaEngine/SyncReady", "alica_ros_proxy/SyncReady");
sub21.addMessageListener(new OnRosSyncReady636345472Listener());
final Subscriber sub22 = connectedNode.newSubscriber("/AlicaEngine/AllocationAuthorityInfo", "alica_ros_proxy/AllocationAuthorityInfo");
sub22.addMessageListener(new OnRosAllocationAuthorityInfo690246385Listener());
final Subscriber sub23 = connectedNode.newSubscriber("/AlicaEngine/SolverResult", "alica_ros_proxy/SolverResult");
sub23.addMessageListener(new OnRosSolverResult2276189600Listener());
final Subscriber sub24 = connectedNode.newSubscriber("/CNCalibration/CameraSettings", "msl_sensor_msgs/CameraSettings");
sub24.addMessageListener(new OnRosCameraSettings2163940045Listener());
final Subscriber sub25 = connectedNode.newSubscriber("/CNCalibration/CameraSettingsRequest", "msl_sensor_msgs/CameraSettingsRequest");
sub25.addMessageListener(new OnRosCameraSettingsRequest3170299750Listener());
final Subscriber sub26 = connectedNode.newSubscriber("/process_manager/ProcessCommand", "process_manager/ProcessCommand");
sub26.addMessageListener(new OnRosProcessCommand3108117629Listener());
final Subscriber sub27 = connectedNode.newSubscriber("/process_manager/ProcessStats", "process_manager/ProcessStats");
sub27.addMessageListener(new OnRosProcessStats2783514677Listener());
	
pub697841562 = connectedNode.newPublisher("/ball", "sensor_msgs/PointCloud");
pub715397477 = connectedNode.newPublisher("/self", "sensor_msgs/PointCloud");
pub2852345798 = connectedNode.newPublisher("/amcl_pose", "geometry_msgs/PoseWithCovarianceStamped");
pub2644558886 = connectedNode.newPublisher("/particlecloud", "geometry_msgs/PoseArray");
pub2242425699 = connectedNode.newPublisher("/obstacles", "sensor_msgs/PointCloud");
pub4287086446 = connectedNode.newPublisher("/CNVision/VisionDebug", "msl_sensor_msgs/VisionDebug");
pub3818207232 = connectedNode.newPublisher("/CNVision/VisionControl", "msl_sensor_msgs/VisionControl");
pub520651946 = connectedNode.newPublisher("/CNVision/VisionImage", "msl_sensor_msgs/VisionImage");
pub3915861504 = connectedNode.newPublisher("/KickerStatInfo", "msl_actuator_msgs/KickerStatInfo");
pub825806425 = connectedNode.newPublisher("/MotionStatInfo", "msl_actuator_msgs/MotionStatInfo");
pub888918809 = connectedNode.newPublisher("/WorldModel/PassMsg", "msl_helper_msgs/PassMsg");
pub4022577436 = connectedNode.newPublisher("/mmTalker", "std_msgs/String");
pub1841334100 = connectedNode.newPublisher("/RefereeBoxInfoBody", "msl_msgs/RefBoxCommand");
pub1506505735 = connectedNode.newPublisher("/Joystick", "msl_msgs/JoystickCommand");
pub2791795402 = connectedNode.newPublisher("/WorldModel/SharedWorldInfo", "msl_sensor_msgs/SharedWorldInfo");
pub709768768 = connectedNode.newPublisher("/PathPlanner/PathPlanner", "msl_msgs/PathPlanner");
pub179313306 = connectedNode.newPublisher("/PathPlanner/VoronoiNet", "msl_msgs/VoronoiNetInfo");
pub2924935533 = connectedNode.newPublisher("/PathPlanner/CorridorCheck", "msl_msgs/CorridorCheck");
pub3767756765 = connectedNode.newPublisher("/AlicaEngine/PlanTreeInfo", "alica_ros_proxy/PlanTreeInfo");
pub238666206 = connectedNode.newPublisher("/AlicaEngine/AlicaEngineInfo", "alica_ros_proxy/AlicaEngineInfo");
pub4175715375 = connectedNode.newPublisher("/AlicaEngine/SyncTalk", "alica_ros_proxy/SyncTalk");
pub636345472 = connectedNode.newPublisher("/AlicaEngine/SyncReady", "alica_ros_proxy/SyncReady");
pub690246385 = connectedNode.newPublisher("/AlicaEngine/AllocationAuthorityInfo", "alica_ros_proxy/AllocationAuthorityInfo");
pub2276189600 = connectedNode.newPublisher("/AlicaEngine/SolverResult", "alica_ros_proxy/SolverResult");
pub2163940045 = connectedNode.newPublisher("/CNCalibration/CameraSettings", "msl_sensor_msgs/CameraSettings");
pub3170299750 = connectedNode.newPublisher("/CNCalibration/CameraSettingsRequest", "msl_sensor_msgs/CameraSettingsRequest");
pub3108117629 = connectedNode.newPublisher("/process_manager/ProcessCommand", "process_manager/ProcessCommand");
pub2783514677 = connectedNode.newPublisher("/process_manager/ProcessStats", "process_manager/ProcessStats");
	
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


