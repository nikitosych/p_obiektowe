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
      .licznik = a.licznik + b.licznik, 
      .mianownik = a.mianownik
    };
  } 

  int w = nww(a.mianownik, b.mianownik);
  
  return {
    .licznik = (a.licznik*(w/a.mianownik)) + (b.licznik*(w/b.mianownik)),
    .mianownik = w
  };
}

ulamek subtract(ulamek a, ulamek b) {
  return add(a, {
    .licznik = -1 * b.licznik,
    .mianownik = b.mianownik
  });
}

int main() {
  ulamek wynikAdd = add({2, 2}, {4, 2});
  
  wynikAdd.skroc();

  ulamek wynikSub = subtract({2,2}, {4,2});
  
  std::cout << nwd(24, 18) << '\n';
  std::cout << nww(24, 18) << '\n';
  std::cout << wynikAdd.licznik << '/' << wynikAdd.mianownik << '\n';
  std::cout << wynikSub.licznik << '/' << wynikSub.mianownik << '\n';
  return 0;
}