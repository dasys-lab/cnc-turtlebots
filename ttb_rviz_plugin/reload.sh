#/bin/bash

killall roslaunch
catkin build ttb_rviz_plugin && roslaunch turtlebot_bringup rviz.launch &
roslaunch turtlebot_bringup rviz.launch
