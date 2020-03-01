/**
 * Implementasi ADT Queue (Queue menggunakan Linked List)
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

/* Structure of Queue using List */

template <typename T=int>
class Queue
{
    // Node Structure
    struct QueueNode {
        T data;
        QueueNode *next;
    } *_front, *_rear;
    unsigned _size;

    Queue()
    {
        _size  = 0;
        _front = NULL;
        _rear  = NULL;
    }

    bool isEmpty() {
        return (_front == NULL && _rear == NULL);
    }

    void push(T value)
    {
        QueueNode *newNode =\
            (QueueNode*) malloc(sizeof(QueueNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            newNode->next = NULL;
            
            if (isEmpty())                 
                _front = _rear = newNode;
            else {
                _rear->next = newNode;
                _rear = newNode;
            }
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            QueueNode *temp = _front;
            _front = _front->next;
            free(temp);
            
            if (_front == NULL)
                _rear = NULL;
            _size--;
        }
    }

    T front()
    {
        if (!isEmpty())
            return _front->data;
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