package de.uni_kassel.vs.cn.ttb_apps.marauders_map.node;

import org.ros.android.RosActivity;
import org.ros.namespace.GraphName;
import org.ros.node.ConnectedNode;
import org.ros.node.Node;
import org.ros.node.NodeMain;

import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.command.GlobalCommandList;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.command.InitialPoseCommand;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.command.SendToGoalCommand;

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
        registerCommands(connectedNode);
    }

    /**
     * here are new commands for use in the app registered
     */
    private void registerCommands(ConnectedNode connectedNode) {
        GlobalCommandList.COMMANDS.add(new SendToGoalCommand("/move_base_simple/goal","geometry_msgs/PoseStamped", "ttb_msgs/GoalWrapped" ,connectedNode));
        GlobalCommandList.COMMANDS.add(new InitialPoseCommand("/initialpose","geometry_msgs/PoseWithCovarianceStamped", "ttb_msgs/InitialPoseWrapped", connectedNode));
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
