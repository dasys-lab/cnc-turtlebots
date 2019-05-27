cmake_minimum_required(VERSION 2.8.3)
project(ttb_base)

## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
  system_config 
  system_util 
  fsystem 
  autodiff 
  id_ros
  event_handling 
  alica_engine 
  alica_ros_proxy 
  ttb_expressions 
  ttb_worldmodel
  robot_control 
  tf
  asp_solver_wrapper
  asp_solver
  alica_simple_solver
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES 
  CATKIN_DEPENDS alica_engine alica_ros_proxy ttb_expressions ttb_worldmodel asp_solver_wrapper asp_solver id_ros alica_simple_solver
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(ttb_base src/Base.cpp)

target_link_libraries(ttb_base ${catkin_LIBRARIES} clingo)
