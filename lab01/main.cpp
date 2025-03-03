#include <iostream>

int nwd(int a, int b);

struct ulamek {
  int licznik, mianownik;
  void skroc() {
    int d = nwd(licznik, mianownik);
    licznik /= d;
    mianownik /= d;
  };
};

int nwd(int a, int b) {  // Zastosowany algorytm Euklidesa za pomocą rekurencji
  int temp = a % b;

  if(temp != 0) {
    a = b;
    b = temp;
    return nwd(a, b);
  }
  return b;
}

int nww(int a, int b) {
  return (a*b)/nwd(a, b);
}

ulamek add(ulamek a, ulamek b) {
  if (a.mianownik==b.mianownik) {
    return {
      .licznik = a.licznik, 
      .mianownik = a.mianownik
    };
  } 

  int w = nww(a.mianownik, b.mianownik);
  
  return {
    .mianownik = w,
    .licznik = (a.licznik*(w/a.mianownik)) + (b.licznik*(w/b.mianownik))
  };
}

int main() {
  ulamek wynik = add({.licznik = 2, .mianownik = 2}, {.licznik = 4, .mianownik = 2});
  std::cout << nwd(24, 18) << '\n';
  std::cout << nww(24, 18) << '\n';
  std::cout << wynik.licznik << '/' << wynik.mianownik << '\n';
  return 0;
}