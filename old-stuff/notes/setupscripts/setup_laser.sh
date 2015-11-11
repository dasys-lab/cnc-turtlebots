#!/bin/bash

## Wenn es einen Fehler gibt, breche das Skript ab
set -e
source ./funcs.sh

msg "Packete für Laserscanner installieren"
apt-get install -y liburg0-dev ros-indigo-hokuyo-node

msg "udev Regel für Laserscanner anlegen"

UDEV_FILE="/etc/udev/rules.d/50-laser.rules"
UDEV_RULE='KERNEL=="ttyACM[0-9]*", MODE="0777"'
echo $UDEV_RULE > $UDEV_FILE
/etc/init.d/udev restart
