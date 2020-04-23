#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
    array<int, 4> angka = {1, 2, 3, 4};
    array<int, 4> genap = {2, 4, 6, 8};
    array<int, 4> ganjil = {1, 3, 5, 7};
    array<int, 4> kosong;

    cout << "Isi array \"angka\":";
    for (int i = 0; i < 4; i++)
        cout << ' ' << angka[i];
    cout << '\n';

    cout << "Elemen ke-2 (operator[]): " << angka[1] << endl;
    cout << "Elemen ke-2 (at()): " << angka.at(1) << endl;
    cout << "Elemen pertama: " << angka.front() << endl;
    cout << "Elemen terakhir: " << angka.back() << endl;

    angka.front() = 100;
    angka.at(1) = 200;
    angka.back() = 400;

    cout << "Isi array \"angka\" sekarang:";
    for (auto i = angka.begin(); i != angka.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    cout << "Jumlah elemen pada array \"angka\": " << angka.size() << "\n";
    cout << "Jumlah maksimal elemen yang dapat ditampung oleh array \"angka\": " << angka.max_size() << "\n";

    if (angka.empty())
        cout << "Array \"angka\" kosong.\n";
    else
        cout << "Array \"angka\" tidak kosong.\n";
    if (kosong.empty())
        cout << "Array \"kosong\" kosong.\n";
    else
        cout << "Array \"kosong\" tidak kosong.\n";

    cout << "Isi array \"genap\":";
    for (int i = 0; i < 4; i++)
        cout << ' ' << genap.at(i);
    cout << '\n';

    cout << "Isi array \"ganjil\":";
    for (int i = 0; i < 4; i++)
        cout << ' ' << ganjil.at(i);
    cout << '\n';

    genap.swap(ganjil);
    // atau
    // ganjil.swap(genap);

    cout << "Isi array \"genap\" setelah swap:";
    for (int i = 0; i < 4; i++)
        cout << ' ' << genap.at(i);
    cout << '\n';

    cout << "Isi array \"ganjil\" setelah swap:";
    for (int i = 0; i < 4; i++)
        cout << ' ' << ganjil.at(i);
    cout << '\n';

    angka.fill(1000);
    kosong.fill(10);

    cout << "Isi array \"angka\" setelah fill:";
    for (int i = 0; i < 4; i++)
        cout << ' ' << angka.at(i);
    cout << '\n';

    cout << "Isi array \"kosong\" setelah fill:";
    for (auto i = kosong.begin(); i != kosong.end(); ++i)
        cout << ' ' << *i;
    cout << '\n';

    return 0;
}