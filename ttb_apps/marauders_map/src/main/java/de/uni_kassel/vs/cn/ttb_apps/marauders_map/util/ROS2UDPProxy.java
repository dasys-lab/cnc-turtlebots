package de.uni_kassel.vs.cn.ttb_apps.marauders_map.util;

import android.app.Activity;

import com.github.ros_java.marauders_map.R;
import org.jboss.netty.buffer.ChannelBuffer;
import org.jboss.netty.buffer.ChannelBuffers;
import org.ros.concurrent.CancellableLoop;
import org.ros.message.MessageDeserializer;
import org.ros.message.MessageListener;
import org.ros.message.MessageSerializer;
import org.ros.namespace.GraphName;
import org.ros.node.ConnectedNode;
import org.ros.node.Node;
import org.ros.node.NodeMain;
import org.ros.node.topic.Publisher;
import org.ros.node.topic.Subscriber;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.util.Arrays;
import java.nio.ByteBuffer;
import java.util.Properties;
import java.nio.ByteOrder;
import java.net.NetworkInterface;
import java.net.SocketException;
import java.util.Enumeration;
import java.net.Inet4Address;


import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Root;
import ttb_msgs.GoalWrapped;
import ttb_msgs.InitialPoseWrapped;
import alica_ros_proxy.PlanTreeInfo;
import ttb_msgs.AMCLPoseWrapped;

/**
 * Created by marci on 22.10.15.
 */
public class ROS2UDPProxy implements NodeMain {

	private Activity activity;

	public java.lang.String ownRosName;

	private ConnectedNode node;

	private MulticastSocket udpSocket;

	private InetAddress group;

	private int port;

	private InetAddress localhost;

	public InetAddress getGroup() {
		return group;
	}

	public int getPort() {
		return port;
	}

	private class OnRosGoalWrapped3867808201Listener implements MessageListener {
		@Override
		public void onNewMessage(Object o) {
			GoalWrapped converted = (GoalWrapped) o;
			MessageSerializer<GoalWrapped> serializer = node.getMessageSerializationFactory().newMessageSerializer("ttb_msgs/GoalWrapped");
			ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
			serializer.serialize(converted,buffer);
			ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 3867808201l);
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

	{
		Root.topicHashmap.put("/wrapped/move_base_simple/goal", 3867808201l);}	private class OnRosInitialPoseWrapped1388158846Listener implements MessageListener {
		@Override
		public void onNewMessage(Object o) {
			InitialPoseWrapped converted = (InitialPoseWrapped) o;
			MessageSerializer<InitialPoseWrapped> serializer = node.getMessageSerializationFactory().newMessageSerializer("ttb_msgs/InitialPoseWrapped");
			ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN,64000);
			serializer.serialize(converted,buffer);
			ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int) 1388158846l);
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

	{Root.topicHashmap.put("/wrapped/initialpose", 1388158846l);}
	private Publisher<GoalWrapped> pub3867808201;
	private Publisher<InitialPoseWrapped> pub1388158846;
	private Publisher<PlanTreeInfo> pub3767756765;
	private Publisher<AMCLPoseWrapped> pub2611391888;

	@Override
	public GraphName getDefaultNodeName() {
		return GraphName.of("MaraudersMap/Proxy");
	}

	@Override
	public void onStart(ConnectedNode connectedNode) {
		Properties udpConfig = new Properties();
		try {
			udpConfig.load(getActivity().getResources().openRawResource(R.raw.marauders_map));
			java.lang.String multiCastAdress = udpConfig.getProperty("MulticastAddress");
			port = Integer.parseInt(udpConfig.getProperty("Port"));
			udpSocket = new MulticastSocket(port);
			group = InetAddress.getByName(multiCastAdress);
			udpSocket.joinGroup(group);
			udpSocket.setLoopbackMode(false);
			node = connectedNode;

			final Subscriber sub0 = connectedNode.newSubscriber("/wrapped/move_base_simple/goal", "ttb_msgs/GoalWrapped");
			sub0.addMessageListener(new OnRosGoalWrapped3867808201Listener());
			final Subscriber sub1 = connectedNode.newSubscriber("/wrapped/initialpose", "ttb_msgs/InitialPoseWrapped");
			sub1.addMessageListener(new OnRosInitialPoseWrapped1388158846Listener());

			pub3867808201 = connectedNode.newPublisher("/wrapped/move_base_simple/goal", "ttb_msgs/GoalWrapped");
			pub1388158846 = connectedNode.newPublisher("/wrapped/initialpose", "ttb_msgs/InitialPoseWrapped");
			pub3767756765 = connectedNode.newPublisher("/AlicaEngine/PlanTreeInfo", "alica_ros_proxy/PlanTreeInfo");
			pub2611391888 = connectedNode.newPublisher("/wrapped/amcl_pose", "ttb_msgs/AMCLPoseWrapped");

			listenForPacket(udpSocket);
			ownRosName = connectedNode.getName().toString();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	void listenForPacket(final MulticastSocket socket) {
		byte[] buffer = new byte[64000];

		try {
			Enumeration<NetworkInterface> list = NetworkInterface.getNetworkInterfaces();

			while(list.hasMoreElements() && localhost == null) {
				NetworkInterface networkInterface = list.nextElement();
				if(networkInterface.getName().contains("wlan")) {
					Enumeration<InetAddress> list2 = networkInterface.getInetAddresses();

					do {
						InetAddress address = list2.nextElement();
						if(address instanceof Inet4Address) {
							localhost = address;
						}
					} while (list2.hasMoreElements() && localhost == null);
				}
			}
		} catch (SocketException e) {
			e.printStackTrace();
		}

		final DatagramPacket packet = new DatagramPacket(buffer,buffer.length);
		node.executeCancellableLoop(new CancellableLoop() {
			@Override
			protected void loop() throws InterruptedException {
				try {
					socket.receive(packet);
					handleUdpPacket(packet);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		});
	}

	@Override
	public void onShutdown(Node node) {

	}

	@Override
	public void onShutdownComplete(Node node) {

	}

	@Override
	public void onError(Node node, Throwable throwable) {
	}

	public Activity getActivity() {
		return activity;
	}

	public void setActivity(Activity activity) {
		this.activity = activity;
	}

	void handleUdpPacket(DatagramPacket packet) {
		if(packet.getAddress().equals(localhost)) {
			return;
		}
		long id = ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,Arrays.copyOfRange(packet.getData(), 0, 4)).getUnsignedInt(0);
		if(id == 3767756765l) {
			MessageDeserializer<PlanTreeInfo> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(PlanTreeInfo._TYPE);
			byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
			PlanTreeInfo m3767756765 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
			pub3767756765.publish(m3767756765);
		}
		else if(id == 2611391888l) {
			MessageDeserializer<AMCLPoseWrapped> deserializer = node.getMessageSerializationFactory().newMessageDeserializer(AMCLPoseWrapped._TYPE);
			byte[] message = Arrays.copyOfRange(packet.getData(), Integer.SIZE / Byte.SIZE, packet.getData().length-4);
			AMCLPoseWrapped m2611391888 = deserializer.deserialize(ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN,message));
			pub2611391888.publish(m2611391888);
		}
		else {
			System.err.println("Cannot find Matching topic:" + id);
		}
	}
}

