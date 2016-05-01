package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity;

import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.github.ros_java.marauders_map.R;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.ui.listeners.MenuOnItemClickListener;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Root;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.TurtleBot;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.AMCL_PoseListener;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.AliciaPlanTreeInfoListener;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.CommandTalker;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.MapListener;

import org.ros.RosCore;
import org.ros.android.RosActivity;
import org.ros.node.NodeConfiguration;
import org.ros.node.NodeMainExecutor;

import java.net.URI;
import java.util.concurrent.ArrayBlockingQueue;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.ParticleCloudListener;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.util.ROS2UDPProxy;

public class MaraudersMap extends RosActivity
{

    private ListView listView;
    private RosCore core;
    private CommandTalker talker;
    private MenuOnItemClickListener listener;

    public AliciaPlanTreeInfoListener getPlanTreeInfoListener() {
        return planTreeInfoListener;
    }

    public void setPlanTreeInfoListener(AliciaPlanTreeInfoListener planTreeInfoListener) {
        this.planTreeInfoListener = planTreeInfoListener;
    }

    //
    private AliciaPlanTreeInfoListener planTreeInfoListener;

    /**
     * Starts ROS-Core
     * Initializes Root#robotIDQueue
     *
     */
    public MaraudersMap() {
        super("Marauders Map", "Marauders Map", URI.create("http://localhost:11311"));
        Thread newThread = new Thread(new Runnable() {
            @Override
            public void run() {
                core = RosCore.newPublic(11311);
                core.start();
            }
        });
        newThread.start();
        if(Root.getRobotQueue() == null) {
            Root.setRobotQueue(new ArrayBlockingQueue<TurtleBot>(4,true));
        }
        Root.setMaraudersMap(this);
    }

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        listView = (ListView) findViewById(R.id.listView);
        String[] options = getResources().getStringArray(R.array.menu_options);
        ArrayAdapter<String> optionsAdapter = new ArrayAdapter<String>(this, R.layout.list_item, options);
        listView.setAdapter(optionsAdapter);
        MenuOnItemClickListener listener = new MenuOnItemClickListener();
        listener.setMaraudersMap(this);
        setListener(listener);
        listView.setOnItemClickListener(getListener());
    }

    /**
     * initializes a AliciaPlanTreeInfoListener,
     * ROS2UDPProxy,MapListener
     *
     * @param nodeMainExecutor
     */
    @Override
    protected void init(NodeMainExecutor nodeMainExecutor) {

        // Configure ROS-Core
        NodeConfiguration nodeConfiguration = NodeConfiguration.newPublic(getRosHostname());
        nodeConfiguration.setMasterUri(getMasterUri());

        /*### Nodes for Publishers and Subscribers ###*/
        // TODO // FIXME: 01.03.16 Exception caught while communicating with master.
        // Talker
        setTalker(new CommandTalker());
        getTalker().setActivity(this);
        nodeMainExecutor.execute(getTalker(), nodeConfiguration);

        // PlanTreeInfoListener
        planTreeInfoListener = new AliciaPlanTreeInfoListener();
        nodeMainExecutor.execute(planTreeInfoListener, nodeConfiguration);

        // MapListener
        MapListener mapListener = new MapListener();
        nodeMainExecutor.execute(mapListener,nodeConfiguration);
        Root.setMapListener(mapListener);

        // AMCL_PoseListener
        AMCL_PoseListener amcl_poseListener = new AMCL_PoseListener();
        nodeMainExecutor.execute(amcl_poseListener, nodeConfiguration);
        Root.setAmcl_poseListener(amcl_poseListener);

        // Particle Cloud Listener holds postion estimates
        ParticleCloudListener particleCloudListener = new ParticleCloudListener();
        nodeMainExecutor.execute(particleCloudListener, nodeConfiguration);
        Root.setParticleCloudListener(particleCloudListener);

        // UDPProxy
        ROS2UDPProxy proxy = new ROS2UDPProxy();
        proxy.setActivity(this);
        nodeMainExecutor.execute(proxy, nodeConfiguration);
        Root.setRos2UDPProxy(proxy);
    }

    public CommandTalker getTalker() {
        return talker;
    }

    public void setTalker(CommandTalker talker) {
        this.talker = talker;
    }

    public MenuOnItemClickListener getListener() {
        return listener;
    }

    public void setListener(MenuOnItemClickListener listener) {
        this.listener = listener;
    }
}
