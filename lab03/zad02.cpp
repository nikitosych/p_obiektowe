#include <iostream>

using namespace std;

class dowod_osobisty {
public:
  int numer;
  string nazwisko;
  string imie;
  int wzrost;
  string kolor_oczu;
  string PESEL;
};

int main() {
  dowod_osobisty dowod1, dowod2;
  
  dowod1.numer = 1;
  dowod1.nazwisko = "Kowalski";
  dowod1.imie = "Jan";
  dowod1.wzrost = 180;
  dowod1.kolor_oczu = "niebieskie";
  dowod1.PESEL = "01123344555";
  
  dowod2.numer = 2;
  dowod2.nazwisko = "Nowak";
  dowod2.imie = "Anna";
  dowod2.wzrost = 170;
  dowod2.kolor_oczu = "czarne";
  dowod2.PESEL = "01123344556";
  
  return 0;
}