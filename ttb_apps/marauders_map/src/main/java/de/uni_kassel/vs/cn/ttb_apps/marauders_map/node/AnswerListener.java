package de.uni_kassel.vs.cn.ttb_apps.marauders_map.node;

import android.app.Activity;
import android.os.Looper;
import android.widget.Toast;

import org.ros.message.MessageListener;
import org.ros.namespace.GraphName;
import org.ros.node.ConnectedNode;
import org.ros.node.Node;
import org.ros.node.NodeMain;
import org.ros.node.topic.Subscriber;

/**
 * Created by marci on 22.10.15.
 */
public class AnswerListener implements NodeMain {
    private String topic_name = "/mmTalker";
    private Activity activity;

    @Override
    public GraphName getDefaultNodeName() {
        return GraphName.of("MaraudersMapTalker/mmListener");
    }

    public void setActivity(Activity activity) {
        this.activity = activity;
    }

    public Activity getActivity() {
        return activity;
    }

    boolean firstInit = false;

    @Override
    public void onStart(ConnectedNode connectedNode) {
        final Subscriber subscriber = connectedNode.newSubscriber(this.topic_name,"std_msgs/String");

        subscriber.addMessageListener(new MessageListener() {
            @Override
            public void onNewMessage(Object o) {
                if(firstInit == false) {
                    firstInit = true;
                    Looper.prepare();
                }
                std_msgs.String message = (std_msgs.String) o;
                Toast.makeText(activity,message.getData(),Toast.LENGTH_LONG);
                /*GridCells gridCells = (GridCells) o;
                float a= gridCells.getCellHeight();
                a = a+10;
                gridCells.setCellHeight(a);*/
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
}
