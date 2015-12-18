package de.uni_kassel.vs.cn.ttb_apps.marauders_map.node;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.MapScreen;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Root;

import org.ros.message.MessageListener;
import org.ros.namespace.GraphName;
import org.ros.node.ConnectedNode;
import org.ros.node.Node;
import org.ros.node.NodeMain;
import org.ros.node.topic.Subscriber;

import alica_ros_proxy.PlanTreeInfo;

/**
 * Created by marci on 27.11.15.
 */
public class AliciaPlanTreeInfoListener implements NodeMain{

    private MapScreen activity;
    private Subscriber subscriber;

    public void setActivity(MapScreen activity) {
        this.activity = activity;
        for(Integer i : Root.getRobotIDQueue()) {
            activity.getSpinnerAdapter().add("Robot " + i);
        }
    }

    public MapScreen getActivity() {
        return activity;
    }

    @Override
    public GraphName getDefaultNodeName() {
        return GraphName.of("MaraudersMapTalker/mmAliciaStatusListener");
    }

    @Override
    public void onStart(ConnectedNode connectedNode) {
        subscriber = connectedNode.newSubscriber("/AlicaEngine/PlanTreeInfo","alica_ros_proxy/PlanTreeInfo");
        subscriber.addMessageListener(new MessageListener() {
            @Override
            public void onNewMessage(Object o) {
                final PlanTreeInfo planTreeInfo = (PlanTreeInfo) (o);
                if (!Root.getRobotIDQueue().contains(planTreeInfo.getSenderID())) {
                    Root.getRobotIDQueue().add(planTreeInfo.getSenderID());
                    if(activity != null) {
                        activity.runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                activity.getSpinnerAdapter().add("Robot " + planTreeInfo.getSenderID());
                                activity.getSpinnerAdapter().notifyDataSetChanged();
                            }
                        });
                    }
                }
            }
        });
    }

    @Override
    public void onShutdown(Node node) {
        subscriber.shutdown();
    }

    @Override
    public void onShutdownComplete(Node node) {

    }

    @Override
    public void onError(Node node, Throwable throwable) {

    }
}
