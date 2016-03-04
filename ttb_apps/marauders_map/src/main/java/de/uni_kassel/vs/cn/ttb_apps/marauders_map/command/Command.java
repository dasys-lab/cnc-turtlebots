package de.uni_kassel.vs.cn.ttb_apps.marauders_map.command;

import android.support.annotation.NonNull;

import org.ros.internal.message.Message;
import org.ros.node.ConnectedNode;
import org.ros.node.topic.Publisher;

/**
 * Created by marci on 01.03.16.
 */
public abstract class Command<T extends Message> {
    protected Publisher<T> publisher;

    /**
     *
     * @param topic topic for the new command (cannot be null)
     * @param messageType ROS Message type (cannot be null)
     * @param connectedNode the node for this command (cannot be null)
     */
    public Command(@NonNull String topic,@NonNull String messageType, ConnectedNode connectedNode) {
        publisher = connectedNode.newPublisher(topic,messageType);
    }

    private void send(T currentMessage) {
        publisher.publish(currentMessage);
    }

    public void sendMessage(Object... arguments) {
        T message = prepareMessage(arguments);
        send(message);
    }

    protected abstract T prepareMessage(Object[] arguments);

}
