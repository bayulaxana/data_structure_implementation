/*
-- Created by Bayu Laksana on 9 January 2019
-- Implemented for C++ (Data Structure 2020)
----------------------------------------------
*/

#include <stdlib.h>

/* Structure of Priority Queue using List */

// Default: minimum priority
template <typename T=int>
struct PriorityQueue
{
    struct PQueueNode {
        T data;
        PQueueNode *next;
    } *_top;
    unsigned _size;

    PriorityQueue()
    {
        _top = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_top == NULL);
    }

    void push(T value)
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

    T top()
    {
        if (!isEmpty()) return _top->data;
        else exit(-1);
    }
};