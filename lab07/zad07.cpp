#include <iostream>
#include <cmath>

using namespace std;

class Rownanie {
protected:
    string typ;
public:
    virtual void czytaj_dane() = 0;
    virtual void przetworz_dane() = 0;
    virtual void wyswietl_wynik() = 0;
};

class Liniowe : public Rownanie {
private:
    double a, b, wynik;
    bool rozwiazanie, niesk_rozwiazan;
public:
    Liniowe() {
        a = 1;
        b = 1;
        rozwiazanie = false;
        niesk_rozwiazan = false;
        typ = "liniowe";
    }

    void czytaj_dane() override {
        cout << "Rownanie liniowe: ax + b = 0\nPodaj a i b: ";
        cin >> a >> b;
    }

    void przetworz_dane() override {
        if (a == 0) {
            if (b == 0) niesk_rozwiazan = true;
            else rozwiazanie = false;
        } else {
            wynik = -b / a;
            rozwiazanie = true;
        }
    }

    void wyswietl_wynik() override {
        if (niesk_rozwiazan)
            cout << "Nieskonczenie wiele rozwiazan\n";
        else if (rozwiazanie)
            cout << "Rozwiazanie: x = " << wynik << endl;
        else
            cout << "Brak rozwiazan\n";
    }
};

class Kwadratowe : public Rownanie {
private:
    double a, b, c;
    double delta, x1, x2;
    int liczba_rozw;
public:
    Kwadratowe() {
        a = 1; b = 1; c = 1;
        liczba_rozw = 0;
        typ = "kwadratowe";
    }

    void czytaj_dane() override {
        cout << "Rownanie kwadratowe: ax^2 + bx + c = 0\nPodaj a b c: ";
        cin >> a >> b >> c;
    }

    void przetworz_dane() override {
        delta = b*b - 4*a*c;
        if (delta < 0) liczba_rozw = 0;
        else if (delta == 0) {
            x1 = -b / (2*a);
            liczba_rozw = 1;
        } else {
            x1 = (-b - sqrt(delta)) / (2*a);
            x2 = (-b + sqrt(delta)) / (2*a);
            liczba_rozw = 2;
        }
    }

    void wyswietl_wynik() override {
        if (liczba_rozw == 0)
            cout << "Brak rozwiazan\n";
        else if (liczba_rozw == 1)
            cout << "Jedno rozwiazanie: x = " << x1 << endl;
        else
            cout << "Dwa rozwiazania: x1 = " << x1 << ",x2 = " << x2 << endl;
    }
};

int main() {
    Rownanie* tablica[2];

    tablica[0] = new Liniowe();
    tablica[1] = new Kwadratowe();

    for (int i = 0; i < 2; ++i) {
        tablica[i]->czytaj_dane();
        tablica[i]->przetworz_dane();
        tablica[i]->wyswietl_wynik();
        cout << endl;
    }

    for (int i = 0; i < 2; ++i)
        delete tablica[i];

    return 0;
}