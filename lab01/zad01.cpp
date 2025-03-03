#include <iostream>

int nwd(int a, int b);

struct ulamek {
  int licznik, mianownik;
  void skroc() {
    int d = nwd(licznik, mianownik);
    licznik /= d;
    mianownik /= d;
  };

  /// <summary>
  /// Pozbywamy się niewłaściwosci i drukujemy wyjście standardowe ułamek mieszany
  /// </summary>
  void mix() {
    if (licznik >= mianownik) {
      int calosc = licznik / mianownik;
      
      licznik = licznik % mianownik;
      
      if (licznik == 0) {
        std::cout << calosc << '\n';
      } 
      else {
        std::cout << calosc << " " << licznik << "/" << mianownik << '\n';
      }
    } 
    else {
      std::cout << licznik << "/" << mianownik << '\n';
    }
  }
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

ulamek add(ulamek a, ulamek b, bool czySkrocic = false) {
  int w = nww(a.mianownik, b.mianownik);
  ulamek wynik;
  
  if (a.mianownik==b.mianownik) {
    wynik = {
      .licznik = a.licznik + b.licznik, 
      .mianownik = a.mianownik
    };
  } 
  else {
    wynik = {
      .licznik = (a.licznik*(w/a.mianownik)) + (b.licznik*(w/b.mianownik)),
      .mianownik = w
    };
  }

  if (czySkrocic) wynik.skroc();
  
  return wynik;
}

ulamek subtract(ulamek a, ulamek b, bool czySkrocic = false) {
  return add(a, {
    .licznik = -b.licznik,
    .mianownik = b.mianownik
  }, czySkrocic);
}

ulamek mult(ulamek a, ulamek b, bool czySkrocic = false) {
  ulamek wynik = {
    .licznik = a.licznik * b.licznik,
    .mianownik = a.mianownik * b.mianownik
  };

  if (czySkrocic) wynik.skroc();
  return wynik;
}

ulamek divide(ulamek a, ulamek b, bool czySkrocic = false) {
  if (b.licznik == 0 || b.mianownik == 0) { 
    // Oczywiście pierwszy ułamek też nie może mieć 0 w mianowniku,
    // ale takie przypadki najlepiej byłoby rozważać w konstruktorze struktury.
    // A gdyz Pan powiedział zrobić te zadania jak możliwie bardziej w "sposób strukturalny"
    // to tym razem będziemy zakładać, ze użytkownik programu jest osobą świadomą i nie będzie
    // i nie będzie stawiać zero w mianowniku :)
    
    std::cout << "ERROR: can't divide by zero (a = " << 
      a.licznik << '/' << a.mianownik << ", b = " <<
      b.licznik << '/' << b.mianownik << ")\n";
    return {0,0};
  }

  ulamek temp_b = {
    .licznik = b.mianownik,
    .mianownik = b.licznik
  };

  return mult(a, temp_b, czySkrocic);
  
}

int main() {
  ulamek wynikAdd = add({2, 2}, {4, 2});
  ulamek wynikSub = subtract({2,2}, {4,2});
  ulamek wynikMult = mult({2,2}, {4,2});
  ulamek wynikDiv = divide({2,2}, {4,2}, true);
  
  std::cout << nwd(24, 18) << '\n';
  std::cout << nww(24, 18) << '\n';
  std::cout << wynikAdd.licznik << '/' << wynikAdd.mianownik << '\n';
  std::cout << wynikSub.licznik << '/' << wynikSub.mianownik << '\n';
  std::cout << wynikMult.licznik << '/' << wynikMult.mianownik << '\n';
  std::cout << wynikDiv.licznik << '/' << wynikDiv.mianownik << '\n';
  wynikMult.mix();
  return 0;
}