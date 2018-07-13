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

  float c = sqrt(T/P);

  int nx = 300;

  float minx = 0.0;

  float maxx = L;

  float dx = (maxx-minx)/(nx);

  float x[nx];

  x[0] = minx;

  for (int a = 1; a < nx; a++){

    x[a] = x[a-1] + dx;
    
  }


  float mint = 0.0;

  float maxt = 200.0;

  float dt = (dx)/(2.0*c);

  int nt = (maxt - mint)/(dt); 


  float u_pasado[nx];
  
  u_pasado[0] = 0.0;

  u_pasado[nx-1] = 0.0;

  for (int b = 0; b < nx; b++){

    u_pasado[b] = 5.0 - (5.0)*(x[b])*(1.0/L);

      if(x[b] <= 0.8*L){

        u_pasado[b] = (1.25)*(x[b])*(1.0/L);

      }
  cout << x[b] << "  " << u_pasado[b] << endl;

  }


  float r = pow ((dt*c)/(dx), 2);


  float u_futuro[nx];

  u_futuro[0] = 0.0;

  u_futuro[nx-1] = 0.0;


  float u_presente[nx];

  u_presente[0] = 0.0;

  u_presente[nx-1] = 0.0;


  for (int q = 1; q < nx-1; q++){

    u_presente[q] = u_pasado[q] + (r)*(u_pasado[q+1]-2.0*u_pasado[q]+u_pasado[q-1]);

  }



  for (int j = 0; j < nt; j++){

    for(int i = 1; i < nx-1; i++){

      u_futuro[i] = (r)*(u_presente[i+1]-2.0*u_presente[i]+u_presente[i-1]) + 2.0*u_presente[i] - u_pasado[i];


    }  

    for (int k = 0; k < nx; k++){

      u_pasado[k] = u_presente[k];

      u_presente[k] = u_futuro[k];

      if(j== 100){

      cout << x[k] << "  " << u_presente[k] << endl;

      }
    }


  }

    return 0;
  
}