cmake_minimum_required(VERSION 2.8.3)
project(ttb_msgs)

find_package(catkin REQUIRED COMPONENTS
  message_generation  std_msgs geometry_msgs
)

 add_message_files(
   FILES
   ServeTask.msg
   DoorCmd.msg
   GoalWrapped.msg
   GrabDropObject.msg
   InitialPoseWrapped.msg
   AMCLPoseWrapped.msg
   LogicalCamera.msg
   LogicalCamera3D.msg
   LogicalCamera3DArray.msg
   LogicalCameraImage.msg
   Model.msg
   ObjectSize.msg
 )
 
 generate_messages(DEPENDENCIES std_msgs geometry_msgs)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ttb_msgs
  CATKIN_DEPENDS std_msgs geometry_msgs message_runtime
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

