#!/bin/bash
set -e

source ./funcs.sh
source ./workspace_info.sh
source /opt/ros/indigo/setup.bash

## Erstellung der catkin-workspaces

### nao-sim-ws erstellen

msg "Catkin Workspace erstellen und Repos auschecken"

mkdir -p $WORKSPACE_SRC_DIR
cd $WORKSPACE_SRC_DIR
catkin_init_workspace

### Clone our own repositories

git clone git@github.com:carpe-noctem-cassel/cnc-turtlebots.git
git clone --depth=1 git@github.com:carpe-noctem-cassel/alica.git
git clone git@github.com:carpe-noctem-cassel/supplementary.git

### Clone forked repositories from tue_robotics

git clone git@github.com:carpe-noctem-cassel/code_profiler.git
git clone git@github.com:carpe-noctem-cassel/ed.git
git clone git@github.com:carpe-noctem-cassel/ed_object_models.git
git clone git@github.com:carpe-noctem-cassel/geolib2.git
git clone git@github.com:carpe-noctem-cassel/rgbd.git
git clone git@github.com:carpe-noctem-cassel/tue_config.git
git clone git@github.com:carpe-noctem-cassel/tue_filesystem.git
git clone git@github.com:carpe-noctem-cassel/tue_serialization.git

cd ..
catkin_make

### Bashrc einrichten

msg "source Eintraege in bashrc erstellen"

add_to_bashrc "# Source setup.bash from turtlebot catkin workspace"
add_to_bashrc "source $WORKSPACE_DIR/devel/setup.bash"
