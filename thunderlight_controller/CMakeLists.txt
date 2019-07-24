cmake_minimum_required(VERSION 2.8.3)
project(thunderlight_controller)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare ROS messages and services
add_message_files(FILES Num.msg)
add_service_files(FILES stripData.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(DMX_talker src/DMX_talker.cpp)
target_link_libraries(DMX_talker ${catkin_LIBRARIES})

add_library(thunderLight 
  src/ThunderLightControl/LightController.cpp
  src/ThunderLightControl/Strip.cpp
  src/ThunderLightControl/Topos.cpp
)
target_link_libraries(DMX_talker thunderLight)

add_dependencies(DMX_talker thunderlight_controller_generate_messages_cpp)





