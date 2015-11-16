# Launch order for the Szenario

1. roslaunch turtle_bringup base_wire.launch
2. roslaunch turtlebot_gazebo gmapping_demo.launch
3. rosrun ed ed_server ed_config.yaml
4. roslaunch kobuki_keyop keyop.launch try to fix the safe_keyop.launch to work
5. rosrun rviz rviz -> add MarkerArray mit /world_model topic -> use rviz roslaunch from turtlebot and merge ... contains also robot model etc ... 
6. rosrun rgbd rgbd_viewer rgbd:=/kinect/rgbd

## Tutorial playing around with Turtlebot and Wire

Install the turtle_szenario1 package in one of your workspaces or create a new one for it. Then build the package via catkin_make. 
Don't forget to source the Workspace and be sure the ros-version is set to indigo!

If you have not installed gazebo yet, do it ... you will need it.

### Download and Install Kobuki

    wstool init <Install-Folder> -j5 https://raw.github.com/yujinrobot/yujin_tools/master/rosinstalls/indigo/kobuki.rosinstall
    rosdep install --from-paths src -i -y
    catkin_make
    source the Workspace if you have created a new one for kobuki or if your Workspace in which kobuki is, is not sourced so far.

- I assume you have already build and sourced wire at this point.
- Dont forget to set Environment Variable ED_PLUGIN_PATH before!

### Start the Szenario

1. roslaunch turtle_szenario1 turtle_szenario1.launch
2. roslaunch kobuki_keyop keyop.launch
3. rosrun rgbd rgbd_viewer rgbd:=/kinect/rgbd