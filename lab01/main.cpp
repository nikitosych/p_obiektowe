#include <iostream>

using namespace std;

struct ulamek {
  int licznik, mianownik;
  void skroc() {
    int d = nwd(licznik, mianownik);
    licznik /= d;
    mianownik /= d;
  };
};

int nwd(int a, int b) {
  // Zastosowany algorytm Euklidesa za pomocą rekurencji

  int temp = a % b;

  if(temp != 0) {
    a = b;
    b = temp;
    return nwd(a, b);
  }
  return b;
}

int main() {
  cout << nwd(24, 18) << '\n';
  
  return 0;
}