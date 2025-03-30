#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

class Zespolona {
public:
  double re, im;

  Zespolona operator+ (Zespolona& z) {
    return this->add(z);
  }

  Zespolona operator- (Zespolona& z) {
    return this->subtract(z);
  }

  Zespolona operator* (Zespolona& z) {
    return this->mult(z);
  }

  Zespolona operator/ (Zespolona& z) {
    return this->divide(z);
  }

  void operator++ () {
    this->re++;
  }

  bool operator< (Zespolona& z) {
    if (this->re != z.re) 
      return this->re < z.re;
    return this->im < z.im;
  }

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
    double kat = this->phi();
    double modul = this->mod();

    std::cout << "z = "
              << modul
              << "(cos(" << kat << ") + isin(" << kat << ")) = "
              << modul << "(" << cos(kat) << " + " << sin(kat) << "i) = "
              << modul * cos(kat) << " + " << modul * sin(kat) << "i\n";
  }

  void printPower(int n) {
    double kat = phi();
    double modul = this->mod();

    std::cout << "z^" << n << " = "
              << modul << "^" << n
              << "(cos(" << kat << ") + isin(" << kat << "))^" << n << " = "
              << modul << "^" << n << "(cos(" << n << "*" << kat << ") + isin(" << n << "*" << kat << "))" << " = "
              << pow(modul, n) << "(" << cos(n*kat) << " + " << sin(n*kat) << "i) = " 
              << pow(modul, n) * cos(n*kat) << " + " << pow(modul, n) * sin(n*kat) << "i\n";

  }

  Zespolona add(Zespolona& z) {
    return {this->re + z.re, this->im + z.im};
  }

  Zespolona subtract(Zespolona& z) {
    return {this->re - z.re, this->im - z.im};
  }

  Zespolona mult(Zespolona& z) {
    return {this->re * z.re - this->im * z.im, this->re * z.im + this->im * z.re};
  }

  Zespolona divide(Zespolona& z) {
    if (z.re == 0 && z.im == 0) std::cout << "UWAGA: dzielisz przez 0 + 0i\n";

    return {(this->re * z.re + this->im * z.im)/(pow(z.re, 2) + pow(z.im, 2)), 
            (z.re * this->im - this->re * z.im)/(pow(z.re, 2) + pow(z.im, 2))};
  }

  // https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
  friend std::ostream& operator<< (std::ostream& os, const Zespolona& z) { // const postawiony tutaj aby moc przekazac tymczasowe wartosci (np. obiekt ktory tworzy metoda z1.divide())
    os << z.re << " + " << z.im << "i\n";
    return os;
  }

  // https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-input-operator-for-your-own-classes?view=msvc-170
  friend std::istream& operator>>(std::istream& is, Zespolona& z) {
    return is >> z.re >> z.im;
  }
  
private:
   double acot(double kat) { // arcctg
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
     else if (re == 0 && im < 0) {
       return -M_PI/2;
     }
     else {
       return nanf(""); // NaN
     }
   } 
};

int main() {
  Zespolona z1;
  z1.re = 1;
  z1.im = sqrt(3);

  Zespolona z2;
  z2.re = sqrt(3);
  z2.im = 1;

  z1.printCan();
  z2.printCan();

  z1.printTrig();
  z2.printTrig();

  std::cout << "\n" << z1.divide(z2) << "\n"; 

  Zespolona z3;
  
  std::cout << "Wprowadz czesc Re i Im:";
  std::cin >> z3;
  std::cout << z2/z3 << "\n";

  return 0;
}