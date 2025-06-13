#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> znajdz_dzielniki(string nr_albumu) {
    vector<int> dzielniki;

    int liczba = 0;

    for (char c : nr_albumu) {
        liczba += (c - '0'); // konwersja znaku na cyfre
    }
    
    for (int i = 1; i <= liczba; i++) {
        if (liczba % i == 0) {
            dzielniki.push_back(i);
        }
    }
    return dzielniki;
}

void generuj_graf(const vector<int>& dzielniki, const string& nazwa_pliku) {
    ofstream plik(nazwa_pliku);

    if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc pliku do zapisu." << endl;
        return;
    }

    plik << "digraph G {\n";

    for (auto it1 = dzielniki.begin(); it1 != dzielniki.end(); ++it1) {
        for (auto it2 = dzielniki.begin(); it2 != dzielniki.end(); ++it2) {
            if (*it2 != *it1 && *it1 % *it2 == 0) {
                plik << "\t" << *it2 << " -> " << *it1 << ";\n";
            }
        }
    }

    plik << "}" <<endl;
    plik.close();
}

int main() {
    string nr = "91234";
    vector<int> dzielniki = znajdz_dzielniki(nr);

    generuj_graf(dzielniki, "lab11/graf.dot");

    ofstream album("lab11/numer_albumu.txt");
    
    if (album.is_open()) {
        album << nr;
        album.close();
    }
    return 0;
}
