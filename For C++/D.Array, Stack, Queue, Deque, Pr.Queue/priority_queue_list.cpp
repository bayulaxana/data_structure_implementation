/**
 * Implementasi ADT PriorityQueue menggunakan Linked List
 * [default: minimum priority]
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C++
 * 
 */

#include <stdlib.h>
#include <stdio.h>

struct PQueueNode {
    int data;
    PQueueNode *next;
};

// Default priority: minimum
struct PriorityQueue
{
    PQueueNode *_top;
    unsigned _size;

    void init()
    {
        _top = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_top == NULL);
    }

    void push(int value)
    {
        PQueueNode *temp = _top;
        PQueueNode *newNode = \
            (PQueueNode*) malloc (sizeof(PQueueNode));
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty()) {
            _top = newNode;
            return;
        }

        if (value < _top->data) {
            newNode->next = _top;
            _top = newNode;
        }
        else {
            while ( temp->next != NULL && 
                    temp->next->data < value)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            PQueueNode *temp = _top;
            _top = _top->next;
            free(temp);
        }
    }

    int top()
    {
        if (!isEmpty()) return _top->data;
        else exit(-1);
    }

    unsigned size() {
        return _size;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
