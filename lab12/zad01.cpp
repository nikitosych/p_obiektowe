#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <ctime>
#include <set>

using namespace std;

class Eurojackpot {
private:
    vector<int> mainSetSet;  // zestaw 1-50
    vector<int> euroSet;  // zestaw 1-12
    vector<int> drawnMain;
    vector<int> drawnEuro;

public:
    Eurojackpot(int mainSetMax = 50, int euroMax = 12) {
        for (int i = 1; i <= mainSetMax; ++i) 
            mainSetSet.push_back(i);
        
        for (int i = 1; i <= euroMax; ++i) 
            euroSet.push_back(i);
    }

    void drawNumbers() {
        
        auto seed = time(nullptr);
        default_random_engine rng(seed);

        shuffle(mainSetSet.begin(), mainSetSet.end(), rng);
        shuffle(euroSet.begin(), euroSet.end(), rng);

        drawnMain.assign(mainSetSet.begin(), mainSetSet.begin() + 5);
        drawnEuro.assign(euroSet.begin(), euroSet.begin() + 2);

        sort(drawnMain.begin(), drawnMain.end());
        
        sort(drawnEuro.begin(), drawnEuro.end());
    }

    vector<int> getDrawnMain() const { return drawnMain; }
    vector<int> getDrawnEuro() const { return drawnEuro; }

    static void printVector(const vector<int>& v) {
        for (int n : v) {
            cout << n << ' ';
        }
        cout << endl;
    }

    int checkHits(vector<int>& mainSet, vector<int>& userSet) {
        vector<int> mainSetHits, euroHits;

        // https://stackoverflow.com/questions/19483663/vector-intersection-in-c
        set_intersection(drawnMain.begin(), drawnMain.end(),
                         mainSet.begin(), mainSet.end(),
                         back_inserter(mainSetHits));
        set_intersection(drawnEuro.begin(), drawnEuro.end(),
                         userSet.begin(), userSet.end(),
                         back_inserter(euroHits));

        cout << "\nTrafione liczby glowne: ";
        printVector(mainSetHits);
        cout << "Trafione liczby euro: ";
        printVector(euroHits);

        cout << "\nTrafiono " << mainSetHits.size() << " z 5 glownego zestawu i "
             << euroHits.size() << " z 2 liczb!" << endl;

        return mainSetHits.size() * 10 + euroHits.size();  // prosty sposób oceny wygranej
    }
};

int main() {
    Eurojackpot lotto;
    vector<int> mainSet, userSet;
    int num = 0;
    
    lotto.drawNumbers();

    auto drawnMain = lotto.getDrawnMain();
    cout << "Wylosowane liczby glowne: ";
    if (drawnMain.size() > 0) {
        Eurojackpot::printVector(drawnMain);
    }
    else {
        cout << "Nie trafiono zadnej liczby :(" << endl;
    }
        

    auto drawnEuro = lotto.getDrawnEuro();
    cout << "Wylosowane liczby euro: ";
    if (drawnEuro.size() > 0) {
        Eurojackpot::printVector(drawnEuro);
    }
    else {
        cout << "Nie trafiono zadnej liczby :(" << endl;
    }



    cout << "\nPodaj 5 liczb (1-50): ";

    for (int i = 0; i < 5; ++i) {
        cin >> num;
        if (num < 1 || num > 50) {
            cout << "Sprobuj ponownie." << endl;
            --i;
            continue;
        }
        mainSet.push_back(num);
    }
    sort(mainSet.begin(), mainSet.end());

    cout << "Podaj 2 swoje liczby euro (1-12): ";
    for (int i = 0; i < 2; ++i) {
        cin >> num;
        if (num < 1 || num > 12) {
            cout << "Sprobuj ponownie." << endl;
            --i;
            continue;
        }
        userSet.push_back(num);
    }
    sort(userSet.begin(), userSet.end());

    lotto.checkHits(mainSet, userSet);

    return 0;
}
