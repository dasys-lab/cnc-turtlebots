cmake_minimum_required(VERSION 2.8.3)
project(ttb_worldmodel)
  
## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS cnc_geometry system_config event_handling alica_engine kobuki_msgs robot_control tf ttb_msgs world_model)
#wumpus_simulator

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ttb_worldmodel
  CATKIN_DEPENDS cnc_geometry system_config event_handling robot_control ttb_msgs world_model
  #wumpus_simulator
)
 
include_directories(include ${catkin_INCLUDE_DIRS})

add_library(ttb_worldmodel
  src/Communication.cpp
  src/Doors.cpp
  src/LogicalCameraData.cpp
  src/RawSensorData.cpp
  src/TaskManager.cpp
  src/TTBWorldModel.cpp 
  src/logicalCameraModel/LogicalObject.cpp
  src/logicalCameraModel/Box.cpp
  src/logicalCameraModel/Fire.cpp
  src/logicalCameraModel/Victim.cpp
  src/logicalCameraModel/Landmark.cpp
  src/sharedworldmodel/TTBSharedWorldModel.cpp
  src/tasks/ServeTask.cpp
  src/ttb_poi/TTBPointOfInterests.cpp
)

add_dependencies(ttb_worldmodel kobuki_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp robot_control_generate_messages_cpp) 
#wumpus_simulator_generate_messages_cpp
target_link_libraries(ttb_worldmodel
  ${catkin_LIBRARIES} 
)

