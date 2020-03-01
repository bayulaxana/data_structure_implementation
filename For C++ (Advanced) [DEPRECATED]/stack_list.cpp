/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
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

/* Structure of Stack using List */

template <typename T=int>
class Stack
{
private:
    // Node structure
    struct StackNode {
        T data;
        StackNode *next;
    } *_top;
    unsigned _size;

public:
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
        StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
        if (newNode) {
            _size++;
            newNode->data = value;

            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _top;
            _top = newNode;
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

int main(int argc, char const *argv[])
{
    
    return 0;
}