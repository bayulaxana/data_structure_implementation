#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> angka;
    vector<int> genap = {2, 4, 6, 8};
    vector<int> ganjil = {1, 3, 5, 7};

    angka.push_back(1);
    angka.push_back(2);
    angka.push_back(3);
    angka.push_back(4);

    cout << "Isi vector \"angka\":";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    cout << "Jumlah elemen pada vector \"angka\": " << angka.size() << "\n";
    cout << "Jumlah maksimal elemen yang dapat ditampung oleh vector \"angka\": " << angka.max_size() << "\n";

    if (angka.empty())
        cout << "Vector \"angka\" kosong.\n";
    else
        cout << "Vector \"angka\" tidak kosong.\n";

    angka.pop_back();

    cout << "Isi vector \"angka\" setelah pop back:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.resize(5, 100);

    cout << "Isi vector \"angka\" setelah resize:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.assign(8, 10);

    cout << "Isi vector \"angka\" setelah assign:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    // memasukkan nilai 20 di posisi ke-2
    angka.insert(angka.begin() + 1, 20);

    // memasukkan nilai 30 di posisi ke-3 sebanyak 3
    angka.insert(angka.begin() + 2, 3, 30);

    cout << "Isi vector \"angka\" setelah insert:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    // menghapus elemen ke-2
    angka.erase(angka.begin() + 1);

    // menghapus elemen ke-2 hingga elemen ke-5
    angka.erase(angka.begin() + 1, angka.begin() + 4);

    cout << "Isi vector \"angka\" setelah erase:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.clear();

    if (angka.empty())
        cout << "Vector \"angka\" kosong.\n";
    else
        cout << "Vector \"angka\" tidak kosong.\n";

    cout << "Isi vector \"genap\":";
    for (auto i = genap.begin(); i != genap.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    cout << "Isi vector \"ganjil\":";
    for (auto i = ganjil.begin(); i != ganjil.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    genap.swap(ganjil);
    // atau
    // ganjil.swap(genap);

    cout << "Isi vector \"genap\" setelah swap:";
    for (int i = 0; i < 4; i++)
        cout << ' ' << genap.at(i);
    cout << '\n';

    cout << "Isi vector \"ganjil\" setelah swap:";
    for (int i = 0; i < 4; i++)
        cout << ' ' << ganjil.at(i);
    cout << '\n';

    vector<int> toSort = {5,3,2,4,1};
    vector<int>::iterator lo,hi;
    
    sort(toSort.begin(),toSort.end());

    for (int i = 0 ; i < 5 ; i++)
        cout << " "  << toSort[i];                  //1 2 3 4 5
    cout << endl;
    lo = lower_bound(toSort.begin(),toSort.end(),3);//    ^
    hi = upper_bound(toSort.begin(),toSort.end(),3);//      ^

    cout << "index lower_bound : " << (lo - toSort.begin()) << endl;
    cout << "index upper_bound : " << (hi - toSort.begin()) << endl;
    return 0;
}