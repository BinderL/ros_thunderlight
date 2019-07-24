#include "ros/ros.h"
#include <ros/console.h>
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"

#include <sstream>
#include <ThunderLightControl/LightController.h>
#include <ThunderLightControl/Strip.h>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "DMX_talker");

  ros::NodeHandle n;

  ros::Rate loop_rate(10);

  LightController _Controller(&n);

  while (ros::ok())
  {
    _Controller.startController();
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

