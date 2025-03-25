#include <iostream>

using namespace std;

class samochod {
  private:
    int bieg = 0; // km
    bool wlaczona = false;
  public:
    string firma, model;
    unsigned short rok;
    int get_bieg () { return this->bieg; }
    bool czyWlaczona () { return this->wlaczona; }
    void uruchom() { this->wlaczona = true; }
    void jedz(int ile_jedziemy) {
      if (!wlaczona) { 
        cout << "Najpierw uruchom!\n";
        return;
      }
      bieg += ile_jedziemy;
      cout << "Samochod przejechal " << ile_jedziemy << " km!\n";
    }
    
};

int main() {
  samochod s1;
  s1.firma = "Honda";
  s1.model = "CRV";
  s1.rok = 2024;

  cout << s1.firma << "\n";
  cout << s1.model << "\n";
  cout << s1.rok << "\n";
  cout << s1.get_bieg() << "\n";

  s1.uruchom();
  s1.jedz(5);
  cout << s1.get_bieg() << "\n";
  
  return 0;
}