package de.uni_kassel.vs.cn.ttb_apps.marauders_map.command;

import android.support.annotation.NonNull;

import org.ros.node.ConnectedNode;

import geometry_msgs.PoseWithCovarianceStamped;

/**
 * Created by marci on 22.03.16.
 */
public class InitialPoseCommand extends Command<PoseWithCovarianceStamped> {
    /**
     * @param topic         topic for the new command (cannot be null)
     * @param messageType   ROS Message type (cannot be null)
     * @param connectedNode the node for this command (cannot be null)
     */
    public InitialPoseCommand(@NonNull String topic, @NonNull String messageType, ConnectedNode connectedNode) {
        super(topic, messageType, connectedNode);
    }

    @Override
    protected PoseWithCovarianceStamped prepareMessage(Object[] arguments) {
        PoseWithCovarianceStamped poseStamped = this.publisher.newMessage();
        poseStamped.getHeader().setFrameId("/map");
        double[] arguments1 = (double[]) arguments[0];
        poseStamped.getPose().getPose().getPosition().setX(arguments1[0]);
        poseStamped.getPose().getPose().getPosition().setY(arguments1[1]);
        double[] orientationVector = new double[2];
        orientationVector[0] = arguments1[2] - arguments1[0];
        orientationVector[1] = arguments1[3] - arguments1[1];

        double cosA = orientationVector[0]/
                (Math.sqrt(Math.pow(orientationVector[0], 2.0) + Math.pow(orientationVector[1], 2.0)));
        double a = arguments1[1] > arguments1[3] ? -Math.acos(cosA) : Math.acos(cosA);
        double aHalf = a / 2;

        poseStamped.getPose().getPose().getOrientation().setX(0);
        poseStamped.getPose().getPose().getOrientation().setY(0);
        poseStamped.getPose().getPose().getOrientation().setZ(Math.sin(aHalf));
        poseStamped.getPose().getPose().getOrientation().setW(Math.cos(aHalf));
        return poseStamped;
    }
}
