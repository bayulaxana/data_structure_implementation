/*
-- Created by Bayu Laksana on 9 January 2019
-- Implemented for C++ (Data Structure 2020)
----------------------------------------------
*/

#include <stdlib.h>

/* Structure of Stack using Array */

template <int stackSize, typename T=int>
struct StackArray
{
    T *_element;
    int _topIndex;
    int _size, _capacity;

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