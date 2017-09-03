#ifndef ISOCHRONE_H
#define ISOCHRONE_H
#include "potential.h"

class Isochrone:public potential{
  /*private:
  double G;
  double M;
  double b;*/
 public:
  void gradientV(double x[],double gradV[]);
  void acceleration(double x[]);
  void setV(double x[]);
  double getV(double x[]);
  void printV();
};

#endif
