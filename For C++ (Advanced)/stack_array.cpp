/**
 * Implementasi ADT StackArray (Stack menggunakan static Array)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C++
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */


#include <stdlib.h>
#include <iostream>

using namespace std;

/* Structure of Stack using Array */

template <int stackSize, typename T=int>
struct StackArray
{
private:
    T *_element;
    int _topIndex;
    int _size, _capacity;

public:
    StackArray() 
    {
        _element  = (T*) malloc(sizeof(T) * stackSize);
        _size     = 0;
        _topIndex = -1;
        _capacity = stackSize;
    }

    bool isEmpty() {
        return (_topIndex == -1);
    }

    void push(T value) 
    {
        if (_size + 1 <= _capacity) {
            _element[++_topIndex] = value;
            _size++;
        }
    }

    void pop() 
    {
        if (!isEmpty()) {
            _topIndex--;
            _size--;
        }
    }

    T top() 
    {
        if (!isEmpty())
            return _element[_topIndex]; 
        exit(-1);
    }
};

int main()
{
    StackArray<100, double> mystc;
    mystc.push(2.32);
    mystc.push(3.30);
    mystc.push(9.1);
    mystc.pop();
    cout << mystc.top() << endl;
    return 0;
}