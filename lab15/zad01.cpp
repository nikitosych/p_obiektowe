#include <iostream>
#include <deque> // 91441 % 4 = 1
#include <map>
#include <fstream>
#include <vector>



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
Pracownik(string wydzial, string funkcja, string imie, string nazwisko, bool kierownik, bool kobieta) 
{
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

inline static map<string, string> funkcje = {
  {"prof", "Profesor"},
  {"dr_hab", "Doktor habilitowany"},
  {"dr", "Doktor"},
  {"mgr", "Magister"}
};

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
};

int main() 
{
  return 0;
}