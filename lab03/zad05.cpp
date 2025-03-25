#include <iostream>
#include <cstdio>

using namespace std;

class rownanie_liniowe { // ax + b = 0
private:
    double wsp[2];
    double wynik; // wynik równania liniowego, czyli x
    bool rozwiazanie, niesk_rozwiazan;

public:
    rownanie_liniowe() { // 1x + 1 = 0
        this->wsp[0] = 1; // a
        this->wsp[1] = 1; // b
        this->rozwiazanie = false;
        this->niesk_rozwiazan = false;
    }

    void czytaj_dane() {
        cout << "Wprowadz wspolczynniki a i b: ";
        cin >> this->wsp[0];
        cin >> this->wsp[1];
        cout << '\n';
    }

    void przetworz_dane() {
        double a = this->wsp[0];
        double b = this->wsp[1];

        if (a == 0) {
            if (b == 0) {
                this->niesk_rozwiazan = true;
            } else {
                this->rozwiazanie = false;
            }
        } else {
            this->wynik = -b / a;
            this->rozwiazanie = true;
        }
    }

    void wyswietl_wynik() {
        if (this->niesk_rozwiazan) {
            cout << "Rownanie ma nieskoczenie wiele rozwiazan\n";
        } else if (this->rozwiazanie) {
            printf("Rozwiazanie: x = %.3f\n", this->wynik);
        } else {
            cout << "Rownanie nie ma rozwiazan\n";
        }
    }

};

int main() {
    rownanie_liniowe r;
    
    r.czytaj_dane();
    r.przetworz_dane();
    r.wyswietl_wynik();
    
    return 0;
}
