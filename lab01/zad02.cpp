
#include <iostream>
#include <cmath>

struct punkt {
  int x, y;
};

struct trojkat {
  punkt punkty[3];

  double dlugosc(punkt f, punkt s) { 
    // obliczamy długość wektoru fs
    return sqrt(pow(f.x - s.x, 2) + pow(f.y - s.y, 2));
  }

  double obwod() {
    return                            // dla prz. trójkątu ABC
      dlugosc(punkty[0], punkty[1]) + // |AB|
      dlugosc(punkty[1], punkty[2]) + // |BC|
      dlugosc(punkty[2], punkty[0]);  // |AC|
  }
  
  double pole() {
    // P = sqrt(p(p-a)(p-b)(p-c))
    double p = obwod()/2;
    double a = dlugosc(punkty[0], punkty[1]);
    double b = dlugosc(punkty[1], punkty[2]);
    double c = dlugosc(punkty[2], punkty[0]);
    
    return sqrt(p*(p-a)*(p-b)*(p-c));
  }
};

int main() {
  trojkat ABC = {{{1,1},{2,4},{4,1}}};
  std::cout << ABC.obwod() << '\n'  << ABC.pole() << '\n';
  return 0;
}
