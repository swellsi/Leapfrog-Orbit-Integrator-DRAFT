#include "Isochrone.h"
#include <iostream>
#include <cmath>
using namespace std;


double G=6.67408*pow(10.,6);
double M=1;
double b=50.;

void Isochrone::gradientV(double x[],double gradV[]){
  potential::gradientV(x,gradV);
}
void Isochrone::acceleration(double x[]){
  potential::acceleration(x);
}
void Isochrone::setV(double x[]){
 double r2=0.0;
 for (int i=0;i<DIM;i++){
   r2+=x[i]*x[i];
 }
              
 V=-G*M/(b+sqrt(b+r2));
}
double Isochrone::getV(double x[]){
double r2=0.0;
for (int i=0;i<DIM;i++){
  r2+=x[i]*x[i];
 }
V=-G*M/(b+sqrt(b+r2));
return V; 
}
void Isochrone::printV(){
  potential::printV();
}
