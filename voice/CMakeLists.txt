cmake_minimum_required(VERSION 2.8.3)
project(voice)

# Add path for additional FindXXX.cmake scenarios
set( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_compile_options(-std=c++11)

find_package(catkin REQUIRED sound_play)
find_package(SDL2 REQUIRED)
find_package(Flite REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES voice
  CATKIN_DEPENDS sound_play
#  DEPENDS system_lib
)

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
 ${SDL2_INCLUDE_DIRS}

)

add_executable(${PROJECT_NAME} src/Voice.cpp)

target_link_libraries(${PROJECT_NAME}
   ${catkin_LIBRARIES}
   ${SDL2_LIBRARIES}
)

