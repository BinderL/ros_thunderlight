/*
  Topos - Library for controlling Thunder Light in "Atelier Franck Genser" Thunder Light project.
  Created by Quentin Marmouget, binders@laposte.net.
  This main class aims at giving information about how the independents strips are set and geometrical disposed on the space.
  this class should implement :
  _ Position strips translation(x,y), rotation (ez on (x,y) plan) (the simple version of thunder lamp are in 2D) CF URDF model -> the positions are relatives to the precedent joint. 
  _ The interaction graph to know how strips are connected    
*/

#include "ThunderLightControl/Topos.h"

Topos::Topos()
{
  
}

Topos::~Topos()
{
  
}

void Topos::startComputing(void)
{
  for(int i=0; i<3; i++)
  {
    strip_tab[i].ComputeDMXorder();
    strip_tab[i].sendDMXTrameToGui();
  }
}


// first param ID strips 1, ID strips 2, ID strips 3. bool for connection 1 with 2 and for connection 1 with 3 and 2 with 3. longueur d'un strip indépendant 
//hypothése : 3 noeuds interconéctés max


void Topos::buildingNode(int ID_tab[], bool link_tab[], int howManyElement_tab[]) // bool link_tab[]
{
  int InterconnectedNode = 3;
  for(int i = 0; i < InterconnectedNode;i++)
  {
    Strip _strip(ID_tab[i],howManyElement_tab[i], ID_tab[0]);
    _strip.SetServerParam(_n);
    strip_tab.push_back(_strip);
  }
}


void Topos::SetServerParam(ros::NodeHandle* n) 
{
  _n = n;
}





