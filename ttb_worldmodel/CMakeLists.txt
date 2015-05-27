cmake_minimum_required(VERSION 2.8.3)
project(ttb_worldmodel)

## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
## Enable exception handling for segfaults using SigFault.h
set(CMAKE_CXX_FLAGS "-rdynamic -fnon-call-exceptions -ggdb ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED system_config event_handling)

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
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

###########
## Build ##
###########


## Specify additional locations of header files
## Your package locations should be listed before other locations
 include_directories(include ${catkin_INCLUDE_DIRS})

## Declare a cpp library
 add_library(ttb_worldmodel
   src/TTBWorldModel.cpp
   src/robotmovement/RobotMovement.cpp
   src/sharedworldmodel/TTBSharedWorldModel.cpp
   src/RawSensorData.cpp
   src/Robots.cpp
 )

## Declare a cpp executable
# add_executable(ttb_worldmodel_node src/ttb_worldmodel_node.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(ttb_worldmodel geometry_msgs_generate_messages_cpp system_config)

## Specify libraries to link a library or executable target against
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
