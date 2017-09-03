#include "Kepler.h"
#include <iostream>
#include <cmath>
using namespace std;

#define DIM 3

double G=6.67408*pow(10.,6);
double M=1;

void Kepler::gradientV(double x[],double gradV[]){
  potential::gradientV(x,gradV);
}
void Kepler::acceleration(double x[]){
  potential::acceleration(x);
}
void Kepler::setV(double x[]){
 double r2=0.0;
 for (int i=0;i<DIM;i++){
   r2+=x[i]*x[i];
 }
              
 V=-G*M/sqrt(r2);
}
double Kepler::getV(double x[]){
double r2=0.0;
for (int i=0;i<DIM;i++){
  r2+=x[i]*x[i];
 }
V=-G*M/sqrt(r2);
return V; 
}
void Kepler::printV(){
  potential::printV();
}
