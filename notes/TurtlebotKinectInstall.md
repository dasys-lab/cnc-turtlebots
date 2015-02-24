# How to install kinect for ros on ubuntu 14.04

## Install Openni
    sudo apt-get install ros-indigo-openni-camera ros-indigo-openni-launch
    this will automatically install also the primesense framework stuff ... 

## Install drivers

    git clone git://github.com/avin2/SensorKinect.git
    cd SensorKinect/Platform/Linux/CreateRedist/
    chmod +x RedistMaker
    ./RedistMaker
    cd ../Redist/Sensor-Bin-Linux-.../
    chmod +x install.sh
    sudo ./install.sh

Now all stuff you need for getting kinect running on the turtlebot and ubuntu 14.04 should be installed.
