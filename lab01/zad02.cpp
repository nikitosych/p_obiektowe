
#include <iostream>
#include <cmath>

struct punkt {
  int x, y;
};

struct trojkat {
  punkt punkty[3] = {{0,0}, {0,0}, {0,0}};

  double dlugosc(punkt f, punkt s) { 
    // obliczamy długość wektoru fs
    return sqrt(pow(f.x - s.x, 2) + pow(f.y - s.y, 2));
  }

  double obwod() {
    return                            // dla prz. trójkątu ABC
      dlugosc(punkty[0], punkty[1]) + // |AB|
      dlugosc(punkty[1], punkty[2]) + // |BC|
      dlugosc(punkty[0], punkty[2]);  // |AC|
  }

  double pole() {
    // P = sqrt(p(p-a)(p-b)(p-c))
    double p = obwod()/2;
    double a = dlugosc(punkty[0], punkty[1]);
    double b = dlugosc(punkty[1], punkty[2]);
    double c = dlugosc(punkty[0], punkty[2]);

    return sqrt(p*(p-a)*(p-b)*(p-c));
  }
};

int main() {
  // trojkat ABC = {{{1,1},{2,4},{4,1}}};
  // punkt g = {2,2};
  // punkt h = {1,3};

  trojkat ABC;
  punkt p

  std::cout << "Wprowadz wspolrzedna x punktu A trojkatu ABC\n";
  std::cin >> ABC.punkty[0].x;
  std::cout << "Wprowadz wspolrzedna y punktu A trojkatu ABC\n";
  std::cin >> ABC.punkty[0].y;
  
  std::cout << "Wprowadz wspolrzedna x punktu B trojkatu ABC\n";
  std::cin >> ABC.punkty[1].x;
  std::cout << "Wprowadz wspolrzedna y punktu B trojkatu ABC\n";
  std::cin >> ABC.punkty[1].y;

  std::cout << "Wprowadz wspolrzedna x punktu C trojkatu ABC\n";
  std::cin >> ABC.punkty[2].x;
  std::cout << "Wprowadz wspolrzedna y punktu C trojkatu ABC\n";
  std::cin >> ABC.punkty[2].y;

  std::cout << "Wprowadz wspolrzedna x punktu p\n";
  std::cin >> p.x;
  std::cout << "Wprowadz wspolrzedna y punktu p\n";
  std::cin >> p.y;

  

  trojkat ABp = {{ABC.punkty[0], ABC.punkty[1], p}};
  trojkat BCp = {{ABC.punkty[1], ABC.punkty[2], p}};
  trojkat ACp = {{ABC.punkty[0], ABC.punkty[2], p}};

  // trojkat ABh = {{ABC.punkty[0], ABC.punkty[1], h}};
  // trojkat BCh = {{ABC.punkty[1], ABC.punkty[2], h}};
  // trojkat ACh = {{ABC.punkty[0], ABC.punkty[2], h}};
  
  // std::cout << ABC.obwod() << '\n'  << ABC.pole() << '\n';

  if (ABp.pole() + BCp.pole() + ACp.pole() == ABC.pole())
    std::cout << "Punkt p nalezy do ABC\n";
  else std::cout << "Punkt p nie nalezy do ABC\n";

  // if (ABh.pole() + BCh.pole() + ACh.pole() == ABC.pole())
  //   std::cout << "Punkt h nalezy do ABC\n";
  // else std::cout << "Punkt h nie nalezy do ABC\n";
  
  return 0;
}
