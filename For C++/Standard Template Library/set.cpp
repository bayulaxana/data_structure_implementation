#include <iostream>
#include <set>
using namespace std;

int main()
{
   set<int> mySet;
    for (int i = 1 ; i <= 10 ; i++)
    {
        for (int j = 1 ; j <= 10 ; j++)
            mySet.insert(i);
    }

    cout << "ukuran set sekarang : " << mySet.size() << endl;
    cout << "elemen - elemen di dalam set : ";
    for (set<int>::iterator it = mySet.begin() ; it != mySet.end() ; ++it)
    {
        cout << *it << " "; //coba tebak kenapa harus pakai asterisk?
    }
    cout << endl;

    for (int i = 7 ; i <= 12 ; i++)
    {
        if (mySet.count(i))
            cout << i << " ada di dalam set" << endl;
        else
            cout << i << " tidak ada di dalam set" << endl;
    }

    set<int>::iterator lo,hi;
    mySet.erase(5);                 //1 2 3 4 6 7 8 9 10
    lo = mySet.lower_bound(4);      //      ^
    hi = mySet.upper_bound(4);      //        ^
}