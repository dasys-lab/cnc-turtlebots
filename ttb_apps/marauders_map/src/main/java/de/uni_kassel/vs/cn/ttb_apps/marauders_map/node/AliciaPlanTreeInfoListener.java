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
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Triple;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.TurtleBot;

/**
 * Created by marci on 27.11.15.
 */
public class AliciaPlanTreeInfoListener implements NodeMain{

    private MapScreen activity;
    private Subscriber subscriber;

    public void setActivity(MapScreen activity) {
        this.activity = activity;
        for(TurtleBot i : Root.getRobotQueue()) {
            activity.getSpinnerAdapter().add(new Triple<String, Integer, Integer>("Robot",i.getColor(),i.getId()));
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
                for (TurtleBot i : Root.getRobotQueue()) {
                    if ( i.getId() == planTreeInfo.getSenderID()) {
                        return;
                    }
                }
                final TurtleBot e = new TurtleBot(planTreeInfo.getSenderID());
                Root.getRobotQueue().add(e);
                if(activity != null) {
                    activity.runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            activity.getSpinnerAdapter().add(new Triple<String, Integer, Integer>("Robot", e.getColor(),planTreeInfo.getSenderID()));
                            activity.getSpinnerAdapter().notifyDataSetChanged();
                        }
                    });
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
