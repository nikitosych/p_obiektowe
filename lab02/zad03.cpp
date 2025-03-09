#include <iostream>
#include <cmath>

class Student {
public:
    std::string imie;
    std::string nazwisko;
    int nr_albumu;
    long long pesel;
    int ocenaPPS;
    int ocenaLiTM;
    int ocenaALG;

    void wczytajStudenta() {
        std::cout << "Podaj imię: ";
        std::cin >> this->imie;
        std::cout << "Podaj nazwisko: ";
        std::cin >> this->nazwisko;
        std::cout << "Podaj numer albumu: ";
        std::cin >> this->nr_albumu;
        std::cout << "Podaj PESEL: ";
        std::cin >> this->pesel;
        std::cout << "Podaj ocenę z PPS: ";
        std::cin >> this->ocenaPPS;
        std::cout << "Podaj ocenę z LiTM: ";
        std::cin >> this->ocenaLiTM;
        std::cout << "Podaj ocenę z ALG: ";
        std::cin >> this->ocenaALG;
    }

    void wypiszStudenta() {
        std::cout << "\nStudent: " << this->imie << " " << this->nazwisko << "\n";
        std::cout << "Nr albumu: " << this->nr_albumu << "\n";
        std::cout << "PESEL: " << this->pesel << "\n";
        std::cout << "Oceny:\n";
        std::cout << "PPS: " << this->ocenaPPS << " (" << this->ocenaSlowna(this->ocenaPPS) << ")\n";
        std::cout << "LiTM: " << this->ocenaLiTM << " (" << this->ocenaSlowna(this->ocenaLiTM) << ")\n";
        std::cout << "ALG: " << this->ocenaALG << " (" << this->ocenaSlowna(this->ocenaALG) << ")\n";
    }

    void wypiszSrednia() {
        double srednia = (this->ocenaPPS + this->ocenaLiTM + this->ocenaALG) / 3.0;
        int zaokraglonaSrednia = round(srednia);
        std::cout << "Średnia ocen: " << srednia << " ≈ " << zaokraglonaSrednia << " (" << this->ocenaSlowna(zaokraglonaSrednia) << ")\n";
    }

private:
    std::string ocenaSlowna(int ocena) {
        switch (ocena) {
            case 2: return "niedostateczny";
            case 3: return "dostateczny";
            case 4: return "dobry";
            case 5: return "bardzo dobry";
            default: return "nieprawidlowa ocena";
        }
    }
};

int main() {
    Student studenci[3];

    studenci[0] = {"Nikita", "Boika", 91441, 1234567890, 5, 4, 4};
    
    for (int i = 1; i < 3; ++i) {
        std::cout << "\nWprowadz dane dla studenta " << (i + 1) << ":\n";
        studenci[i].wczytajStudenta();
    }

    // Wypisanie danych studentów
    for (int i = 0; i < 3; ++i) {
        std::cout << "\nDane studenta " << (i + 1) << ":\n";
        studenci[i].wypiszStudenta();
        studenci[i].wypiszSrednia();
    }

    return 0;
}
