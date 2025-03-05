#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

class Zespolona {
public:
  double re, im;

  void getNumber() {
    std::cout << "Wprowadz czesc rzeczywista (Re): ";
    std::cin >> this->re;
    std::cout << "\nWprowadz czesc urojona (Im): ";
    std::cin >> this->im;
    std::cout << '\n';
  }

  void printMod() {
    std::cout << "|z| = " << this->mod() << '\n';
  }

  void printCan() {
    std::cout << "z = " << this->re << " + " << this->im << "i\n";
  }

  void printTrig() {
    // https://pl.wikipedia.org/wiki/Liczby_zespolone#Posta%C4%87_trygonometryczna

    std::cout << "z = " <<
              << 
  }

  void printPower() {
    
  }

private:
   double acot(double kat) {
     return M_PI/2 - atan(kat);
   }
   double mod() {
     return sqrt(pow(this->re, 2) + pow(this->im, 2));
   }
   double phi() {
     if (re > 0) {
       return this->acot(im/re);
     } 
     else if (re < 0 && im >= 0) {
       return this->acot(im/re) + M_PI;
     }
     else if (re < 0 && im < 0) {
       return this->acot(im/re) - M_PI;
     }
     else if (re == 0 && im > 0) {
       return M_PI/2;
     }
     else {
       return nanf(""); // NaN
     }
   } 
}

int main() {
  return 0;
}