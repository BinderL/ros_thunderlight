cmake_minimum_required(VERSION 2.8.3)
project(thunderlight_controller)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare ROS messages and services
add_message_files(FILES Num.msg)
add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})

add_library(thunderLight 
  src/ThunderLightControl/LightController.cpp
  src/ThunderLightControl/Strip.cpp
  src/ThunderLightControl/Com.cpp
)
target_link_libraries(talker thunderLight)

add_dependencies(talker beginner_tutorials_generate_messages_cpp)





