#include <iostream>
#include <deque> // 91441 % 4 = 1
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Pracownik {
private:
  string wydzial;
  string funkcja;
  string imie;
  string nazwisko;
  bool kierownik;
  bool kobieta;

public:
Pracownik(string wydzial, string funkcja, string imie, string nazwisko, bool kierownik, bool kobieta) {
  bool err = true;
  // Sprawdzamy wydzial
  for (auto w : wydzialy) {
    if (wydzial == w.first) {
      err = false;
      break;
    }
  }
  if (err) { 
    throw invalid_argument("Niepoprawny wydzial.");
  }
  this->wydzial = wydzial;

  err = true;
  // Sprawdzamy funkcje
  for (auto f : funkcje) {
    if (funkcja == f.first) {
      err = false;
      break;
    }
  }
  if (err) {
    throw invalid_argument("Niepoprawna funkcja.");
  }
  this->funkcja = funkcja;
  
  this->imie = imie;
  this->nazwisko = nazwisko;
  this->kobieta = kobieta;
  this->kierownik = kierownik;
}

Pracownik(string wydzial, string funkcja, string imie, string nazwisko, bool kierownik = false) : Pracownik(wydzial, funkcja, imie, nazwisko, kierownik, imie[imie.size() - 1] == 'a') {
  // Automatycznie przypisujemy plec w sposób prymitywny
}

string getWydzial() const {
  return wydzial;
}

string getFunkcja() const {
  return funkcja;
}

string getImie() const {
  return imie;
}

string getNazwisko() const {
  return nazwisko;
}

bool isKierownik() const {
  return kierownik;
}

bool isKobieta() const {
  return kobieta;
}

bool operator==(const Pracownik& p) const {
  return (
    this->getWydzial() == p.getWydzial() &&
    this->getFunkcja() == p.getFunkcja() &&
    this->getImie() == p.getImie() &&
    this->getNazwisko() == p.getNazwisko() &&
    this->isKierownik() == p.isKierownik() &&
    this->isKobieta() == p.isKobieta()
  );
}

// prosta funkcja do znalezenia indeksu elementu w deque
// https://www.geeksforgeeks.org/std-find-in-cpp/
static int indexof(Pracownik &target, deque<Pracownik> &deq) {
  auto it = find(deq.begin(), deq.end(), target);

  if (it != deq.end()) {
    return distance(deq.begin(), it);
  } else { return -1; }
}

// Proszę Pana się upewnić że kompilator jest wersji C++17 lub wyżej ze wzgledu na 'inline'
inline static map<string, string> wydzialy = {
  {
    "KMN", "Katedra Metod Numerycznych"
  },
  {
    "ZBI", "Zaklad Bioinformatyki"
  },
  {
    "ZPD", "Zaklad Procesow Dyskretnych"
  },
  {
    "ZIM", "Zaklad Sztucznej Inteligencji i Multimediow"
  },
  {
    "ZPM", "Zaklad Programowania i Metod Formalnych"
  }
  }; 

inline static map<string, int> funkcje = {
  {"prof", 1},
  {"dr_hab", 2},
  {"dr", 3},
  {"mgr", 4}
};

};

enum class rule {
  WYDZIAL, 
  FUNKCJA,
  IMIE,
  NAZWISKO,
  KIEROWNIK,
  NONE
};

class Parser {
public:

static vector<string> split(const string& s, char delimiter = ' ') {
    vector<string> slowy;
    string slowo;

    // czytamy po znaku i dodajemy do slowa,a jak natrafimy na spacje to dodajemy slowo do "slowy" i czyscimy zmienna slowo
    for (char c : s) {
        if (c == delimiter) {
            if (!slowo.empty())
                slowy.push_back(slowo);
            slowo.clear();
        } else {
            slowo += c;
        }
    }
    if (!slowo.empty())
        slowy.push_back(slowo);

    return slowy;
}


static void read(string filename, deque<Pracownik>& buffer) {
  fstream file(filename);
  if (!file.is_open()) {
    throw runtime_error("Nie udalo sie otworzyc pliku");
  }

  string l;
  
  while (getline(file, l) && l != "EOF") {
    auto frags = split(l);
    if (frags.size() < 4) continue;

    bool kierownik = (frags.size() >= 5 && frags[4] == "(kierownik)");
    
    buffer.push_back(Pracownik(frags[0], frags[1], frags[2], frags[3], kierownik));
  }
};

static void sortx(rule rule, deque<Pracownik>& buffer) {
  switch (rule) {
    case rule::WYDZIAL:
      sort(buffer.begin(), buffer.end(), [](Pracownik& a, Pracownik& b) {
        return a.getWydzial() < b.getWydzial();
      });
      break;
    case rule::FUNKCJA:
      sort(buffer.begin(), buffer.end(), [](const Pracownik& a, const Pracownik& b) {
        if (a.isKierownik() != b.isKierownik())
          return a.isKierownik() > b.isKierownik();  // kierownicy w 1 kolejnosci
        return Pracownik::funkcje.at(a.getFunkcja()) < Pracownik::funkcje.at(b.getFunkcja());   // potem według wagi funkcji
      });
    break;
    case rule::IMIE:
      sort(buffer.begin(), buffer.end(), [](Pracownik& a, Pracownik& b) {
        return a.getImie() < b.getImie();
      });
      break;
    case rule::NAZWISKO:
      sort(buffer.begin(), buffer.end(), [](Pracownik& a, Pracownik& b) {
        return a.getNazwisko() < b.getNazwisko();
      });
      break;
    case rule::KIEROWNIK:
      sort(buffer.begin(), buffer.end(), [](Pracownik& a, Pracownik& b) {
        return a.isKierownik() > b.isKierownik();
      });
      break;
    case rule::NONE: // czyli nie sortujemy
      break;
    default: break;
  }
}
};



int main() 
{
  // testujemy
  deque<Pracownik> pracownicy;
  // proszę zmienić ścieżkę do pliku na właściwą na Pana komputerze
  Parser::read("lab15/wi_uwb.txt", pracownicy);
  Parser::sortx(rule::FUNKCJA, pracownicy);
  for (auto p : pracownicy)
  cout << (p.isKobieta() ? "Pani" : "Pan") << " " << p.getImie() << " " << p.getNazwisko() << " " << p.getWydzial() << " " << p.getFunkcja() << " " << (p.isKierownik() ? "KIEROWNIK" : "") << endl;
  
  return 0;
}