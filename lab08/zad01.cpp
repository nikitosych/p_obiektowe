#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class PESEL {
private:
    string numer;

    bool checkSum(const string& pesel) {
        int wagi[] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
        int suma = 0;

        for (int i = 0; i < 10; ++i)
            suma += (pesel[i] - '0') * wagi[i];

        int kontrolna = (10 - (suma % 10)) % 10;
        return kontrolna == (pesel[10] - '0');
    }

    bool sprawdzDate(const string& pesel) {
        int rok = stoi(pesel.substr(0, 2));
        int miesiac = stoi(pesel.substr(2, 2));
        int dzien = stoi(pesel.substr(4, 2));

        if (
            miesiac < 1 
            || miesiac > 32 
            || dzien < 1 
            || dzien > 31
            )
        {
            return false;
        }
        
        return true;
    }

public:
    PESEL(const string& p) {
        testujPESEL(p);

        numer = p;
    }

    void testujPESEL(const string& p) // po co mam inicjalizowac p jako char*, gdy mozna to zrobic jako string?
    {
        if (p.length() != 11)
            throw invalid_argument("Niepoprawna dlugosc PESELu");

        for (char c : p) // foreach c in p
            if (!isdigit(c))
                throw invalid_argument("Niepoprawne znaki PESELu");

        if (!sprawdzDate(p))
            throw invalid_argument("Niepoprawne urodziny PESELu");

        if (!checkSum(p))
            throw invalid_argument("Niepoprawna suma PESELu");
    }

    void wypisz() {
        cout << "----------------------------------------------------------"<< endl;
        cout << "          " << numer << "         |         " << wczytajUrodziny()<< endl;
    }

    string wczytajUrodziny() { // nie jestem pewien ze to jest poprawne
        // https://pl.wikipedia.org/wiki/PESEL#Data_urodzenia

        int rok = stoi(numer.substr(0, 2));
        int miesiac = stoi(numer.substr(2, 2));
        int dzien = stoi(numer.substr(4, 2));
        int wiek = 1900;

        if (miesiac >= 81 && miesiac <= 92) { wiek = 1800; miesiac -= 80; }
        else if (miesiac >= 1 && miesiac <= 12) { wiek = 1900; }
        else if (miesiac >= 21 && miesiac <= 32) { wiek = 2000; miesiac -= 20; }
        else if (miesiac >= 41 && miesiac <= 52) { wiek = 2100; miesiac -= 40; }
        else if (miesiac >= 61 && miesiac <= 72) { wiek = 2200; miesiac -= 60; }

        return to_string(wiek + rok) + "-" + to_string(miesiac) + "-" + to_string(dzien);
    }
};

int main() {
    ifstream plik("./lab08/test.txt"); // moja sciezka do pliku

    string line;

    cout << "             PESEL            |      Data urodzenia      " << endl;
    
    while (getline(plik, line)) {
        try {
            PESEL p(line);
            
            p.wypisz();
        } catch (exception& e) {
            cout << "----------------------------------------------------------"<< endl;
            cout << "          " << line << "         |" << e.what() << endl;
        }
    }

    plik.close();
    return 0;
}