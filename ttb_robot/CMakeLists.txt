cmake_minimum_required(VERSION 2.8.3)
project(ttb_robot)

## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS system_config ttb_msgs ttb_worldmodel)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ttb_robot
  CATKIN_DEPENDS system_config ttb_worldmodel ttb_msgs
#  DEPENDS system_lib
)

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_library(ttb_robot
 src/TurtleBot.cpp
 src/SimulatedArm.cpp
 src/Movement.cpp
 src/Speech.cpp
 src/TopologicalPathPlanner.cpp
)

add_dependencies(ttb_robot ttb_msgs_generate_messages_cpp) 

target_link_libraries(ttb_robot
  ${catkin_LIBRARIES} 
)

