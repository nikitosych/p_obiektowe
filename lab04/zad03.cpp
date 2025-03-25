#include <iostream>
using namespace std;

class Czlowiek {
protected:
    double wzrost;
public:
    void get_wzrost() {
        cout << "Podaj wzrost: ";
        cin >> wzrost;
    }
};

class Chlopak : public Czlowiek {
protected:
    double waga;
public:
    void get_waga() {
        cout << "Podaj wage: ";
        cin >> waga;
    }
};

class Dziewczyna : public Czlowiek {
protected:
    double liczba;
public:
    void get_liczba() {
        cout << "Podaj ulubiona liczbe: ";
        cin >> liczba;
    }
};

class IDziewczynaIChlopak : public Chlopak, public Dziewczyna {
public:
    void bmi() {
        Dziewczyna::get_wzrost(); // Uzywamy metody z klasy dziewczyny
        get_waga();
        get_liczba();
        cout << "BMI wynosi: " << (waga / (Dziewczyna::wzrost * Dziewczyna::wzrost)) / liczba << endl;
    }
};

int main() {
    IDziewczynaIChlopak d;
    d.bmi();
    return 0;
}
