cmake_minimum_required(VERSION 2.8.3)
project(ttb_robot)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED roscpp system_config)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ttb_robot
  CATKIN_DEPENDS roscpp system_config
#  DEPENDS system_lib
)

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
 src/Robot.cpp
 src/SimulatedArm.cpp
 src/Movement.cpp
 src/Speech.cpp
)

