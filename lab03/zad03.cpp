#include <iostream>

usin namespace std;
// Skonstruuj klasę pies (patrz poprzednie laboratoria) z metodami szczekania i jedzenia.
// Tym razem oczywiście warto uruchomić odpowiedni konstruktor, żeby upewnić się, że
// damy radę zorganizować np. dwa różne psy.

class pies {
public:
  string imie, rasa;
  int wiek;

  pies(string imie, int wiek, string rasa) {
    this->imie = imie;
    this->wiek = wiek;
    this->rasa = rasa;
  }

  void szczekaj() {
    cout << "Hau hau hau";
  }

  void jedz() {
    cout << "Jam jam jam";
  }

};

int main() {
  pies pies1("Ralf", 5, "Labrador");
  pies pies2("Bajkal", 6, "Owczarek");

  pies1.szczekaj();
  pies1.jedz();

  pies2.szczekaj();
  pies2.jedz();
  
  return 0;
}