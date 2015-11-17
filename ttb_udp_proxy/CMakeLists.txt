cmake_minimum_required(VERSION 2.8.3)
project(ttb_udp_proxy)

## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11  ${CMAKE_CXX_FLAGS}")

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  alica_ros_proxy
  roscpp
  roslib
  system_config
  udp_proxy_generator
)

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS system filesystem regex)


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
#  INCLUDE_DIRS include
#  LIBRARIES ttb_udp_proxy
  CATKIN_DEPENDS alica_ros_proxy roscpp roslib system_config udp_proxy_generator
  DEPENDS system filesystem regex
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS} ${Boost_INCLUIDE_DIRS}
)

# Please note, that the following command does not work, if you compile your workspace the first time, because rosrun does not know anything about udp_proxy_generator in that case.
# We could exchange the command with something more ROS-Independent, like calling the binary without rosrun.
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/proxy_gen/ros2udpProxy.cpp
    #COMMAND rosrun udp_proxy_generator udp_proxy_generator ${PROJECT_NAME}
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/../../../devel/lib/udp_proxy_generator/udp_proxy_generator ${PROJECT_NAME}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/relayMsgs.conf ${udp_proxy_generator_LIBRARIES}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "${PROJECT_NAME}: Generating Code ..."
)

## Declare a cpp executable
add_executable(${PROJECT_NAME}
  proxy_gen/ros2udpProxy.cpp
)

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${Boost_LIBRARIES})

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(${PROJECT_NAME} ${catkin_LIBRARIES} ${Boost_LIBRARIES} process_manager_generate_messages_cpp)
