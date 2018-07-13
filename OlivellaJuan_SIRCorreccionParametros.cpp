#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>


#define B 0.002
#define G 0.2


using std::cout;
using std::endl;
using std::abs;


float susceptible(float bb, float gg, float tt, float ii, float ss);

float infeccion(float bb, float gg, float tt, float ii, float ss);

float recuperado(float bb, float gg, float tt, float ii, float ss);


int main(){


  float maxn = 50.0;

  int minn = 0;

  int puntos = 1000;

  float maxi = -1000.0;

  float maxt = -1000.0;

  float h = (maxn)/(puntos);

  float t[puntos];

  float s[puntos];

  float i[puntos];

  float r[puntos];

  t[0] = 0.0;

  s[0] = 770.0;
  
  i[0] = 1.0;

  r[0] = 0.0;

  t[1] = t[0] + h;

  s[1] = s[0] + h*(susceptible(B, G, t[0], i[0], s[0]));

  i[1] = i[0] + h*(infeccion(B, G, t[0], i[0], s[0]));

  r[1] = r[0] + h*(recuperado(B, G, t[0], i[0], s[0]));


  for(int j = 2; j < puntos; j++){

    t[j] = t[j-1] + h;

    s[j] = s[j-2] + 2*h*(susceptible(B, G, t[j-1], i[j-1], s[j-1]));

    i[j] = i[j-2] + 2*h*(infeccion(B, G, t[j-1], i[j-1], s[j-1]));

    r[j] = r[j-2] + 2*h*(recuperado(B, G, t[j-1], i[j-1], s[j-1]));

    if(i[j] > maxi){

      maxi = i[j];

      maxt = t[j];

    } 
 

    if(i[j] < 0){

      i[j] = 0;

    }  
  }

  for (int w = 0; w < puntos; w++){

  cout << i[w] << "  " << t[w] << "  " << maxi << "  " << maxt << endl;

  }

  return 0;

}


float susceptible(float bb, float gg, float tt, float ii, float ss){

  return (-1.0)*(bb)*(ii)*(ss);

}

float infeccion(float bb, float gg, float tt, float ii, float ss){

  return (bb)*(ii)*(ss) + (-1.0)*(gg)*(ii);

}


float recuperado(float bb, float gg, float tt, float ii, float ss){

  return (gg)*(ii);

}