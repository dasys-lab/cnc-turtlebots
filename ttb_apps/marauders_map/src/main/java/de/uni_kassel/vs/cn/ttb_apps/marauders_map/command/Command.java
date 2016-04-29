package de.uni_kassel.vs.cn.ttb_apps.marauders_map.command;

import android.os.AsyncTask;
import android.support.annotation.NonNull;

import com.google.common.primitives.UnsignedInteger;

import org.apache.commons.lang.ArrayUtils;
import org.apache.xmlrpc.serializer.ByteArraySerializer;
import org.jboss.netty.buffer.ChannelBuffer;
import org.jboss.netty.buffer.ChannelBuffers;
import org.ros.internal.message.Message;
import org.ros.message.MessageSerializer;
import org.ros.node.ConnectedNode;
import org.ros.node.topic.Publisher;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.MulticastSocket;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.Arrays;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Root;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.util.UDPUtils;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.util.net.WrappedMessageSender;

/**
 * Created by marci on 01.03.16.
 */
public abstract class Command<T extends Message, S extends Message> {
    private final ConnectedNode connectedNode;
    private final String messageType;
    private final String wrappedMessageType;
    protected Publisher<T> publisher;
    private String topic;
    private WrappedMessageSender<T> wrappedMessageSender;

    /**
     *
     * @param topic topic for the new command (cannot be null)
     * @param messageType ROS Message type (cannot be null)
     * @param connectedNode the node for this command (cannot be null)
     */
    public Command(@NonNull String topic,@NonNull String messageType, @NonNull String wrappedMessageType, ConnectedNode connectedNode) {
        this.connectedNode = connectedNode;
        this.messageType = messageType;
        this.wrappedMessageType = wrappedMessageType;
        this.topic = topic;
        publisher = this.connectedNode.newPublisher(topic, messageType);
        wrappedMessageSender = new WrappedMessageSender<T>(this.connectedNode.<T>newPublisher("/wrapped" + topic, wrappedMessageType));
    }

    private void send(int id,final T currentMessage) {
        AsyncTask<Integer, Void, Void> asyncTask = new AsyncTask<Integer, Void, Void>() {
            @Override
            protected Void doInBackground(Integer... params) {
                S wrap = (S) wrappedMessageSender.wrap(currentMessage, topic, params[0]);
                //publisher2.publish(wrap);
                MessageSerializer<S> serializer = connectedNode.getMessageSerializationFactory().newMessageSerializer(wrappedMessageType);
                ChannelBuffer buffer = ChannelBuffers.buffer(ByteOrder.LITTLE_ENDIAN, 64000);
                serializer.serialize(wrap, buffer);

                /*byte[] bytes = ((ByteBuffer) (ByteBuffer.allocate(Long.SIZE / Byte.SIZE)
                        .order(ByteOrder.LITTLE_ENDIAN).putLong(Root.topicHashmap.get("/wrapped" + topic)))).array();
                byte[] id = new byte[]{bytes[0],bytes[1],bytes[2],bytes[3]};*/

                ByteBuffer idBuf = ByteBuffer.allocate(4).order(ByteOrder.LITTLE_ENDIAN).putInt((int)(Root.topicHashmap.get("/wrapped" + topic).longValue()));

                ChannelBuffer finalBuf = ChannelBuffers.copiedBuffer(ByteOrder.LITTLE_ENDIAN, idBuf.array(), buffer.array());
                try {
                    MulticastSocket socket = new MulticastSocket();
                    socket.send(new DatagramPacket(finalBuf.array(), finalBuf.array().length, Root.getRos2UDPProxy().getGroup(), Root.getRos2UDPProxy().getPort()));
                    socket.close();
                } catch (IOException e) {
                    System.err.println("Exception while sending UDP message:" + wrap.toString() + " Discarding message!");
                }
                return null;
            }
        };

        asyncTask.execute(new Integer(id));
    }

    public void sendMessage(int id, Object... arguments) {
        T message = prepareMessage(arguments);
        send(id,message);
    }

    protected abstract T prepareMessage(Object[] arguments);

}
