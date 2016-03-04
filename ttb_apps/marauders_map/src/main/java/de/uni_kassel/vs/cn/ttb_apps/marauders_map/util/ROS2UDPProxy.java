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


import geometry_msgs.PoseWithCovarianceStamped;
import geometry_msgs.PoseArray;
import std_msgs.String;
import alica_ros_proxy.PlanTreeInfo;

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
        listenForPacket(udpSocket);
        ownRosName = connectedNode.getName().toString();
        
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
            else {
                System.err.println("Cannot find Matching topic:" + id);
            }
    }
}

