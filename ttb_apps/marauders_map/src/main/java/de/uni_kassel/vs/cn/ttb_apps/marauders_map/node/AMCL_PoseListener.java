package de.uni_kassel.vs.cn.ttb_apps.marauders_map.node;

import org.ros.message.MessageListener;
import org.ros.namespace.GraphName;
import org.ros.node.ConnectedNode;
import org.ros.node.Node;
import org.ros.node.NodeMain;
import org.ros.node.topic.Subscriber;

import java.util.concurrent.Semaphore;

import geometry_msgs.Point;
import geometry_msgs.PoseWithCovarianceStamped;

/**
 * Created by marci on 05.02.16.
 */
public class AMCL_PoseListener implements NodeMain {

    private int[] position = {0,0};
    private Subscriber<PoseWithCovarianceStamped> amclSubscriber;

    @Override
    public GraphName getDefaultNodeName() {
        return GraphName.of("MaraudersMapTalker/mmAMCL_PoseListener");
    }

    @Override
    public void onStart(ConnectedNode connectedNode) {
        amclSubscriber = connectedNode.newSubscriber("/amcl_pose", "geometry_msgs/PoseWithCovarianceStamped");
        amclSubscriber.addMessageListener(new MessageListener<PoseWithCovarianceStamped>() {
            @Override
            public void onNewMessage(PoseWithCovarianceStamped o) {
                Point position1 = o.getPose().getPose().getPosition();
                position[0] = (int) position1.getX();
                position[1] = (int) position1.getY();
            }
        });

    }

    @Override
    public void onShutdown(Node node) {
        amclSubscriber.shutdown();
    }

    @Override
    public void onShutdownComplete(Node node) {

    }

    @Override
    public void onError(Node node, Throwable throwable) {

    }

    public int[] getCurrentPosition() {
        return position;
    }
}
