cmake_minimum_required(VERSION 2.8.3)
project(turtle_base)

## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED roscpp system_config fsystem autodiff event_handling alica_engine alica_ros_proxy turtle_expressions turtle_worldmodel nodelet pluginlib)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES alica_engine turtle_expressions turtle_base turtle_base_nodelet
  CATKIN_DEPENDS alica_engine alica_ros_proxy turtle_expressions turtle_worldmodel
#  DEPENDS tinyxml
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(include ${catkin_INCLUDE_DIRS})

## Declare a cpp library
# add_library(msl_base
#   src/${PROJECT_NAME}/turtle_base.cpp
# )

## Declare a cpp executable
add_executable(turtle_base_node 
	src/BaseNode.cpp
)

add_library(turtle_base
	src/Base.cpp
)

target_link_libraries(turtle_base ${catkin_LIBRARIES} alica_engine alica_ros_proxy
turtle_expressions turtle_worldmodel)

## Specify libraries to link a library or executable target against
target_link_libraries(turtle_base_node ${catkin_LIBRARIES} turtle_base)

add_library(turtle_base_nodelet 
	src/BaseNodelet.cpp
)

target_link_libraries(turtle_base_nodelet ${catkin_LIBRARIES} turtle_base)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(turtle_base_node turtle_base_generate_messages_cpp alica_engine alica_ros_proxy
turtle_expressions turtle_worldmodel)

install(TARGETS turtle_base_nodelet
        DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(TARGETS turtle_base
        DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)


