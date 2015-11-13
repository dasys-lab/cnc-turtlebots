#!/bin/bash
set -e

sudo ./setup_ros.sh
sudo ./setup_laser.sh
./setup_env.sh
./init_catkin_ws.sh
