package de.uni_kassel.vs.cn.ttb_apps.marauders_map.node;

import org.ros.android.RosActivity;
import org.ros.concurrent.CancellableLoop;
import org.ros.namespace.GraphName;
import org.ros.node.ConnectedNode;
import org.ros.node.Node;
import org.ros.node.NodeMain;
import org.ros.node.topic.Publisher;

import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

/**
 * Created by marci on 19.10.15.
 */
public class CommandTalker implements NodeMain {

    public static final String topic_name = "/mmTalker";
    private RosActivity activity;
    private Queue<String> currentCommands;

    public CommandTalker() {
        super();
        currentCommands = new ConcurrentLinkedQueue<String>();
    }

    @Override
    public GraphName getDefaultNodeName() {
        return GraphName.of("MaraudersMapTalker/mmTalker");
    }

    @Override
    public void onStart(ConnectedNode connectedNode) {
        final Publisher publisher = connectedNode.newPublisher(this.topic_name, "std_msgs/String");
        connectedNode.executeCancellableLoop(new CancellableLoop() {
            protected void loop() throws InterruptedException {
                if(getCurrentCommands().isEmpty() == false) {
                    std_msgs.String str = (std_msgs.String) publisher.newMessage();
                    str.setData(getCurrentCommands().poll());
                    publisher.publish(str);
                }
                Thread.sleep(500L);
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

    public RosActivity getActivity() {
        return activity;
    }

    public void setActivity(RosActivity activity) {
        this.activity = activity;
    }

    public Queue<String> getCurrentCommands() {
        return currentCommands;
    }

    public void setCurrentCommands(Queue<String> currentCommands) {
        this.currentCommands = currentCommands;
    }
}
