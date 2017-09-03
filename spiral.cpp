#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include "potential.h"
#include "Kepler.h"
#include "Isochrone.h"
#include "star.h"


#define DIM 3
	

int main() {

/*              SET PARAMETERS              */
//////////////////////////////////////////////
/*define Time, initial time step*/
   double T=1000.0;
   double dt0=0.0001;
/*define star name*/
   star echidna;
/*uncomment the type of potential to use*/
   Kepler pot;
   //Isochrone pot ;
/*define xin values, vin values*/
   double xin[DIM]={10,100,0};
   double vin[DIM]={100,100,0};
   echidna.setall(xin,vin);
///////////////////////////////////////////////

   

//sets V, a, E (E0) at given initial conditions
   pot.setV(xin);
   pot.acceleration(xin);
   echidna.setE(pot.V);
   echidna.E0=echidna.E;

//leapfrog iteration
   double t=0.0;
   double dt=dt0;
   int count=0;
   while (t<T){	  

     echidna.step1(dt);

     pot.setV(echidna.x);
     pot.acceleration(echidna.x);

     echidna.step2(pot.a,dt);

     //timestep adaptation --> for fixed timestep, uncomment ddt=dt in star.cpp     
     echidna.timestep(echidna.x,echidna.v,dt,dt0);

     t+=0.5*(dt+echidna.ddt);

     echidna.step2(pot.a,echidna.ddt);
     echidna.step1(echidna.ddt);

     pot.setV(echidna.x);

     dt=echidna.ddt;
		
     //value output --> set desired output frequency
     count++;
     if (count%10000==5000){
       echidna.setE(pot.V);
       echidna.printall(t);
     }

   }
}
