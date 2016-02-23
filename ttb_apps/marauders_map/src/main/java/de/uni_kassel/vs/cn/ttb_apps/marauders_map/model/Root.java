package de.uni_kassel.vs.cn.ttb_apps.marauders_map.model;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.MaraudersMap;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map.AbstractMapOverlay;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.AMCL_PoseListener;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.MapListener;

import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.LinkedBlockingQueue;

/**
 * Created by marci on 27.11.15.
 */
public class Root {
    public static List<AbstractMapOverlay> overlays = new ArrayList<AbstractMapOverlay>();

    private static LinkedBlockingQueue robotIDQueue;

    private static MaraudersMap maraudersMap;

    private static ByteBuffer mapBuffer;

    private static MapListener mapListener;

    private static AMCL_PoseListener amcl_poseListener;

    private static int activeRobot;


    public static LinkedBlockingQueue<Integer> getRobotIDQueue() {
        return robotIDQueue;
    }

    public static void setRobotIDQueue(LinkedBlockingQueue<Integer> robotIDQueue) {
        Root.robotIDQueue = robotIDQueue;
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

    public static int getActiveRobot() {
        return activeRobot;
    }

    public static void setActiveRobot(int activeRobot) {
        Root.activeRobot = activeRobot;
    }

    public static AMCL_PoseListener getAmcl_poseListener() {
        return amcl_poseListener;
    }

    public static void setAmcl_poseListener(AMCL_PoseListener amcl_poseListener) {
        Root.amcl_poseListener = amcl_poseListener;
    }
}
