#include <iostream>
#include <cmath>
using namespace std;

class Wektor3d {
private:
    double x, y, z;
public:
    static int wymiar;

    double get_x(void) { return x; }
    void set_x(double Ax) { x = Ax; }

    double get_y(void) { return y; }
    void set_y(double Ay) { y = Ay; }

    double get_z(void) { return z; }
    void set_z(double Az) { z = Az; }

    void wypisz(void) {
        cout << endl << "[" << x << ", " << y << ", " << z << "]";
    }

    void normuj(void);

    static void zmien_rozmiar(int nowy_rozmiar) {
        wymiar = nowy_rozmiar;
        cout << "Nowy wymiar to " << wymiar << endl;
    }
};

int Wektor3d::wymiar = 3;

void Wektor3d::normuj(void) {
    double dlg = sqrt(x * x + y * y + z * z);
    if (dlg > 0) {
        x /= dlg;
        y /= dlg;
        z /= dlg;
    }
}

int main() {
    Wektor3d w1, w[100];
    w1.set_x(50);
    w1.set_y(60);
    w1.set_z(70);
    w1.wypisz();
    cout << " - skladowe wektora w1";

    w[13].set_x(10);
    w[13].set_y(10);
    w[13].set_z(10);
    w[13].wypisz();
    cout << " - skladowe wektora w[13]";

    cout << "\nWymiar: " << Wektor3d::wymiar << endl;
    Wektor3d::zmien_rozmiar(4);
    
    return 0;
}
