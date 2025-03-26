#include <iostream>
#include <cmath>

class Wektor2D {
private:
  int x, y;
public:
  Wektor2D (double x, double y) {
    this->x = x;
    this->y = y;
  }
  Wektor2D () {
    this->x = 1;
    this->y = 1;
  }
  void ustawSkladowe(double x, double y) {
    this->x = x;
    this->y = y;
  }
  void wypisz() {
    std::cout << "[" << this->x << ", " << this->y << "]\n";
  }
  double liczModul() {
    return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2));
  }
  bool czyProstopadle(Wektor2D wektor = Wektor2D(1,0)) {
    return this->x * wektor.getX() + this->y * wektor.getY() == 0;
  }
  bool czyRownolegle(Wektor2D wektor = Wektor2D(1,0)) {
    double k = this->x / wektor.getX();
    return this->y == wektor.getY() * k;
  }
  double getX () { return this->x; }
  double getY () { return this->y; }
};

int main() {
  Wektor2D w1(1,0);
  w1.wypisz();
  std::cout << w1.liczModul() << "\n";
  Wektor2D w2(1,0);
  std::cout << (w1.czyProstopadle(w2) ? "Prostopadle" : "Nieprostopadle") << "\n";
  std::cout << (w1.czyRownolegle(w2) ? "Rownolegle" : "Nierownolegle") << "\n";

  return 0;
}