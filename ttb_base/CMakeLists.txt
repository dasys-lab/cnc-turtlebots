cmake_minimum_required(VERSION 2.8.3)
project(ttb_base)

## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC ${CMAKE_CXX_FLAGS}")

## Enable exception handling for segfaults
set(CMAKE_CXX_FLAGS "-rdynamic -g -fnon-call-exceptions -ggdb ${CMAKE_CXX_FLAGS}")

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS 
  roscpp 
  system_config 
  system_util 
  fsystem 
  autodiff 
  agent_id
  event_handling 
  alica_engine 
  alica_ros_proxy 
  ttb_expressions 
  ttb_worldmodel
  robot_control 
  tf 
  asp_commons
  asp_solver_wrapper
  asp_solver
  alica_simple_solver
)

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
  LIBRARIES 
  CATKIN_DEPENDS alica_engine alica_ros_proxy ttb_expressions ttb_worldmodel asp_commons asp_solver_wrapper asp_solver agent_id alica_simple_solver
#  DEPENDS tinyxml
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(include ${catkin_INCLUDE_DIRS})

## Declare a cpp executable
add_executable(ttb_base src/Base.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(ttb_base ${catkin_LIBRARIES} clingo)
