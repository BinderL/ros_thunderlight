/*
  LightController - Library for controlling Thunder Light in "Atelier Franck Genser" Thunder Light project.
  Created by Quentin Marmouget, binders@laposte.net.
  This main class aims at controlling in real time the different strips and synchronised   
*/

#include <ThunderLightControl/LightController.h>


LightController::LightController(int argc, char **argv)
{
  //_Com.setArg(argc, argv);
}

LightController::~LightController()
{

}

void LightController::Setup(void)
{
  
}

void LightController::startController(void)
{
  for(int i=0; i<_strip_size; i++)
  {
    strip_tab[i].ComputeDMXorder();
    sendDMXTrame(strip_tab[i].DMXorder_tab, int(strip_tab[i].CANAL));
  }
}

void LightController::sendDMXTrame(int _tab[], int size_tab)
{
  _Com.sendDMXOrderToSim(_tab, size_tab);
}



