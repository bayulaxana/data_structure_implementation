/*
-- Created by Bayu Laksana on 9 January 2019
-- Implemented for C++ (Data Structure 2020)
----------------------------------------------
*/

#include <stdlib.h>

/* Structure of Stack using List */

template <typename T=int>
struct Stack
{
    // Node structure
    struct StackNode {
        T data;
        StackNode *next;
    } *_top;
    unsigned _size;

    Stack() 
    {
        _size = 0;
        _top = nullptr;
    }

    bool isEmpty() {
        return (_top == nullptr);
    }

    void push(T value)
    {
        StackNode *newNode =\
            (StackNode*) malloc(sizeof(StackNode));
        if (newNode) {
            _size++;
            if (isEmpty()) {
                newNode->data = value;
                newNode->next = NULL;
                _top = newNode;
            }
            else {
                newNode->data = value;
                newNode->next = _top;
                _top = newNode;
            }
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            StackNode *temp = _top;
            _top = _top->next;
            free(temp);
            _size--;
        }
    }

    T top()
    {
        if (!isEmpty())
            return _top->data;
        exit(-1);
    }
};