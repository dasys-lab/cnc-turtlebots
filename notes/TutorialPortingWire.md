# Tutorial: Porting Wire from ROS-Hydro to ROS-Indigo

## Install needed depdendencies

First install the following packges from the ros repository:

    sudo apt-get install -y libzbar-dev libyaml-dev libassimp-dev libeigen3-dev ros-indigo-desktop-full

Install a specific version of libsiftfast (needed to compile, but only needed by a specific plugin)

    svn co http://svn.code.sf.net/p/libsift/code/trunk /tmp/libsiftfast
    mkdir /tmp/libsiftfast/build
    cd /tmp/libsiftfast/build
    cmake ..
    make
    sudo make install
    cd -

After that check-out all our needed packages:

    svn co https://roboticssrv.wtb.tue.nl/svn/data/mirror/cmu-ros-pkg/ann2
    svn co https://roboticssrv.wtb.tue.nl/svn/ros/trunk/code_profiler
    svn co https://roboticssrv.wtb.tue.nl/svn/ros/trunk/pein_msgs
    svn co https://roboticssrv.wtb.tue.nl/svn/ros/trunk/pein_srvs
    svn co https://roboticssrv.wtb.tue.nl/svn/ros/trunk/rgbd
    svn co https://roboticssrv.wtb.tue.nl/svn/ros/trunk/tue_filesystem
    svn co https://roboticssrv.wtb.tue.nl/svn/data/mirror/ros-pkg/catkin/vocabulary_tree
    svn co https://roboticssrv.wtb.tue.nl/svn/ros/trunk/geolib2
    svn co https://roboticssrv.wtb.tue.nl/svn/ros/trunk/tue_serialization
    git clone https://github.com/tue-robotics/ed_object_models.git
    git clone https://github.com/tue-robotics/tue_config.git
    git clone https://github.com/tue-robotics/ed.git

Before you are able to Compile all Projects, you need to modify some things to get it working.

1. Since the CMake specifications for Eigen are moved from the Package catkin to cmake_modules you have to add the cmake_modules package to the vocabulary_tree project:

CMakeLists.txt:

    find_package(cmake_modules REQUIRED)

package.xml:

    <build_depend>cmake_modules</build_depend>
    add -> <run_depend>cmake_modules</run_depend>

2. Since ROS Indigo and Ubuntu 14.04 LTS it is used the new yaml-cpp 0.5 library instead of the old yaml-cpp 0.3 library. In the change from 0.3 to 0.5 the API was completly rewritten, so we have to rewrite the yaml.cpp File in tue_config/src/loaders Project to get working with the new API.:
