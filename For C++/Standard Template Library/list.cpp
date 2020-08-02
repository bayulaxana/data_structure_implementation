#include <iostream>
#include <list>
using namespace std;

bool is_small_num(const int& value) { return value < 50; }

int main()
{
    list<int> angka;
    list<int> genap = {2, 4, 6, 8};
    list<int> ganjil = {1, 3, 5, 7};
    list<int>::iterator it, it1, it2;

    angka.push_front(4);
    angka.push_back(1);
    angka.push_front(2);
    angka.push_back(3);

    cout << "Isi list \"angka\":";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    cout << "Jumlah elemen pada list \"angka\": " << angka.size() << "\n";
    cout << "Jumlah maksimal elemen yang dapat ditampung oleh list \"angka\": " << angka.max_size() << "\n";

    if (angka.empty())
        cout << "List \"angka\" kosong.\n";
    else
        cout << "List \"angka\" tidak kosong.\n";

    angka.reverse();

    cout << "Isi list \"angka\" setelah reverse:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.sort();

    cout << "Isi list \"angka\" setelah sort:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.pop_front();
    angka.pop_back();

    cout << "Isi list \"angka\" setelah pop (front dan back):";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.resize(5, 100);

    cout << "Isi list \"angka\" setelah resize:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.assign(8, 10);

    cout << "Isi list \"angka\" setelah assign:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    it = angka.begin(); // it menunjuk posisi pertama
    ++it;               // it menunjuk posisi ke-2

    // memasukkan nilai 20 di posisi ke-2
    angka.insert(it, 20);
    // it menunjuk posisi ke-3 (bergeser akibat insert elemen sebanyak 1)

    // memasukkan nilai 30 di posisi ke-3 sebanyak 3
    angka.insert(it, 3, 30);

    cout << "Isi list \"angka\" setelah insert:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    it1 = angka.begin(); // it1 menunjuk posisi pertama
    ++it1;               // it1 menunjuk posisi ke-2

    // menghapus elemen ke-2
    it1 = angka.erase(it1);
    // it tetap menunjuk posisi ke-2

    it2 = angka.begin(); // it2 menunjuk posisi pertama
    advance(it2, 4);     // menggeser it2 sebanyak 4 posisi
    // it2 menunjuk posisi ke-5

    // menghapus elemen ke-2 hingga elemen ke-5
    angka.erase(it1, it2);

    cout << "Isi list \"angka\" setelah erase:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.clear();

    if (angka.empty())
        cout << "List \"angka\" kosong.\n";
    else
        cout << "List \"angka\" tidak kosong.\n";

    cout << "Isi list \"genap\":";
    for (auto i = genap.begin(); i != genap.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    cout << "Isi list \"ganjil\":";
    for (auto i = ganjil.begin(); i != ganjil.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    genap.swap(ganjil);
    // atau
    // ganjil.swap(genap);

    cout << "Isi list \"genap\" setelah swap:";
    for (auto i = genap.begin(); i != genap.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    cout << "Isi list \"ganjil\" setelah swap:";
    for (auto i = ganjil.begin(); i != ganjil.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    it = genap.begin(); // it menunjuk posisi pertama
    advance(it, 2);     // menggeser it sebanyak 2 posisi

    // memindahkan semua elemen ke list lain
    genap.splice(it, ganjil);

    cout << "Isi list \"genap\" setelah splice:";
    for (auto i = genap.begin(); i != genap.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    cout << "Isi list \"ganjil\" setelah splice:";
    for (auto i = ganjil.begin(); i != ganjil.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    // memindahkan satu elemen ke list lain
    ganjil.splice(ganjil.begin(), genap, it);

    cout << "Isi list \"genap\" setelah splice:";
    for (auto i = genap.begin(); i != genap.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    cout << "Isi list \"ganjil\" setelah splice:";
    for (auto i = ganjil.begin(); i != ganjil.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    it = genap.begin(); // it menunjuk posisi pertama
    advance(it, 3);     // menggeser it sebanyak 3 posisi

    // memindahkan beberapa elemen pada range tertentu ke list lain
    ganjil.splice(ganjil.begin(), ganjil, it, genap.end());

    cout << "Isi list \"genap\" setelah splice:";
    for (auto i = genap.begin(); i != genap.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    cout << "Isi list \"ganjil\" setelah splice:";
    for (auto i = ganjil.begin(); i != ganjil.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    // syarat sebelum melakukan merge adalah kedua list terurut
    genap.sort();
    ganjil.sort();

    genap.merge(ganjil);
    // atau
    // ganjil.merge(genap);

    cout << "Isi list \"genap\" setelah merge:";
    for (auto i = genap.begin(); i != genap.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    cout << "Isi list \"ganjil\" setelah merge:";
    for (auto i = ganjil.begin(); i != ganjil.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    for (int i = 0; i < 10; i++)
    {
        angka.push_front((i + 1) * 10);
    }

    for (int i = 0; i < 10; i++)
    {
        angka.push_back((i + 1) * 10);
    }

    angka.sort();

    cout << "Isi list \"angka\":";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.remove(10);

    cout << "Isi list \"angka\" setelah remove:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.remove_if(is_small_num);

    cout << "Isi list \"angka\" setelah remove if:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    angka.unique();

    cout << "Isi list \"angka\" setelah unique:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    return 0;
}