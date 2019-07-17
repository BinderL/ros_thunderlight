/*
  Strip - Library for controlling Thunder Light in "Atelier Franck Genser" Thunder Light project.
  Created by Quentin Marmouget, binders@laposte.net.
  This class provid sustainable control of one independent Strip :
	_ A strip is composed of 8 dependents strips  
*/

#ifndef Strip_h
#define Strip_h


class Strip
{
public:

  int CANAL = 6;
  int quantification = 100;
  float offset = 120;

  Strip();
  ~Strip();
  void ComputeDMXorder(void);

public:

  int DMXorder_tab[6];
  float _sumPI;

};

#endif
