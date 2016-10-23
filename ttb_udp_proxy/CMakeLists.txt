cmake_minimum_required(VERSION 2.8.3)
project(ttb_udp_proxy)

## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11  ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
  alica_ros_proxy
  roscpp
  roslib
  system_config
  udp_proxy_generator
  process_manager
  ttb_msgs
  kobuki_msgs
)

find_package(Boost REQUIRED COMPONENTS system filesystem regex)

catkin_package(
  #INCLUDE_DIRS include
  #LIBRARIES ttb_udp_proxy
  CATKIN_DEPENDS alica_ros_proxy roscpp roslib system_config udp_proxy_generator
  #DEPENDS
)

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

add_executable(${PROJECT_NAME}
  proxy_gen/ros2udpProxy.cpp
)

target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${Boost_LIBRARIES})

add_dependencies(${PROJECT_NAME} process_manager_generate_messages_cpp)
