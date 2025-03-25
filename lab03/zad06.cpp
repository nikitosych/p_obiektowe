#include <iostream>

class bramkarz {
private:
  int liczba;
public:
  bramkarz() {
    this->liczba = 0;
  }
  bramkarz(int liczba) {
    this->liczba = liczba;
  }

  void zwieksz() {
    this->liczba++;
  }
  void zmniejsz() {
    this->liczba--;
  }
  void wypisz() {
    std::cout << "Liczba osob w pomieszczeniu wynosi: " << this->liczba << "\n";
  }
};

int main () {
  bramkarz b1;
  
  b1.wypisz();
  
  b1.zwieksz();
  b1.zwieksz();
  b1.zwieksz();
  
  b1.wypisz();
  
  b1.zmniejsz();
  
  b1.wypisz();
  
  return 0;
  
}