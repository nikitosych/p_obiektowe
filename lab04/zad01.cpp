#include <iostream>
using namespace std;

class Dziadek {
protected:
    int wiek;
    string imie;

public:
    Dziadek() {
        this->wiek = 60;
        this->imie = "Jan";
    }

    Dziadek(int a) {
        this->wiek = a;
        this->imie = "Anonim";
    }

    Dziadek(string im) {
        this->wiek = 60;
        this->imie = im;
    }

    void powitanie() {
        cout << "Dzien dobry! Mam na imię " << imie << " i mam " << wiek << " lat.\n";
    }

    ~Dziadek() {
        cout << "Do widzenia!\n";
    }
};

class Ojciec : public Dziadek {
public:
    using Dziadek::Dziadek; // dziedziczenie konstruktorow dziadka
    // https://stackoverflow.com/questions/347358/inheriting-constructors

    ~Ojciec() {
        cout << "Papa!\n";
    }
};

class Syn : public Ojciec {
public:
    using Ojciec::Ojciec; // dziedziczenie konstruktorow ojca

    ~Syn() {
        cout << "Narka!\n";
    }
};

int main() {
    Syn wnuczek1;
    wnuczek1.powitanie();

    Syn wnuczek2(25);
    wnuczek2.powitanie();

    Syn wnuczek3("Adam");
    wnuczek3.powitanie();

    return 0;
}
