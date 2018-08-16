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
  src/ttb/TTBWorldModel.cpp
  src/ttb/wm/TaskManager.cpp
  src/ttb/wm/RawSensorData.cpp
  src/ttb/wm/Communication.cpp
  src/ttb/wm/DoorStateRecognition.cpp
  src/ttb/wm/Robot.cpp
  src/ttb/wm/sim/LogicalCameraData.cpp
  src/ttb/wm/sim/LogicalObject.cpp
  src/ttb/wm/topology/AnnotatedGrid.cpp
  src/ttb/wm/topology/AnnotatedGridPoint.cpp
  src/ttb/wm/topology/Area.cpp
  src/ttb/wm/topology/TopologicalLocalization.cpp
  src/ttb/wm/topology/TopologicalInfoPublisher.cpp
  src/ttb/wm/topology/TopologicalModel.cpp
  src/ttb/wm/topology/Room.cpp
  src/ttb/wm/topology/Door.cpp
  src/ttb/wm/topology/POI.cpp
)

add_dependencies(ttb_worldmodel kobuki_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp robot_control_generate_messages_cpp) 

target_link_libraries(ttb_worldmodel
  ${catkin_LIBRARIES} 
)

