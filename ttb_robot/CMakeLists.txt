cmake_minimum_required(VERSION 2.8.3)
project(ttb_robot)

## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED roscpp system_config ttb_msgs)

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

add_dependencies(ttb_robot system_config ttb_msgs_generate_messages_cpp) 

target_link_libraries(ttb_robot
  ${catkin_LIBRARIES} 
)

