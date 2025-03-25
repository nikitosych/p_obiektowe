#include <iostream>
using namespace std;
class Czlowiek
{
protected:
double wzrost;
public:
void get_wzrost()
{
cout << "Podaj wzrost: " << endl;
cin >> wzrost;
}
};
class Chlopak
{
protected:
double waga;
public:

void get_waga()
{
cout << "Podaj wage: " << endl;
cin >> waga;
}
};
class Dziewczyna : public Czlowiek
{
protected:
double liczba;
public:
void get_liczba()
{
cout << "Podaj ulubiona liczbe " << endl;
4
cin >> liczba;
}
};
class IDziewczynaIChlopak : public Chlopak, public Dziewczyna
{
public:
void bmi()
{
get_wzrost();
get_waga();
get_liczba();
cout << "BMI wynosi: " << (waga / (wzrost * wzrost)) / liczba << endl;
}
};
int main()
{
IDziewczynaIChlopak d;
d.bmi();
return 0;
}
