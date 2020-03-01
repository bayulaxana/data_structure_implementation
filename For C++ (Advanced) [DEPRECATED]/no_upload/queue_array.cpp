/**
 * Implementasi ADT QueueArray (Queue menggunakan array)
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

/* Structure of Queue using Array */

template <int queueSize, typename T=int>
class QueueArray
{
private:
    T *_element;
    int _front, _rear;
    unsigned _size, _capacity;

public:
    QueueArray()
    {
        _element = (T*) malloc(sizeof(T) * queueSize);
        _front = -1;
        _rear  = -1;
        _size  = 0;
        _capacity = queueSize;
    }

    bool isEmpty() {
        return (_front == -1);
    }

    void push(T value)
    {
        if (_size + 1 <= _capacity) {
            if (_front == -1)
                _front = 0;
            
            _rear = (_rear + 1) % _capacity;
            _element[_rear] = value;
            _size++; 
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            if (_front == _rear) _front = _rear = -1;
            else _front = (_front + 1) % _capacity;
            _size--;
        }
    }

    T front()
    {
        if (!isEmpty())
            return _element[_front];
        exit(-1);
    }

    unsigned size() {
        return _size;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}