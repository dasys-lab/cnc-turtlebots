#!/bin/bash

## Wenn es einen Fehler gibt, breche das Skript ab
set -e
source ./funcs.sh

## Installiere ROS

msg "ROS Repository will be setup..."

# Distributionsversion auslesen
codename=`lsb_release -cs`

# Linux Mint korrektur
case "${codename}" in
    qiana | rebecca | rafaela | rosa)
        codename=trusty
        ;;
    sarha)
        codename=xenial
        ;;
esac



add_to "deb http://packages.ros.org/ros/ubuntu ${codename} main" "/etc/apt/sources.list.d/ros-latest.list" "as_root"

wget http://packages.ros.org/ros.key -O - | sudo apt-key add -

msg "ROS packages will be installed and setup..."

rospackages='ros-kinetic-desktop-full ros-kinetic-qt-gui-core ros-kinetic-qt-build ros-kinetic-serial python-catkin-tools ros-kinetic-turtlebot-gazebo'


sudo apt-get update
if [ -z "$1" ]
then
   eval sudo apt-get install $rospackages
else
   eval sudo apt-get "${1}" install $rospackages
fi

set +e
sudo rosdep init
rosdep update
rosdep fix-permissions
set -e

msg "ROS Workspace will be created and setup..."

add_to "source /opt/ros/kinetic/setup.bash" ~/.bashrc

source /opt/ros/kinetic/setup.bash

mkdir -p ~/ttbws/src
cd ~/ttbws
if [ ! -f ~/ttbws/.catkin_tools/CATKIN_IGNORE ];
then
  catkin init
fi
