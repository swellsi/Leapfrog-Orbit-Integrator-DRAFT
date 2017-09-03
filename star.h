#ifndef STAR_H
#define STAR_H

#define DIM 3

class star{
 public:
  double x[DIM];
  double v[DIM];
  double ddt;
  double a2;
  double v2;
  double CCr;
  double CCvr;
  double E;
  double E0;

  void setx(double xin[DIM]);
  void setv(double vin[DIM]);
  void setall(double xin[DIM],double vin[DIM]);
  void printall(double ti);
  void printallCC(double ti);
  void step1(double dt);
  void step2(double acceleration[DIM],double dt);
  void timestep(double position[DIM],double velocity[DIM],double dt,double dt0);
  void setE(double potential);
};

#endif
