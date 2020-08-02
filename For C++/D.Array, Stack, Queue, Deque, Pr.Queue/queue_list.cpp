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
#include <stdio.h>

using namespace std;

// Node Structure
struct QueueNode {
    int data;
    QueueNode *next;
};

/* Structure of Queue using List */
struct Queue
{
    QueueNode *_front, *_rear;
    unsigned _size;

    void init()
    {
        _size  = 0;
        _front = NULL;
        _rear  = NULL;
    }

    bool isEmpty() {
        return (_front == NULL && _rear == NULL);
    }

    void push(int value)
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

    int front()
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
    // Buat objek queue
    Queue myQueue;
    // PENTING!! Jangan lupa di-init()
    myQueue.init();

    myQueue.push(23);
    myQueue.push(11);
    myQueue.push(3);
    myQueue.push(35);

    // Cetak isi queue
    while (!myQueue.isEmpty()) {
        printf("%d ", myQueue.front());
        myQueue.pop();
    }
    puts("");
    return 0;
}