cmake_minimum_required(VERSION 2.8.3)
project(voice)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES voice
#  CATKIN_DEPENDS sound_play
#  DEPENDS flite
)

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/Voice.cpp)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)

