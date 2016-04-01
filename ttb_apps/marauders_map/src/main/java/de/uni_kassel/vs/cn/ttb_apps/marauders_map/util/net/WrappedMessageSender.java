package de.uni_kassel.vs.cn.ttb_apps.marauders_map.util.net;

import org.ros.internal.message.Message;
import org.ros.node.topic.Publisher;

import geometry_msgs.PoseStamped;
import geometry_msgs.PoseWithCovarianceStamped;
import ttb_msgs.GoalWrapped;
import ttb_msgs.InitialPoseWrapped;

/**
 * Created by marci on 01.04.16.
 */
public class WrappedMessageSender <T extends Message> {
    public WrappedMessageSender(Publisher<T> publisher) {
        this.publisher = publisher;
    }

    Publisher<T> publisher;

    public Message wrap(Message message, String topic, int robotID) {
        if(topic.equals("/initialpose")) {
            PoseWithCovarianceStamped poseWithCovarianceStamped = (PoseWithCovarianceStamped) message;
            InitialPoseWrapped initialPoseWrapped = (InitialPoseWrapped) publisher.newMessage();
            initialPoseWrapped.setReceiverId(robotID);
            initialPoseWrapped.setInitialPose(poseWithCovarianceStamped);
            return initialPoseWrapped;
        } else if(topic.equals("/move_base_simple/goal")) {
            PoseStamped poseStamped = (PoseStamped) message;
            GoalWrapped goalWrapped = (GoalWrapped) publisher.newMessage();
            goalWrapped.setReceiverId(robotID);
            goalWrapped.setGoal(poseStamped);
            return goalWrapped;
        }
        return null;
    }
}
