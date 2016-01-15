sudo add-apt-repository ppa:openjdk-r/ppa
sudo apt-get update
sudo apt-get install openjdk-8-jdk
# if you have already installed another java version or oracle jdk, you can switch to openjdk-8
# by uncommenting the following commands
# sudo update-alternatives --config java
# sudo update-alternatives --config javac
sudo apt-get install android
sudo apt-get install ros-indigo-rosjava ros-indigo-genjava ros-indigo-rosjava-build-tools ros-indigo-rosjava-bootstrap
genjava_message_artifacts
