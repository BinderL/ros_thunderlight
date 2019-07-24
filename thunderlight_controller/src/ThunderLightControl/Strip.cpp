/*
  Strip - Library for controlling Thunder Light in "Atelier Franck Genser" Thunder Light project.
  Created by Quentin Marmouget, binders@laposte.net.
  This class provid sustainable control of one independent Strip :
	_ A strip is composed of 8 dependents strips  
*/

#include <ThunderLightControl/Strip.h>


#define PI 3.14159265

Strip::Strip(int ID, int howManyElement, int ID_antecedent)
{
  _ID = ID;
  _Element = howManyElement;
  _length = _Element * size_element;
  if(ID_antecedent == 0)
    first_strip = true;
  _sumPI = 0;
}


Strip::~Strip()
{

}

void Strip::ComputeDMXorder(void)
{ 
  DMXorder_tab[0] = int(100 * sin(_sumPI) + offset);
  DMXorder_tab[1] = 0;
  DMXorder_tab[2] = 0;
  DMXorder_tab[3] = 0;
  DMXorder_tab[4] = 0;
  DMXorder_tab[5] = 0;
  _sumPI = _sumPI + PI/quantification;
  
}

void Strip::sendDMXTrameToGui(void)
{
  std_msgs::Int32 msg;
  msg.data = DMXorder_tab[0];
  ROS_INFO("%i", _ID);
  ROS_INFO("%s", ";"); 
  ROS_INFO("%i", msg.data);
  DMX_Canal1_pub.publish(msg);
}


void Strip::SetServerParam(ros::NodeHandle* n) 
{
  std::stringstream ss;
  ss << _ID;
  std::string str = ss.str();
  _n = n;
  DMX_Canal1_pub = n->advertise<std_msgs::Int32>("DMX_Canal" + str, 1000);
}

