#ifndef KEPLER_H
#define KEPLER_H
#include "potential.h"

class Kepler:public potential{
  /* private:
  double G;
  double M;*/
 public:
  void gradientV(double x[],double gradV[]);
  void acceleration(double x[]);
  void setV(double x[]);
  double getV(double x[]);
  void printV();
};

#endif
    
  
