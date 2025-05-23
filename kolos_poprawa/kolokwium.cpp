#include <iostream>
#include <cmath>

using namespace std;

class Punkt {
public:
  int x, y;
  Punkt(int x, int y) : x(x), y(y) {}
};

class Trojkat {
private:
double bok1, bok2, bok3;

Punkt w1, w2, w3; // wierzcholki trojkata, numer odpowiada numerowi boku

bool czyTrojkat() {
  if (bok1 <= 0 || bok2 <= 0 || bok3 <= 0)
    return false;

  return true;
}

public:
double bok(unsigned short nrBoku) {// getter dla boku
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
};

double w(unsigned short nrWierszcholku) {// getter dla wierzcholka
  switch(nrWierszcholku) {
    case 1:
      return w1;
    case 2:
      return w2;
    case 3:
      return w3;
    default:
      throw out_of_range("Sprobowales wypisac wierzcholek o numerze poza zakresem ilosci wierzcholkow trojkata");
  }

bool czyRownoramienny(void) {
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
      if (i == j) continue;

      if (bok(i) == bok(3))
        return true;
    }
  }

  return false;
}

double liczPole(void) {
  const auto p = obwod() / 2;
  
  return sqrt(p*(p-bok1)*(p-bok2)*(p-bok3));
}

double obwod() {
  return bok1 + bok2 + bok3;
}

Trojkat(double bok1, double bok2, double bok3) : bok1(bok1), bok2(bok2), bok3(bok3) {
  if (!czyTrojkat())
    throw invalid_argument("Boki musza byc dodatnimi liczbami rzeczywistymi, wiecej od zera.");
}

Trojkat() : Trojkat(1,1,1) {}
};

int main() {
  Trojkat t(2, 3, 4);
  Trojkat d(2, 3, 3);

  cout << d.czyRownoramienny() << endl;
  cout << t.liczPole() << endl;

  
  return 0;
}