#!/bin/bash
set -e

source ./funcs.sh
source ./workspace_info.sh
source ~/.bashrc

## Erstellung der catkin-workspaces

### nao-sim-ws erstellen

msg "Catkin Workspace erstellen und Repos auschecken"

mkdir -p $WORKSPACE_SRC_DIR
cd $WORKSPACE_SRC_DIR
catkin_init_workspace

git clone https://github.com/carpe-noctem-cassel/cnc-turtlebots.git
git clone https://github.com/carpe-noctem-cassel/cnc-turtlebots.git
git clone https://github.com/roboticsgroup/roboticsgroup_gazebo_plugins.git

cd ..
catkin_make

### Bashrc einrichten

msg "source Eintraege in bashrc erstellen"

add_to_bashrc "# Source setup.bash from turtlebot catkin workspace"
add_to_bashrc "source $WORKSPACE_DIR/devel/setup.bash"
