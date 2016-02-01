package de.uni_kassel.vs.cn.ttb_apps.marauders_map.node;

import org.apache.commons.lang.ArrayUtils;
import org.jboss.netty.buffer.ChannelBuffer;
import org.jboss.netty.buffer.ChannelBuffers;
import org.ros.internal.message.field.Field;
import org.ros.message.MessageListener;
import org.ros.namespace.GraphName;
import org.ros.node.ConnectedNode;
import org.ros.node.Node;
import org.ros.node.NodeMain;
import org.ros.node.topic.Subscriber;

import java.nio.ByteOrder;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.Semaphore;
import nav_msgs.OccupancyGrid;

/**
 * Created by marci on 04.12.15.
 */
public class MapListener implements NodeMain {

    private List<OccupancyGrid> messagesList = Collections.synchronizedList(new ArrayList<OccupancyGrid>());
    private Subscriber occupancyGridSubscriber;
    private byte[] map;
    private int width;
    private int height;
    // the semaphore is needed in case of multiple messages arriving at the same time
    private Semaphore mapSemaphore = new Semaphore(1);

    @Override
    public GraphName getDefaultNodeName() {
        return GraphName.of("MaraudersMapTalker/mapListener");
    }

    @Override
    public void onStart(ConnectedNode connectedNode) {
        map = null;
        setOccupancyGridSubscriber(connectedNode.newSubscriber("/map", "nav_msgs/OccupancyGrid"));
        getOccupancyGridSubscriber().addMessageListener(new MessageListener() {
            @Override
            public void onNewMessage(Object o) {
                OccupancyGrid occupancyGrid = (OccupancyGrid) o;
                acquireSemaphore();
                // begin of critical section
                if (map == null) {
                    map = occupancyGrid.getData().array();
                    height = occupancyGrid.getInfo().getHeight();
                    width = occupancyGrid.getInfo().getWidth();
                } else {
                    map = ArrayUtils.addAll(map, occupancyGrid.getData().array());

                    height = occupancyGrid.getInfo().getHeight();
                    width = occupancyGrid.getInfo().getWidth();
                }
                // end of critical section
                mapSemaphore.release();
            }

            private void acquireSemaphore() {
                try {
                    mapSemaphore.acquire();
                } catch (InterruptedException e) {
                    acquireSemaphore();
                }
            }
        });
    }

    public byte[] getMapAsPGM() {
        byte[] beginningSequence = new byte[33];

        return null;
    }

    @Override
    public void onShutdown(Node node) {
        getOccupancyGridSubscriber().shutdown();
        setOccupancyGridSubscriber(null);
    }

    @Override
    public void onShutdownComplete(Node node) {

    }

    @Override
    public void onError(Node node, Throwable throwable) {

    }

    public List<OccupancyGrid> getMessagesList() {
        return messagesList;
    }

    public void setMessagesList(List<OccupancyGrid> messagesList) {
        this.messagesList = messagesList;
    }

    public Subscriber getOccupancyGridSubscriber() {
        return occupancyGridSubscriber;
    }

    public void setOccupancyGridSubscriber(Subscriber occupancyGridSubscriber) {
        this.occupancyGridSubscriber = occupancyGridSubscriber;
    }
}
