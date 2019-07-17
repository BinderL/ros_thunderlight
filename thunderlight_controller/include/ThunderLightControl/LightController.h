/*
  LightController - Library for controlling Thunder Light in "Atelier Franck Genser" Thunder Light project.
  Created by Quentin Marmouget, binders@laposte.net.
  This main class aims at controlling in real time the different strips and synchronised   
*/

#ifndef LightController_h
#define LightController_h

#include "Com.h"
#include "Strip.h"

class LightController
{
public:
  int MIN_PWM_TO_SPIN_MOTOR = 70;
  int _strip_size = 1; //improve : allocation dynamique

  LightController(int argc, char **argv);
  ~LightController();
  void sendDMXTrame(int _tab[], int size_tab);
  void startController(void);
  void Setup(void);


public:
  Com _Com;
  Strip strip_tab[1];
};

#endif
