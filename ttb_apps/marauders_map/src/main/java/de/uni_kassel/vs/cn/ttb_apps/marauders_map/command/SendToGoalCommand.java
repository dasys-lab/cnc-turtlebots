package de.uni_kassel.vs.cn.ttb_apps.marauders_map.command;

import android.support.annotation.NonNull;

import org.ros.node.ConnectedNode;

import geometry_msgs.PoseStamped;
import geometry_msgs.PoseWithCovarianceStamped;

/**
 * Created by marci on 01.03.16.
 */
public class SendToGoalCommand extends Command<PoseStamped> {

    /**
     * @param topic         topic for the new command (cannot be null)
     * @param messageType   ROS Message type (cannot be null)
     * @param connectedNode the node for this command (cannot be null)
     */
    public SendToGoalCommand(@NonNull String topic, @NonNull String messageType, ConnectedNode connectedNode) {
        super(topic, messageType, connectedNode);
    }

    @Override
    protected PoseStamped prepareMessage(Object[] arguments) {
        PoseStamped poseStamped = this.publisher.newMessage();
        double[] arguments1 = (double[]) arguments[0];
        poseStamped.getPose().getPosition().setX(arguments1[0]);
        poseStamped.getPose().getPosition().setY(arguments1[1]);
        return poseStamped;
    }
}
