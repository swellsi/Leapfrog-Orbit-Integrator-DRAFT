#include "star.h"
#include <iostream>
#include <cmath>
using namespace std;

void star::setx(double xin[DIM]){
  for (int i = 0; i < DIM; i++) {
    x[i] = xin[i];
  }
}
void star::setv(double vin[DIM]){
  for (int i = 0; i < DIM; i++) {
    v[i] = vin[i];
  } 
}
void star::setall(double xin[DIM], double vin[DIM]) {
  for (int i = 0; i < DIM; i++) {
    x[i] = xin[i]; v[i] = vin[i];
  }
}
void star::printall(double ti){
  cout << ti;
  for (int i = 0; i < DIM; i++) {
    cout << "  " << x[i];
  }
  for (int i=0; i<DIM; i++){
    cout<<" "<< v[i];
  }
  cout <<"         "<<E0<<"  "<<E<<"  "<<(E-E0)/E0<< "\n";
}  
void star::printallCC(double ti){
  cout << ti;
  double CCr2=0.0;
  for (int i=0; i<(DIM-1); i++){
    CCr2+=x[i]*x[i];
  }
  CCr=sqrt(CCr2);
  cout<<"  "<<CCr;
  cout <<" "<< x[3];
  double CCvr2=0.0;
  for (int i=0; i<(DIM-1); i++){
    CCvr2+=v[i]*v[i];
  }
  CCvr=sqrt(CCvr2);

  cout<<"  "<<CCvr;
  cout<<" "<< v[3];

  cout <<"  "<<(E-E0)/E0<< "\n";
}

void star::step1(double dt){
  for (int i=0; i<DIM; i++){
    x[i]+=v[i]*0.5*dt;
  }
}

void star::step2(double acceleration[DIM], double dt){
  for (int i=0; i<DIM; i++){
    v[i]+=acceleration[i]*dt*0.5;
  }
}

void star::timestep(double position[DIM], double velocity[DIM], double dt, double dt0){
  double r2=0.0;
  double v2=0.0;
  for (int i=0; i<DIM; i++){
    r2+=position[i]*position[i];
    v2+=velocity[i]*velocity[i];
  }
  //ddt=dt;
  ddt=(sqrt((r2/v2)))*2/pow(10.,3)-dt;
  if(ddt>dt0){ddt=dt0;};
}

void star::setE(double potential){
  double v2=0.0;
  for (int i=0; i<DIM; i++){
    v2+=v[i]*v[i];

  }
  E=0.5*v2+potential;
}


