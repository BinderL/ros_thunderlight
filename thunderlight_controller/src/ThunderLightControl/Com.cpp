/*
  Com - Library for controlling Thunder Light in "Atelier Franck Genser" Thunder Light project.
  Created by Quentin Marmouget, binders@laposte.net.
  This class is design for sending DMX on a serial port : we use the RS485 protocole for sending data to arduino shield for each channel.
*/

#include <ThunderLightControl/Com.h>

Com::Com()
{

}


Com::~Com()
{
  
}


void Com::setArg(int argc, char **argv)
{
//  ros::init(argc, argv, "talker");

//  ros::NodeHandle n;
  
//  chatter_pub = n.advertise<std_msgs::Int32>("chatter", 1000);

}


// assume tab is organised as follow : 
// tab[0] : canal 1
// tab[1] : canal 2
// tab[2] : canal 3
// tab[3] : canal 4
// tab[4] : canal 5
// tab[5] : canal 6
// tab[6] : canal 1 for next independent strip (to robustify)

void Com::sendDMXOrderToSim(int tab[], int size_tab) 
{
//  std_msgs::Int32 msg;
//  msg.data = tab[0];
//  std::stringstream ss;
//  ss << " 1; " << msg.data;
//  ROS_INFO("%i", msg.data);
//  chatter_pub.publish(msg);
//  loop_rate.sleep();

//  for(int i=1; i <  size_tab + 1; i++)
//  {
//    std_msgs::Int32 Data = tab[i-1];
//    DmxSimple.write(i, tab[i-1]);
//  }

}


