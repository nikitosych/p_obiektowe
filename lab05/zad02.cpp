#include <iostream>
#include <cmath>

class Wektor2D {
private:
  double x, y;
public:
  Wektor2D (double x, double y) {
    this->x = x;
    this->y = y;
  }
  Wektor2D () {
    this->x = 1;
    this->y = 1;
  }
  double operator* (Wektor2D wektor) {
    return this->x * wektor.getX() + this->y * wektor.getY();
  }
  Wektor2D operator* (double k) {
    return Wektor2D(this->x * k, this->y * k);
  }
  bool operator== (Wektor2D wektor) {
    return this->x == wektor.getX() && this->y == wektor.getY();
  }

  // https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170#example
  friend std::ostream& operator<<(std::ostream& os, const Wektor2D& wektor) {
    os << "[" << wektor.x << ", " << wektor.y << "]";
    return os;
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
    if (wektor.getX() == 0) return this->x == 0;
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

  std::cout << (w1 == w2 ? "Wektory sa rowne" : "Wektory sa rozne") << '\n';
  std::cout << ((w1 * w2)*5) << '\n';

  return 0;
}