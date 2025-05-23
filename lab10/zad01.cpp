#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

struct Osoba {
  string imie;
  short wiek;

  bool operator> (const Osoba& osoba) {
    return this->wiek > osoba.wiek;
  }
};

template <typename T>
void bubbleSort(vector<T>& tab) 
{
  int n = tab.size();
  for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < n - i - 1; ++j) {
          if (tab[j] > tab[j + 1]) {
              std::swap(tab[j], tab[j + 1]);
          }
      }
  }
}

// https://www.youtube.com/watch?v=7zuGmKfUt7s
// działa tylko dla liczb całkowitych
template <typename T>
void countingSort(vector<T>& tab)
{
  vector<T> out(tab.size());
  int max = *max_element(tab.begin(), tab.end());
  vector<int> count(max+1);
  int i;
  // memset(count, 0, sizeof(count));

  for (i = 0; i < tab.size(); ++i) 
    {
      ++count[tab[i]]; // liczymy wystąpienia
    }

  for (i = 1; i < count.size(); ++i)
    {
      count[i] += count[i - 1]; // sum count
    }

  for (i = 0; i < tab.size(); ++i)
    {
      out[count[tab[i]] - 1] = tab[i];
      --count[tab[i]];
    }
  
  for (i = 0; i < tab.size(); ++i)
    {
      tab[i] = out[i];
    }
}

template <typename T>
void quickSort(vector<T>& tab)
{
  sort(tab.begin(), tab.end());
}

int main()
{
  vector<Osoba> osoby = {{"Jan", 20}, {"Anna", 25}, {"Piotr", 18}, {"Maria", 30}, {"Krzysztof", 22}};
  vector<int> nums = {1, 33333, 5, 4, 9, 8};
  vector<double> dbs = {1.5, 0.4, 0, 0.24231, 0.94376, 8.232};
  vector<char> syms = {'a', '0', '-', '1', '=', 'b', 'a'};
  
  bubbleSort(osoby);
  countingSort(nums);
  bubbleSort(dbs);
  quickSort(syms);

  for (const auto& osoba : osoby)
    {
    cout << osoba.imie << " " << osoba.wiek << endl;
    }

  cout << '\n';

  for (const int& num : nums)
    {
      cout << num << endl;
    }

  cout << '\n';

  for (const double& db : dbs)
    {
      cout << db << endl;
    }

  cout << '\n';

  for (const double& c : syms)
    {
      cout << c << endl;
    }


  // sprawdzamy czas sortowania

  vector<int> nums2 = {1, 33333, 5, 4, 9, 8, 10000, 100000, 1000};
  auto start = chrono::high_resolution_clock::now();
  quickSort(nums2);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> czas = end - start;
  for (const int& num : nums2)
    {
      cout << num << endl;
      
    }
  cout << "Czas sortowania quickSort: " << czas.count() << " ms\n";

  start = chrono::high_resolution_clock::now();
  bubbleSort(nums2);
  end = chrono::high_resolution_clock::now();
  czas = end - start;
  for (const int& num : nums2)
    {
      cout << num << endl;
    }
  cout << "Czas sortowania bubbleSort: " << czas.count() << " ms\n";

  start = chrono::high_resolution_clock::now();
  countingSort(nums2);
  end = chrono::high_resolution_clock::now();
  czas = end - start;
  for (const int& num : nums2)
    {
      cout << num << endl;
    }
  cout << "Czas sortowania countingSort: " << czas.count() << " ms\n";
  
  
  return 0;
}