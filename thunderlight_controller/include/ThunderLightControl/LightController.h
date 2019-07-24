/*
  LightController - Library for controlling Thunder Light in "Atelier Franck Genser" Thunder Light project.
  Created by Quentin Marmouget, binders@laposte.net.
  This main class aims at controlling in real time the different strips and synchronised   
*/

#ifndef LightController_h
#define LightController_h

#include "Topos.h"

class LightController
{
public:
  int MIN_PWM_TO_SPIN_MOTOR = 70;


  LightController(ros::NodeHandle* n);
  ~LightController();
  void buildingTopology(void);
  void sendDMXTrame(int _tab[], int size_tab);
  void startController(void);
  void initGuiParameters(void);
  void Setup(void);


public:

  ros::NodeHandle* _n = nullptr;
  Topos _Topos;
};

#endif
