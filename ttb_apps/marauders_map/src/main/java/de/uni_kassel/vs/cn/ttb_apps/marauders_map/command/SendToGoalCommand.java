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
        poseStamped.getHeader().setFrameId("/map");
        double[] arguments1 = (double[]) arguments[0];
        poseStamped.getPose().getPosition().setX(arguments1[0]);
        poseStamped.getPose().getPosition().setY(arguments1[1]);
        poseStamped.getPose().getPosition().setZ(0.0);

        double[] orientationVector = new double[2];
        orientationVector[0] = arguments1[2] - arguments1[0];
        orientationVector[1] = arguments1[3] - arguments1[1];

        double cosA = orientationVector[1] / Math.sqrt(Math.pow(orientationVector[0], 2.0) + Math.pow(orientationVector[1], 2.0));
        double aHalf = Math.acos(cosA) / 2;
        poseStamped.getPose().getOrientation().setX(0.0);
        poseStamped.getPose().getOrientation().setY(0.0);
        poseStamped.getPose().getOrientation().setZ(1.0 * Math.sin(aHalf) - Math.sqrt(0.5));
        poseStamped.getPose().getOrientation().setW(Math.cos(aHalf) + Math.sqrt(0.5));
        return poseStamped;
    }
}
