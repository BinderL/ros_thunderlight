/*
  Cloud - Library for controlling Thunder Light in "Atelier Franck Genser" Thunder Light project.
  Created by Quentin Marmouget, binders@laposte.net.
  This class provid sustainable control of a Cloud :
	_ A Cloud is a geometrical shape which navigate on 2d (X,Y) plan and dependent on where the cloud is, the light respond to the cloud. 
*/

#ifndef Cloud_h
#define Cloud_h

class Cloud
{
public:


  Cloud();
  ~Cloud(); 
  
  // Setup
  void initCloud(void);

  // Compute
  void computeCloud(void);



public:
  float _kp;
};

#endif
