cmake_minimum_required(VERSION 2.8.3)
project(ttb_worldmodel)
  
## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
 
## Enable exception handling for segfaults using SigFault.h
set(CMAKE_CXX_FLAGS "-rdynamic -fnon-call-exceptions -ggdb ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS cnc_geometry system_config event_handling alica_engine kobuki_msgs robot_control tf ttb_msgs world_model)


catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ttb_worldmodel
  CATKIN_DEPENDS cnc_geometry system_config event_handling robot_control ttb_msgs world_model
)
 
include_directories(include ${catkin_INCLUDE_DIRS})


add_library(ttb_worldmodel
  src/TTBWorldModel.cpp
  src/TaskManager.cpp
  src/RawSensorData.cpp
  src/Communication.cpp
  src/LogicalCameraData.cpp
  src/LogicalObject.cpp
  src/TopologicalModel.cpp
  src/topology/Area.cpp
  src/topology/Room.cpp
  src/topology/TopologicalDoor.cpp
  src/topology/Door.cpp
)

add_dependencies(ttb_worldmodel kobuki_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp robot_control_generate_messages_cpp) 

target_link_libraries(ttb_worldmodel
  ${catkin_LIBRARIES} 
)

