#include <iostream>
#include <cmath>
using namespace std;

class Figura {
public:
    virtual double pole() const = 0;
    virtual double obwod() const = 0;
    virtual void wypisz() const {
        cout << "Pole: " << pole() << ", Obwod: " << obwod() << endl;
    }
};

class Kolo : public Figura {
protected:
    double promien;
public:
    Kolo() : promien(1.0) {}
    Kolo(double r) : promien(r) {}
    double pole() const override {
        return M_PI * promien * promien;
    }
    double obwod() const override {
        return 2 * M_PI * promien;
    }
};

class Kwadrat : public Figura {
protected:
    double bok;
public:
    Kwadrat() : bok(1.0) {}
    Kwadrat(double x) : bok(x) {}
    double pole() const override {
        return bok * bok;
    }
    double obwod() const override {
        return 4 * bok;
    }
};

class Prostokat : public Figura {
protected:
    double a, b;
public:
    Prostokat() : a(1.0), b(2.0) {}
    Prostokat(double x, double y) : a(x), b(y) {}
    double pole() const override {
        return a * b;
    }
    double obwod() const override {
        return 2 * (a + b);
    }
};

class Trojkat : public Figura {
protected:
    double a, b, c;
public:
    Trojkat() : a(3), b(4), c(5) {}
    Trojkat(double x, double y, double z) : a(x), b(y), c(z) {}
    double pole() const override {
        double s = obwod() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double obwod() const override {
        return a + b + c;
    }
};

int main() {
    Figura* figury[4];

    double r, x, y, z;

    cout << "Podaj promien kola: ";
    cin >> r;
    figury[0] = new Kolo(r);

    cout << "Podaj bok kwadratu: ";
    cin >> x;
    figury[1] = new Kwadrat(x);

    cout << "Podaj boki prostokata (a b): ";
    cin >> x;
    cin >> y;
    figury[2] = new Prostokat(x, y);

    cout << "Podaj boki trojkata (a b c): ";
    cin >> x;
    cin >> y;
    cin >> z;
    figury[3] = new Trojkat(x, y, z);

    for (int i = 0; i < 4; ++i) {
        cout << "Figura " << i + 1 << ": ";
        figury[i]->wypisz();
        delete figury[i];
    }

    return 0;
}
