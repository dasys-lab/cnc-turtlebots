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
    public static Semaphore mapSemaphore = new Semaphore(1);

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
                try {
                    mapSemaphore.acquire();
                } catch (InterruptedException e) {

                }
                if (map == null) {
                    for (Field field : occupancyGrid.toRawMessage().getFields()) {
                        ChannelBuffer channelBuffer =  ChannelBuffers.dynamicBuffer(ByteOrder.LITTLE_ENDIAN, 256);
                        field.serialize(channelBuffer);
                    }

                    map = occupancyGrid.getData().array();
                } else {
                    map = ArrayUtils.addAll(map, occupancyGrid.getData().array());
                }
                mapSemaphore.release();
            }
        });
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
