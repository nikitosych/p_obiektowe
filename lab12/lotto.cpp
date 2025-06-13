#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <ctime>

using namespace std;

void print (vector<int> v)
{
    for (int n : v) cout << n << ' ';
    cout << endl;
//	for (auto iter = v.begin(); iter != v.end(); ++iter)
//         cout << * iter << ' ';
//    for (const auto &i : traf) {  
//            cout << i << ' ';  
//        }     
}

int main()
{
    vector<int> v;
  for (int i = 0; i < 6; i++) {
        v.push_back (i + 1);
    }

    default_random_engine g;
    g.seed(time(NULL));
    shuffle(v.begin(), v.end(), g);

  vector <int> los;

    copy(v.begin(), v.begin() + 6, back_inserter(los));
    copy(los.begin(), los.end(), ostream_iterator<int>(cout, " "));
    cout << endl << "Wylosowane liczby: ";
//    vector <int> los = {v.begin(),v.begin()+6};

  sort(los.begin(), los.end(), less<int>());
  print (los);

    vector <int> moje {1,2,3,4,5,6};
    cout << endl << "Moje trafione liczby: ";

    vector<int> traf;  

    set_intersection(los.begin(), los.end(),  
                       moje.begin(), moje.end(),                    
                       back_inserter(traf));  
    print (traf);   

    cout << "\nTrafilem " << traf.size() << " z 6 liczb! Brawo!" << endl;
    return 0;
}