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
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;
  
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("chatter", 1000);

  ros::Rate loop_rate(10);

  // Set up Controller
  //LightController _Controller(argc, argv);
  int _strip_size = 1;
  Strip strip_tab[1];

  while (ros::ok())
  {
    //_Controller.startController();
    

    for(int i=0; i<_strip_size; i++)
    {
      strip_tab[i].ComputeDMXorder();
      std_msgs::Int32 msg;
      msg.data = strip_tab[i].DMXorder_tab[0];
      ROS_INFO("%i", msg.data);
      chatter_pub.publish(msg);

//      sendDMXTrame(strip_tab[i].DMXorder_tab, int(strip_tab[i].CANAL));
    }


    

    ros::spinOnce();
    loop_rate.sleep();
    
  }
  return 0;
}

