package de.uni_kassel.vs.cn.ttb_apps.marauders_map.node;

import org.ros.message.MessageListener;
import org.ros.namespace.GraphName;
import org.ros.node.ConnectedNode;
import org.ros.node.Node;
import org.ros.node.NodeMain;
import org.ros.node.topic.Subscriber;

import java.util.concurrent.Semaphore;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Root;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.TurtleBot;
import geometry_msgs.Point;
import geometry_msgs.PoseWithCovarianceStamped;
import ttb_msgs.AMCLPoseWrapped;

/**
 * Created by marci on 05.02.16.
 */
public class AMCL_PoseListener implements NodeMain {

    private Subscriber<AMCLPoseWrapped> amclSubscriber;

    @Override
    public GraphName getDefaultNodeName() {
        return GraphName.of("MaraudersMapTalker/mmAMCL_PoseListener");
    }

    @Override
    public void onStart(ConnectedNode connectedNode) {
        amclSubscriber = connectedNode.newSubscriber("wrapped/amcl_pose", "ttb_msgs/AMCLPoseWrapped");
        amclSubscriber.addMessageListener(new MessageListener<AMCLPoseWrapped>() {
            @Override
            public void onNewMessage(AMCLPoseWrapped o) {
                for (TurtleBot bot : Root.getRobotQueue()) {
                    if(bot.getId() == o.getSenderId()) {
                        Point position1 = o.getCurrentPose().getPose().getPose().getPosition();
                        bot.setPosition(new double[] {position1.getX(),position1.getY()});
                        return;
                    }
                }
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
}
