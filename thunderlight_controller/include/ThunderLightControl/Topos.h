/*
  Topos - Library for controlling Thunder Light in "Atelier Franck Genser" Thunder Light project.
  Created by Quentin Marmouget, binders@laposte.net.
  This main class aims at giving information about how the independents strips are set and geometrical disposed on the space.
  this class should implement :
  _ Position strips translation(x,y), rotation (ez on (x,y) plan) (the simple version of thunder lamp are in 2D) CF URDF model -> the positions are relatives to the precedent joint. 
  _ The interaction graph to know how strips are connected  
  _ this class should allow to parse config files, URDF models  
*/

#ifndef Topos_h
#define Topos_h

#include "Strip.h"
#include <vector>

class Topos
{
public:

  Topos();
  ~Topos();
  void startComputing(void);
  void buildingNode(int ID_tab[], bool link_tab[], int howManyElement_tab[]);
  void SetServerParam(ros::NodeHandle* n) ;


public:
  ros::NodeHandle* _n = nullptr;
  std::vector<Strip> strip_tab;

};

#endif
