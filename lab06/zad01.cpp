#include <iostream>
#include <string>

using namespace std;

const int MAKS_PRACOWNIKOW = 10;
const int MAKS_ZAKLADOW = 5;

class Pracownik {
    string imie;
    string nazwisko;
    string tytul;
public:
    Pracownik() {}
    Pracownik(string i, string n, string t) : imie(i), nazwisko(n), tytul(t) {}

    void wypisz() const {
        cout << tytul << " " << imie << " " << nazwisko << endl;
    }
};

class Zaklad {
    string nazwa;
    Pracownik pracownicy[MAKS_PRACOWNIKOW];
    int liczbaPracownikow = 0;
public:
    Zaklad() {}
    Zaklad(string n) : nazwa(n) {}

    void dodajPracownika(const Pracownik& p) {
        if (liczbaPracownikow < MAKS_PRACOWNIKOW) {
            liczbaPracownikow++;
            pracownicy[liczbaPracownikow] = p;
        }
    }

    void wypisz() const {
        cout << "Zaklad: " << nazwa << endl;
        for (int i = 0; i < liczbaPracownikow; ++i) {
            pracownicy[i].wypisz();
        }
    }
};

class Wydzial {
    string nazwa;
    Zaklad zaklady[MAKS_ZAKLADOW];
    int liczbaZakladow = 0;
public:
    Wydzial(string n) : nazwa(n) {}

    void dodajZaklad(Zaklad& z) {
        if (liczbaZakladow < MAKS_ZAKLADOW) {
            liczbaZakladow++;
            zaklady[liczbaZakladow] = z;
        }
    }

    void wypisz() const {
        cout << "Wydzial: " << nazwa << endl;
        for (int i = 0; i < liczbaZakladow; ++i) {
            zaklady[i].wypisz();
        }
    }
};

int main() {
    Zaklad bio("BIO");
    bio.dodajPracownika(Pracownik("Anna", "Kowal", "dr"));
    bio.dodajPracownika(Pracownik("Jan", "Nowak", "prof"));

    Zaklad zpd("ZPD");
    zpd.dodajPracownika(Pracownik("Ewa", "Wisniewska", "dr"));

    Wydzial uwb("WI UWB");
    uwb.dodajZaklad(bio);
    uwb.dodajZaklad(zpd);

    uwb.wypisz();

    return 0;
}