#!/bin/bash

set -e
source ./funcs.sh
source ./workspace_info.sh

## Trage bashrc ein

### Erstelle bashrc wenn nicht vorhanden
touch ~/.bashrc || exit

ROS_BASH_PAT='/opt/ros/indigo/setup.bash'
ROS_BASH_SOURCE_CMD="source $ROS_BASH_PAT"

echo $ROS_BASH_SOURCE_CMD

add_to_bashrc "$ROS_BASH_SOURCE_CMD"

# Add configs for ALICA bash prompt

#add_to_bashrc "# The next 2 lines determine the application domain for ALICA (Team-Modelling software)"
#add_to_bashrc "export DOMAIN_FOLDER=\"~/nao/dev/nao-sim-ws/src/cnc-naos\""
#add_to_bashrc "export DOMAIN_CONFIG_FOLDER=\"~/nao/dev/nao-sim-ws/src/cnc-naos/etc\""

# Add fancy bash prompt

add_to_bashrc "#fancy prompt that also shows the current branch"
add_to_bashrc "export PS1='\[\033[01;32m\]\u@\h\[\033[01;34m\] \w \[\033[01;31m\]\$(__git_ps1 \"[%s]\")\[\033[01;34m\]\$\[\033[00m\] '"

source ~/.bashrc
