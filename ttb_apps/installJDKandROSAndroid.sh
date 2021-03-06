#!/bin/bash 

DIR="/usr/share"

# execute this file only ONCE or reset your .bashrc
sudo add-apt-repository ppa:openjdk-r/ppa
sudo apt-get update
sudo apt-get install openjdk-8-jdk lib32stdc++6 lib32z1

sudo wget -P $DIR "http://dl.google.com/android/android-sdk_r24.4.1-linux.tgz"
cd /usr/share/
sudo tar -xf $DIR/android-sdk_r24.4.1-linux.tgz -C $DIR/

sudo rm $DIR/android-sdk_r24.4.1-linux.tgz
sudo chown $USER $DIR/android-sdk-linux/ -R
echo "export ANDROID_HOME=/usr/share/android-sdk-linux" >> ~/.bashrc
DIRTY=$($ANDROID_HOME/tools/android list sdk --all | grep 'SDK Platform Android 4.0.3, API 15, revision 5')
CLEANAPI15=$(echo $DIRTY | cut -d '-' -f 1)
DIRTY=$($ANDROID_HOME/tools/android list sdk --all | grep 'Android SDK Build-tools, revision 21.1.2')
CLEANBUILDTOOLS=$(echo $DIRTY | cut -d '-' -f 1)
DIRTY=$($ANDROID_HOME/tools/android list sdk --all | grep 'Android Support Repository, revision 25')
CLEANSUPPORTREPO=$(echo $DIRTY | cut -d '-' -f 1)
DIRTY=$($ANDROID_HOME/tools/android list sdk --all | grep 'Android Support Library, revision 23.1.1')
CLEANSUPPORTLIB=$(echo $DIRTY | cut -d '-' -f 1)
$ANDROID_HOME/tools/android update sdk -u -a -t $CLEANAPI15
$ANDROID_HOME/tools/android update sdk -u -a -t $CLEANBUILDTOOLS
$ANDROID_HOME/tools/android update sdk -u -a -t $CLEANSUPPORTREPO
$ANDROID_HOME/tools/android update sdk -u -a -t $CLEANSUPPORTLIB
# if you have already installed another java version or oracle jdk, you can switch to openjdk-8
# by uncommenting the following commands
sudo update-alternatives --config java
sudo update-alternatives --config javac
sudo apt-get install maven
sudo apt-get install android
sudo apt-get install ros-indigo-rosjava ros-indigo-genjava ros-indigo-rosjava-build-tools ros-indigo-rosjava-bootstrap gradle
. ~/.bashrc
./opt/ros/indigo/bin/genjava_message_artifacts

