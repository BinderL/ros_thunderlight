/*
  Com - Library for controlling Thunder Light in "Atelier Franck Genser" Thunder Light project.
  Created by Quentin Marmouget, binders@laposte.net.
  This class is design for sending DMX on a serial port : we use the RS485 protocole for sending data to arduino shield for each channel.
*/

#ifndef Com_h
#define Com_h

#include "std_msgs/Int32.h"
#include "ros/ros.h"
#include <sstream>


class Com
{
public:

  Com();
  ~Com();
  void sendDMXOrderToSim(int tab[], int size_tab);
public:
  double frequency = 10;

  int _PIN = 3;
  void setArg(int argc, char **argv);

  

};

#endif
