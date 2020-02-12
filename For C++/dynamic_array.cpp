/**
 * Implementasi ADT Dynamic Array
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C++
 * 
 */

#include <stdlib.h>
#include <iostream>

using namespace std;

struct DynamicArray
{
    int *_arr;
    unsigned int _size, _capacity;

    void init() {
        _arr = (int*) malloc(sizeof(int) * 2);
        _size = 0u;
        _capacity = 2u;
    }

    bool isEmpty() {
        return _size == 0;
    }

    void pushBack(int value)
    {
        if (_size + 1 > _capacity) {
            unsigned int it;
            _capacity *= 2;
            int *newArr = (int*) malloc(sizeof(int) * _capacity);
            
            for (it = 0; it < _size; ++it)
                newArr[it] = _arr[it];
            
            int *oldArray = _arr;
            _arr = newArr;
            free(oldArray);
        }
        _arr[_size++] = value;
    }

    void setAt(unsigned index, int value) {
        if (!isEmpty()) {
            if (index >= _size) _arr[_size-1] = value;
            else _arr[index] = value;
        }
        else exit(-1);
    }

    void popBack() {
        if (!isEmpty()) _size--;
        else exit(-1);
    }

    int back() {
        if (!isEmpty()) return _arr[_size - 1];
        else exit(-1);
    }

    int front() {
        if (!isEmpty()) return _arr[0];
        else exit(-1);
    }

    int getAt(unsigned index) {
        if (!isEmpty()) {
            if (index >= _size) return _arr[_size - 1];
            else return _arr[index];
        }
        else exit(-1);
    }
};

void printAll(DynamicArray darray)
{
    for (int i = 0; i < darray._size; ++i) {
        printf("%d ", darray.getAt(i));
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // Buat objek DynamicArray
    DynamicArray myArray;
    // PENTING! Jangan lupa di-init()
    myArray.init();

    myArray.pushBack(1);
    myArray.pushBack(11);
    myArray.pushBack(19);
    myArray.pushBack(23);
    myArray.pushBack(7);
    // Isi array => [1, 11, 19, 23, 7]

    myArray.popBack();
    // Isi array => [1, 11, 19, 23]

    // print isi array
    printAll(myArray);
    return 0;   
}
