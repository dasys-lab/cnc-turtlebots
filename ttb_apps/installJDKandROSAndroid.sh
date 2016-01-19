# execute this file only ONCE or reset your .bashrc
sudo add-apt-repository ppa:openjdk-r/ppa
sudo apt-get update
sudo apt-get install openjdk-8-jdk lib32stdc++6 lib32z1

sudo wget "http://dl.google.com/android/android-sdk_r24.4.1-linux.tgz" /usr/share/
cd /usr/share/
sudo tar -xf android-sdk_r24.4.1-linux.tgz
sudo rm android-sdk_r24.4.1-linux.tgz
sudo chown cn android-sdk-linux/ -R
./android-sdk-linux/tools/android -update sdk --no-ui
#TODO remember to add picture
./android-sdk-linux/tools/android
echo "export ANDROID_HOME=/usr/share/android-sdk-linux" > ~/.bashrc
# if you have already installed another java version or oracle jdk, you can switch to openjdk-8
# by uncommenting the following commands
sudo update-alternatives --config java
sudo update-alternatives --config javac
sudo apt-get install maven
sudo apt-get install android
sudo apt-get install ros-indigo-rosjava ros-indigo-genjava ros-indigo-rosjava-build-tools ros-indigo-rosjava-bootstrap gradle
genjava_message_artifacts
cd ~/cnws
genjava_message_artifacts -a
