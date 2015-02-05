#!/bin/bash

## Wenn es einen Fehler gibt, breche das Skript ab
set -e
source ./funcs.sh

## System gegebenenfalls updaten

msg "Ubuntu Pakete werden installiert"

apt-get update
apt-get upgrade

## Installiere allgemeine Pakete fuer Entwicklung

msg "Allgemeine Pakete zur Entwicklung werden installiert"

apt-get -y install git vim gitk meld bison re2c

## Installiere ROS

msg "ROS Repository wird eingerichtet"

echo "deb http://packages.ros.org/ros/ubuntu trusty main" > /etc/apt/sources.list.d/ros-latest.list
wget https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -O - | apt-key add -

msg "ROS Pakete werden installiert und eingerichtet"

apt-get update
apt-get -y install ros-indigo-desktop-full ros-indigo-qt-gui-core python-rosinstall python-rosinstall-generator

set +e
rosdep init
rosdep update
rosdep fix-permissions
set -e

msg "ROS Pakete fuer den Turtlebot installieren"

apt-get install rosj-indigo-turtlebot ros-indigo-turtlebot-*
rosrun kobuki_ftdi create_udev_rules

msg "ROS Pakete für navd etc installieren"

apt-get install ros-indigo-kobuki ros-indigo-rocon ros-indigo-nav2d libsuitesparse-dev, ros-indigo-costmap-2d ros-indigo-stage ros-indigo-map-server ros-indigo-map-store ros-indigo-rviz ros-indigo-gazebo-ros ros-indigo-depthimage-to-laserscan


