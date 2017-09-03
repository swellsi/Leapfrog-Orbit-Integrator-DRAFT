#ifndef POTENTIAL_H
#define POTENTIAL_H

#define DIM 3

class potential{
 public:
  double V;
  double a[DIM];
  double xx[DIM];
  // double h;

  virtual void setV(double x[])=0;
  virtual double getV(double x[])=0;
  void gradientV(double x[],double gradV[]);
  void acceleration(double x[]);
  void printV();
};

#endif
