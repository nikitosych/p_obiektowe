#include <iostream>

using namespace std;

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

class Spojnik {
public:
    string nazwa;
    int sila;
    Spojnik(string nazwa, int sila) {
        this->nazwa = nazwa;
        this->sila = sila;
    }
    virtual void wypisz() {
        cout << nazwa;
    }
};

static Spojnik *ZMIENNA = new Spojnik("",100);
static Spojnik *NEGACJA = new Spojnik("~",90);
static Spojnik *KONIUNKCJA = new Spojnik("&",80);
static Spojnik *ALTERNATYWA = new Spojnik("|",70);
static Spojnik *IMPLIKACJA = new Spojnik("->",60);
static Spojnik *ROWNOWAZNOSC = new Spojnik("<->",50);

class Formula {
public:
    Spojnik *spojnik;
    Formula(Spojnik *spojnik) {
        this->spojnik = spojnik;
    }
    virtual void wypisz() = 0;
    virtual bool oblicz() = 0;
    virtual Formula* usunRownowaznosc() = 0;
    virtual Formula* usunImplikacje() = 0;
    virtual Formula* usunAlternatywe() = 0;
    virtual Formula* podwojnaNegacja() = 0;

    Formula* NF() {
        return usunRownowaznosc()->usunImplikacje()->usunAlternatywe()->podwojnaNegacja();
    }
};

class Zmienna: public Formula {
public:
    string nazwa;
    bool wartosc;
    Zmienna(string nazwa, bool wartosc) : Formula(ZMIENNA) {
        this->nazwa = nazwa;
        this->wartosc = wartosc;
    }
    Zmienna(string nazwa) : Formula(ZMIENNA) {
        this->nazwa = nazwa;
        this->wartosc = true;
    }
    void wypisz() {
        cout << nazwa;
    }
    bool oblicz() {
        return wartosc;
    }
    Formula* usunRownowaznosc() {
        return this;
    }
    Formula* usunImplikacje() {
        return this;
    }
    Formula* usunAlternatywe() {
        return this;
    }
    Formula* podwojnaNegacja() {
        return this;
    }
};

class Formula1: public Formula {
public:
    Formula *arg;
    Formula1(Spojnik *spojnik, Formula *arg) : Formula(spojnik) {
        this->arg = arg;
    }
    void wypisz() {
        bool nawiasy = spojnik->sila > arg->spojnik->sila;
        spojnik->wypisz();
        if (nawiasy) cout << "(";
        arg->wypisz();
        if (nawiasy) cout << ")";
    }
};

class Formula2: public Formula {
public:
    Formula *arg1, *arg2;
    Formula2(Spojnik *spojnik, Formula *arg1, Formula *arg2) : Formula(spojnik) {
        this->arg1 = arg1;
        this->arg2 = arg2;
    }
    void wypisz() {
        bool nawiasy1 = spojnik->sila >= arg1->spojnik->sila;
        bool nawiasy2 = spojnik->sila >= arg2->spojnik->sila;
        if (nawiasy1) cout << " (";
        arg1->wypisz();
        if (nawiasy1) cout << ") ";
        spojnik->wypisz();
        if (nawiasy2) cout << " (";
        arg2->wypisz();
        if (nawiasy2) cout << ") ";
    }
};

class Negacja: public Formula1 {
public:
    Negacja(Formula *arg) : Formula1(NEGACJA, arg) {
    }
    bool oblicz() {
        return ! arg->oblicz();
    }
    Formula* usunRownowaznosc() {
        return new Negacja(arg->usunRownowaznosc());
    }
    Formula* usunImplikacje() {
        return new Negacja(arg->usunImplikacje());
    }
    Formula* usunAlternatywe() {
        return new Negacja(arg->usunAlternatywe());
    }
    Formula* podwojnaNegacja() {
        if (instanceof<Negacja>(arg)) {
            return ((Negacja*)arg)->arg->podwojnaNegacja();
        } else {
            return new Negacja(arg->podwojnaNegacja());
        }
    }
};

class Koniunkcja: public Formula2 {
public:
    Koniunkcja(Formula *arg1, Formula *arg2) : Formula2(KONIUNKCJA,arg1,arg2){
    }
    bool oblicz() {
        return arg1->oblicz() && arg2->oblicz();
    }
    Formula* usunRownowaznosc() {
        return new Koniunkcja(arg1->usunRownowaznosc(),arg2->usunRownowaznosc());
    }
    Formula* usunImplikacje() {
        return new Koniunkcja(arg1->usunImplikacje(),arg2->usunImplikacje());
    }
    Formula* usunAlternatywe() {
        return new Koniunkcja(arg1->usunAlternatywe(),arg2->usunAlternatywe());
    }
    Formula* podwojnaNegacja() {
        return new Koniunkcja(arg1->podwojnaNegacja(),arg2->podwojnaNegacja());
    }
};

int main() {
    Zmienna *p = new Zmienna("p", false);
    Zmienna *q = new Zmienna("q");
    Negacja *n = new Negacja(p);
    Negacja *n1 = new Negacja(n);
    Koniunkcja *k1 = new Koniunkcja(n,n1);
    Koniunkcja *k2 = new Koniunkcja(n1,n1);
    n->wypisz();
    cout << endl;
    n->NF() -> wypisz();
    cout << endl;

    n1->wypisz();
    cout << endl;
    n1->NF() -> wypisz();
    cout << endl;

    k1->wypisz();
    cout << endl;

    k2->wypisz();
    cout << endl;
    cout << k2->NF() -> oblicz() << endl;
  k2->NF() -> wypisz();


    return 0;
}