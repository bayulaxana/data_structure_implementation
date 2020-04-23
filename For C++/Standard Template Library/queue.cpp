#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> angka;
    queue<int> genap;
    queue<int> ganjil;

    for (int i = 0; i < 4; i++)
    {
        angka.push(i + 1);
    }

    cout << "Elemen pertama queue \"angka\": " << angka.front() << "\n";
    cout << "Elemen terakhir queue \"angka\": " << angka.back() << "\n";

    cout << "Jumlah elemen pada queue \"angka\": " << angka.size() << "\n";

    if (angka.empty())
        cout << "queue \"angka\" kosong.\n";
    else
        cout << "queue \"angka\" tidak kosong.\n";

    angka.pop();

    cout << "Elemen pertama queue \"angka\" setelah pop: " << angka.front() << "\n";
    cout << "Elemen terakhir queue \"angka\" setelah pop: " << angka.back() << "\n";

    for (int i = 0; i < 4; i++)
    {
        genap.push((i + 1) * 2);
    }

    for (int i = 0; i < 4; i++)
    {
        ganjil.push((i + 1) * 2 - 1);
    }

    cout << "Elemen pertama queue \"genap\": " << genap.front() << "\n";
    cout << "Elemen terakhir queue \"genap\": " << genap.back() << "\n";

    cout << "Elemen pertama queue \"ganjil\": " << ganjil.front() << "\n";
    cout << "Elemen terakhir queue \"ganjil\": " << ganjil.back() << "\n";

    genap.swap(ganjil);
    // atau
    // ganjil.swap(genap);

    cout << "Elemen pertama queue \"genap\" setelah swap: " << genap.front() << "\n";
    cout << "Elemen terakhir queue \"genap\" setelah swap: " << genap.back() << "\n";

    cout << "Elemen pertama queue \"ganjil\" setelah swap: " << ganjil.front() << "\n";
    cout << "Elemen terakhir queue \"ganjil\" setelah swap: " << ganjil.back() << "\n";

    return 0;
}