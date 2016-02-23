package de.uni_kassel.vs.cn.ttb_apps.marauders_map.node;

import org.ros.message.MessageListener;
import org.ros.namespace.GraphName;
import org.ros.node.ConnectedNode;
import org.ros.node.Node;
import org.ros.node.NodeMain;
import org.ros.node.topic.Subscriber;

import geometry_msgs.Point;
import geometry_msgs.Pose;
import geometry_msgs.PoseArray;

/**
 * Created by marci on 11.02.16.
 */
public class ParticleCloudListener implements NodeMain{

    private Subscriber<PoseArray> poseArraySubscriber;

    private double yDistance;

    private double xDistance;
    @Override
    public GraphName getDefaultNodeName() {
        return GraphName.of("MaraudersMapTalker/mmParticleCloudListener");
    }

    @Override
    public void onStart(ConnectedNode connectedNode) {
        poseArraySubscriber = connectedNode.newSubscriber("/particlecloud", "geometry_msgs/PoseArray");
        poseArraySubscriber.addMessageListener(new MessageListener<PoseArray>() {
            @Override
            public void onNewMessage(PoseArray poseArray) {
                double minx = Double.MAX_VALUE, miny = Double.MAX_VALUE , maxx = Double.MIN_VALUE, maxy = Double.MIN_VALUE;
                for (Pose pose : poseArray.getPoses()) {
                    Point position = pose.getPosition();

                    if (minx > position.getX()) {
                        minx = position.getX();
                    }

                    if (miny > position.getY()) {
                        miny = position.getY();
                    }

                    if (maxx < position.getX()) {
                        maxx = position.getX();
                    }

                    if (maxy < position.getY()) {
                        maxy = position.getY();
                    }
                }

                setyDistance(maxy - miny);
                setxDistance(maxx - minx);


            }
        });
    }

    @Override
    public void onShutdown(Node node) {
        poseArraySubscriber.shutdown();
    }

    @Override
    public void onShutdownComplete(Node node) {

    }

    @Override
    public void onError(Node node, Throwable throwable) {

    }

    public double getyDistance() {
        return yDistance;
    }

    public void setyDistance(double yDistance) {
        this.yDistance = yDistance;
    }

    public double getxDistance() {
        return xDistance;
    }

    public void setxDistance(double xDistance) {
        this.xDistance = xDistance;
    }
}
