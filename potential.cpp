#include "potential.h"
#include <iostream>
#include <cmath>
using namespace std;

double h=1/pow(10.,7);

//void potential::setV(double x[]);
double potential::getV(double x[]){
  return 0;
}
void potential::gradientV(double x[],double gradV[]){
  for (int i = 0; i < DIM; i++) {
    for (int i = 0; i < DIM; i++) {
      xx[i]=x[i];
    }
    xx[i]+=h;
    gradV[i]=(getV(xx)-getV(x))/(h);
    }
}
void potential::acceleration(double x[]){
  double gradV[DIM];
  gradientV(x,gradV);
  for (int i = 0; i < DIM; i++) {
    a[i]=-gradV[i];
  }
}
void potential::printV(){
  cout << "    " << V << endl;
}
