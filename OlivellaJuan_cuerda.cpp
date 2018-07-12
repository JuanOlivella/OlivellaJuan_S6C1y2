#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>


#define L 100.0
#define T 40.0
#define P 10.0


using std::cout;
using std::endl;


int main(){

  float C = pow(T/P,0.5);

  int nx = 100;

  float minx = 0.0;

  float maxx = L;

  float dx = (maxx-minx)/(nx);

  float x[nx];

  x[0] = minx;

  x[nx] = maxx; 

  for (int i = 1; i < nx; i++){

    x[i] = x[i-1] + dx;
    
  }


  float mint = 0.0;

  float maxt = 200.0;

  float dt = dx/(2.0*C);

  int nt = (maxt - mint)/(dt); 


  float u[nx];

  for (int i = 0; i < nx; i++){

    u[i] = 5.0 - (5.0)*(x[i])*(1/L);

      if(x[i] <= 0.8*L){

        u[i] = (1.25)*(x[i])*(1/L);
      }
    
    cout << x[i] << "  " << u[i] << endl;

  }


  float r = (dt*C)/(dx);

  u[0] = 0.0;

  u[nx-1] = 0.0;

  float u_futuro[nx];

  u_futuro[0] = 0.0;

  u_futuro[nx-1] = 0.0;

  for (int i = 1; i < nx-1; i++){

    u_futuro[i] = u[i] + (0.5)*(r)*(r)*(u[i+1]-2*u[i]-u[i-1]);



  }


  float u_pasado[nx];

  for (int i = 0; i < nx; i++){

    u_pasado[i] = u[i];


  }  


  float u_presente[nx];
  
  for (int i = 0; i < nx; i++){

    u_presente[i] = u_futuro[i];

  }



  for (int j = 0; j < nt; j++){

    for(int i = 1; i < nx-1; i++){

      u_futuro[i] = (r)*(r)*(u_presente[i+1] - 2*u_presente[i] + u_presente[i-1]) +2*u_presente[i]-u_pasado[i];


    }  

    for (int i = 0; i < nx; i++){

      u_pasado[i] = u_presente[i];

    }

    for (int i = 0; i < nx; i++){

      u_presente[i] = u_futuro[i];

      if(j==0){

        cout << x[i] << "  " << u_presente[i] << endl;

      }


    }



  }
  
}