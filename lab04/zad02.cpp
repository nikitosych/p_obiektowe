#include <iostream>

using namespace std;

class Boki2 {
protected:
    double a, b, pole;

public:
    void set_dane(double n, double m) {
        this->a = n;
        this->b = m;
    }

    double get_pole() {
        return pole;
    }
};

class Prostokat : public Boki2 {
public:
    void set_pole() {
        this->pole = a * b;
    }
};

class Trojkat : public Boki2 {
public:
    void set_pole() {
        this->pole = (a * b)/2;
    }
};

int main() {
    Prostokat r;
    Trojkat t;
    double dlugosc, szerokosc, podstawa, wysokosc;

    cout << "Podaj boki prostokata: " << endl;
    cin >> dlugosc >> szerokosc;
    r.set_dane(dlugosc, szerokosc);
    r.set_pole();
    cout << "Pole prostokata = " << r.get_pole() << endl;

    cout << "Podaj podstawe i wysokosc trojkata: " << endl;
    cin >> podstawa >> wysokosc;
    t.set_dane(podstawa, wysokosc);
    t.set_pole();
    cout << "Pole trojkata = " << t.get_pole() << endl;

    return 0;
}
