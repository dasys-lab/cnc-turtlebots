cmake_minimum_required(VERSION 2.8.3)
project(slplanner)

## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
if (${CMAKE_EXTRA_GENERATOR} MATCHES "Eclipse CDT4")
	set(CMAKE_CXX_COMPILER_ARG1 "-std=c++11" CACHE STRING "C++ version for eclipse" FORCE)
	set(CMAKE_ECLIPSE_VERSION "4.5" CACHE STRING "Eclipse version" FORCE)
	add_definitions (-DCMAKE_ECLIPSE_GENERATE_SOURCE_PROJECT=TRUE)
endif (${CMAKE_EXTRA_GENERATOR} MATCHES "Eclipse CDT4")

find_package(catkin REQUIRED COMPONENTS
  nav_core
  costmap_2d
  base_local_planner
  geometry_msgs
  pluginlib
)

catkin_package(
   INCLUDE_DIRS include
   LIBRARIES slplanner
#  CATKIN_DEPENDS nav_core
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
  src/SimpleLocalPlanner.cpp
)

target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

