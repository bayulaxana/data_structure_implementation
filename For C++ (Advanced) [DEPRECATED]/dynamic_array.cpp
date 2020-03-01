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

template <typename T=int>
class DynamicArray
{
private:
    T *_arr;
    unsigned _size, _capacity;

public:
    DynamicArray() {
        _arr = (T*) malloc(sizeof(T) * 2);
        _size = 0u;
        _capacity = 2u;
    }

    bool isEmpty() {
        return _size == 0;
    }

    void pushBack(T value)
    {
        if (_size + 1 > _capacity) {
            unsigned it;
            _capacity *= 2;
            T *newArr = (T*) malloc(sizeof(T) * _capacity);
            
            for (it = 0; it < _size; ++it)
                newArr[it] = _arr[it];
            
            T *oldArray = _arr;
            _arr = newArr;
            free(oldArray);
        }
        _arr[_size++] = value;
    }

    void reserve(unsigned size) {
        _arr = (T*) malloc(sizeof(T) * size);
    }

    void setAt(unsigned index, T value) {
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

    T back() {
        if (!isEmpty()) return _arr[_size - 1];
        else exit(-1);
    }

    T front() {
        if (!isEmpty()) return _arr[0];
        else exit(-1);
    }

    T getAt(unsigned index) {
        if (!isEmpty()) {
            if (index >= _size) return _arr[_size - 1];
            else return _arr[index];
        }
        else exit(-1);
    }

    T& operator[](unsigned index) {
        return _arr[index];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;   
}
