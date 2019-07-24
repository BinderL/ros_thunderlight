/*
  Strip - Library for controlling Thunder Light in "Atelier Franck Genser" Thunder Light project.
  Created by Quentin Marmouget, binders@laposte.net.
  This class provid sustainable control of one independent Strip :
	_ A strip is composed of 8 dependents strips  
*/

#ifndef Strip_h
#define Strip_h

#include "ros/ros.h"
#include <sstream>
#include <string>
#include <math.h>
#include <ros/console.h>
#include "std_msgs/Float64.h"
#include "std_msgs/Int32.h"


class Strip
{
public:

  int CANAL = 6;
  int size_element = 300; // assume size of one element is 300mm
  int quantification = 100;
  float offset = 120;

  Strip(int ID, int howManyElement, int ID_antecedent);
  ~Strip();
  void ComputeDMXorder(void);
  void SetServerParam(ros::NodeHandle* n); 
  void sendDMXTrameToGui(void);

public:
  int _ID;
  int ID_antecedent;
  bool first_strip = false;
  int _length;
  int _Element; // how many dependent element in one strips
  int DMXorder_tab[6];
  float _sumPI;
  ros::NodeHandle* _n = nullptr;
  ros::Publisher DMX_Canal1_pub;


};

#endif
