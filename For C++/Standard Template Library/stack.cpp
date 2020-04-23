#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> angka;
    stack<int> genap;
    stack<int> ganjil;

    for (int i = 0; i < 4; i++)
    {
        angka.push(i + 1);
    }

    cout << "Elemen pertama stack \"angka\": " << angka.top() << "\n";

    cout << "Jumlah elemen pada stack \"angka\": " << angka.size() << "\n";

    if (angka.empty())
        cout << "Stack \"angka\" kosong.\n";
    else
        cout << "Stack \"angka\" tidak kosong.\n";

    angka.pop();

    cout << "Elemen pertama stack \"angka\" setelah pop: " << angka.top() << "\n";

    for (int i = 0; i < 4; i++)
    {
        genap.push((i + 1) * 2);
    }

    for (int i = 0; i < 4; i++)
    {
        ganjil.push((i + 1) * 2 - 1);
    }

    cout << "Elemen pertama stack \"genap\": " << genap.top() << "\n";
    cout << "Elemen pertama stack \"ganjil\": " << ganjil.top() << "\n";

    genap.swap(ganjil);
    // atau
    // ganjil.swap(genap);

    cout << "Elemen pertama stack \"genap\" setelah swap: " << genap.top() << "\n";
    cout << "Elemen pertama stack \"ganjil\" setelah swap: " << ganjil.top() << "\n";

    return 0;
}