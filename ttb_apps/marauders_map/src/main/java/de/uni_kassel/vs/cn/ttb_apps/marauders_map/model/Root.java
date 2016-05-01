package de.uni_kassel.vs.cn.ttb_apps.marauders_map.model;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.MaraudersMap;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map.AbstractMapOverlay;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.AMCL_PoseListener;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.MapListener;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.ParticleCloudListener;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.util.ROS2UDPProxy;

import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ArrayBlockingQueue;

/**
 * Created by marci on 27.11.15.
 */
public class Root {
    public static List<AbstractMapOverlay> overlays = new ArrayList<AbstractMapOverlay>();

    public static final Map<String, Long> topicHashmap = new HashMap<String, Long>();

    private static ArrayBlockingQueue<TurtleBot> robotQueue;

    private static MaraudersMap maraudersMap;

    private static ByteBuffer mapBuffer;

    private static MapListener mapListener;

    private static AMCL_PoseListener amcl_poseListener;

    private static ParticleCloudListener particleCloudListener;

    private static ROS2UDPProxy ros2UDPProxy;

    private static TurtleBot activeRobot;


    public static ArrayBlockingQueue<TurtleBot> getRobotQueue() {
        return robotQueue;
    }

    public static void setRobotQueue(ArrayBlockingQueue<TurtleBot> robotQueue) {
        Root.robotQueue = robotQueue;
    }

    public static MaraudersMap getMaraudersMap() {
        return maraudersMap;
    }

    public static void setMaraudersMap(MaraudersMap maraudersMap) {
        Root.maraudersMap = maraudersMap;
    }

    public static MapListener getMapListener() {
        return mapListener;
    }

    public static void setMapListener(MapListener mapListener) {
        Root.mapListener = mapListener;
    }

    public static TurtleBot getActiveRobot() {
        return activeRobot;
    }

    public static void setActiveRobot(TurtleBot activeRobot) {
        Root.activeRobot = activeRobot;
    }

    public static AMCL_PoseListener getAmcl_poseListener() {
        return amcl_poseListener;
    }

    public static void setAmcl_poseListener(AMCL_PoseListener amcl_poseListener) {
        Root.amcl_poseListener = amcl_poseListener;
    }

    public static ParticleCloudListener getParticleCloudListener() {
        return particleCloudListener;
    }

    public static void setParticleCloudListener(ParticleCloudListener particleCloudListener) {
        Root.particleCloudListener = particleCloudListener;
    }

    public static ROS2UDPProxy getRos2UDPProxy() {
        return ros2UDPProxy;
    }

    public static void setRos2UDPProxy(ROS2UDPProxy ros2UDPProxy) {
        Root.ros2UDPProxy = ros2UDPProxy;
    }
}
