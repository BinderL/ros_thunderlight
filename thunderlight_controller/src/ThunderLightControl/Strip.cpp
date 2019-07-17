/*
  Strip - Library for controlling Thunder Light in "Atelier Franck Genser" Thunder Light project.
  Created by Quentin Marmouget, binders@laposte.net.
  This class provid sustainable control of one independent Strip :
	_ A strip is composed of 8 dependents strips  
*/

#include <ThunderLightControl/Strip.h>
#include <math.h>
#include <ros/console.h>
#include "std_msgs/Float64.h"

#define PI 3.14159265

Strip::Strip()
{
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
