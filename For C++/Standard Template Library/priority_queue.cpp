#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> angka;
    priority_queue<int> genap;
    priority_queue<int> ganjil;

    angka.push(2);
    angka.push(4);
    angka.push(1);
    angka.push(3);

    cout << "Elemen pertama priority queue \"angka\": " << angka.top() << "\n";

    cout << "Jumlah elemen pada priority queue \"angka\": " << angka.size() << "\n";

    if (angka.empty())
        cout << "priority queue \"angka\" kosong.\n";
    else
        cout << "priority queue \"angka\" tidak kosong.\n";

    angka.pop();

    cout << "Elemen pertama priority queue \"angka\" setelah pop: " << angka.top() << "\n";

    genap.push(4);
    genap.push(8);
    genap.push(2);
    genap.push(6);

    ganjil.push(3);
    ganjil.push(7);
    ganjil.push(1);
    ganjil.push(5);

    cout << "Elemen pertama priority queue \"genap\": " << genap.top() << "\n";
    cout << "Elemen pertama priority queue \"ganjil\": " << ganjil.top() << "\n";

    genap.swap(ganjil);
    // atau
    // ganjil.swap(genap);

    cout << "Elemen pertama priority queue \"genap\" setelah swap: " << genap.top() << "\n";
    cout << "Elemen pertama priority queue \"ganjil\" setelah swap: " << ganjil.top() << "\n";

    return 0;
}