
#include <iostream>
#include <cmath>

using namespace std;

class Punkt {
public:
  int x, y;
  Punkt(int x, int y) : x(x), y(y) {}
};

class Figura {
  virtual double liczPole() = 0;
  virtual bool czyRownoramienny() = 0;
};

class Trojkat : public Figura {
private:
  double bok1, bok2, bok3;
  Punkt w1, w2, w3; // wierzcholki trojkata, numer odpowiada numerowi boku

  bool czyTrojkat() {
    if (bok1 <= 0 || bok2 <= 0 || bok3 <= 0)
      return false;
    return true;
  }

public:
  double bok(unsigned short nrBoku) { // getter dla boku
    switch(nrBoku) {
      case 1:
        return bok1;
      case 2:
        return bok2;
      case 3:
        return bok3;
      default:
        throw out_of_range("Sprobowales wypisac bok o numerze poza zakresem ilosci bokow trojkata");
    }
  }

  Punkt w(unsigned short nrWierzcholka) { // getter dla wierzcholka
    switch(nrWierzcholka) {
      case 1:
        return w1;
      case 2:
        return w2;
      case 3:
        return w3;
      default:
        throw out_of_range("Sprobowales wypisac wierzcholek o numerze poza zakresem ilosci wierzcholkow trojkata");
    }
  }

  bool czyRownoramienny() override {
    for (int i = 1; i <= 3; ++i) {
      for (int j = 1; j <= 3; ++j) {
        if (i == j) continue;
        if (bok(i) == bok(j))
          return true;
      }
    }
    return false;
  }

  double liczPole() override {
    const auto p = obwod() / 2;
    return sqrt(p*(p-bok1)*(p-bok2)*(p-bok3));
  }

  double obwod() {
    return bok1 + bok2 + bok3;
  }

  Trojkat(Punkt w1, Punkt w2, Punkt w3) : w1(w1), w2(w2), w3(w3) 
  {
    bok1 = sqrt(pow((w2.x - w1.x), 2) + pow((w2.y - w1.y), 2));
    bok2 = sqrt(pow((w3.x - w2.x), 2) + pow((w3.y - w2.y), 2));
    bok3 = sqrt(pow((w1.x - w3.x), 2) + pow((w1.y - w3.y), 2));

    if (!czyTrojkat())
       throw invalid_argument("Boki musza byc dodatnimi liczbami rzeczywistymi, wiecej od zera.");
  }

  Trojkat() : Trojkat(Punkt(0,0), Punkt(1,0), Punkt(0,1)) {}

  Trojkat(int w1x, int w1y, int w2x, int w2y, int w3x, int w3y) : Trojkat(Punkt(w1x, w1y), Punkt(w2x, w2y), Punkt(w3x, w3y)) {}

  ~Trojkat() {
    cout << "Destruktor wywolany" << endl;
  }

  void operator* (double s) {
    bok1 *= s;
    bok2 *= s;
    bok3 *= s;
  }

  Trojkat operator* (Trojkat t) {
    return Trojkat(Punkt(0,0), Punkt(t.bok1, 0), Punkt(0, t.bok2));
  }
};

class Graniastoslup : public Figura {
private:
  Trojkat podstawa;
  double wysokosc;

public:
  double liczObjetosc() {
    return podstawa.liczPole() * wysokosc;
  }

  void opiszBryle() {
    cout << "Bryla jest graniastoslupem o podstawie bedacej trojkatem o polu " << podstawa.liczPole() << " i wysokosci " << wysokosc << endl;
  }

  double liczPole() override {
    return 2 * podstawa.liczPole() + podstawa.obwod() * wysokosc;
  }

  bool czyRownoramienny() override {
    return podstawa.czyRownoramienny();
  }

  
  Graniastoslup(Trojkat podstawa, double wysokosc) : podstawa(podstawa), wysokosc(wysokosc) {}
};


int main() {
  Trojkat t(Punkt(0,0), Punkt(0,1), Punkt(1,0));
  cout << t.liczPole() << endl;
  t * 2;
  cout << t.liczPole() << endl;
  cout << t.czyRownoramienny() << endl;

  Graniastoslup g(Trojkat(), 1);
  g.opiszBryle();
  cout << "Objetosc Graniastoslupa wynosi " << g.liczObjetosc() << endl;
  
  Figura *figury[3] = {new Trojkat(0,0,0,1,1,0), new Trojkat(0,0,0,1,1,1), new Trojkat(0,0,1,0,1,1)};

  Trojkat t2 = t * Trojkat(Punkt(2,3), Punkt(4,3), Punkt(4, 5));

  cout << t2.liczPole() << endl;
  cout << t2.czyRownoramienny() << endl;
  cout << t2.obwod() << endl;
  
  return 0;
}
