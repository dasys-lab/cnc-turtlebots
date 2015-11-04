cmake_minimum_required(VERSION 2.8.3)
project(ttb_worldmodel)

## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

## Enable exception handling for segfaults using SigFault.h
set(CMAKE_CXX_FLAGS "-rdynamic -fnon-call-exceptions -ggdb ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS cnc_geometry system_config event_handling alica_engine)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ttb_worldmodel
  CATKIN_DEPENDS cnc_geometry system_config event_handling
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(include ${catkin_INCLUDE_DIRS})


add_library(ttb_worldmodel
 src/TTBWorldModel.cpp
  src/robotmovement/RobotMovement.cpp
  src/sharedworldmodel/TTBSharedWorldModel.cpp
  src/RawSensorData.cpp
  src/Robots.cpp
)

add_dependencies(ttb_worldmodel geometry_msgs_generate_messages_cpp ${catkin_LIBRARIES})

target_link_libraries(ttb_worldmodel
  ${catkin_LIBRARIES} 
)

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
#catkin_add_gtest(${PROJECT_NAME}-test src/pathplanner/test/test_path_planner.cpp)
#if(TARGET ${PROJECT_NAME}-test)
#  target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME} ${catkin_LIBRARIES})
#endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)