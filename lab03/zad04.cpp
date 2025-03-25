#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

class trojkat {
private:
  double x, y, z, pole;
public:
  trojkat() {
    this->x = 3;
    this->y = 4;
    this->z = 5;
  }

  void czytaj_dane () {
    cout << "Wprowadz wartosc boku x: ";
    cin >> this->x;
    cout << "\nWprowadz wartosc boku y: ";
    cin >> this->y;
    cout << "\nWprowadz wartosc boku z: ";
    cin >> this->z;
    cout << '\n';
  }

  void przetworz_dane () {
    double p = (this->x + this->y + this->z)/2;
    this->pole = sqrt(p*(p-this->x)*(p-this->y)*(p-this->z));
  }

  void wyswetl_wynik () {
    printf("Pole trojkata wynosi %.3f\n", this->pole);
  }
};

int main () {
  trojkat t;
  t.czytaj_dane();
  t.przetworz_dane();
  t.wyswetl_wynik();
  return 0;
}