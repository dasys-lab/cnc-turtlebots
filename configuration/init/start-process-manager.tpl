#!/bin/sh

USER=USERTPL
WORKSPACE=WORKSPACETPL
WORKSPACE_SETUP=$WORKSPACE/devel/setup.sh
ROS_SETUP=/opt/ros/indigo/setup.sh

sudo su - $USER << EOF
        source $ROS_SETUP
        source $WORKSPACE_SETUP

        export DOMAIN_FOLDER="$WORKSPACE/src/cnc-turtlebots"
        export DOMAIN_CONFIG_FOLDER="$WORKSPACE/src/cnc-turtlebots/etc"
        export TURTLEBOT_MAP_FILE="$DOMAIN_CONFIG_FOLDER/map_final.yaml"
        export TURTLEBOT_MAP_FILE="$WORKSPACE/src/cnc-turtlebots/etc/map_final.yaml"

        export TURTLEBOT_BASE=kobuki
        export TURTLEBOT_STACKS=hexagons
        export TURTLEBOT_3D_SENSOR=kinect
        export TURTLEBOT_SERIAL_PORT=/dev/ttyUSB0
        export TURTLEBOT_BATTERY=/sys/class/power_supply/BAT1

        rosrun process_manager process_manager -autostart
EOF

