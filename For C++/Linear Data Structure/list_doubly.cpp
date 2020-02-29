/**
 * Implementasi ADT List (Doubly Linked List)
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

// Node Structure
struct DListNode {
    int data;
    DListNode *next, *prev;
};

/* Structure of Doubly Linked List */
struct List
{
    DListNode *_head, *_tail;
    unsigned _size;

    // Utility function
    DListNode* __createNode(int value)
    {
        DListNode *newNode = \
            (DListNode*) malloc (sizeof(DListNode));
    
        if (!newNode) return NULL;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        return (DListNode*) newNode;
    }

    void init() {
        _head = _tail = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == NULL && _tail == NULL);
    }

    void pushFront(int value)
    {
        DListNode *newNode = __createNode(value);
        if (newNode) {
            _size++;
            if (isEmpty()) {
                _head = newNode;
                _tail = newNode;
                return;
            }

            newNode->next = _head;
            _head->prev = newNode;
            _head = newNode;
        }
    }

    void pushBack(int value)
    {
        DListNode *newNode = __createNode(value);
        if (newNode) {
            _size++;
            if (isEmpty()) {
                _head = newNode;
                _tail = newNode;
                return;
            }

            _tail->next = newNode;
            newNode->prev = _tail;
            _tail = newNode;
        }
    }

    void insertAt(unsigned index, int value)
    {
        if (index == 0) {
            pushFront(value);
            return;
        }
        else if (index >= _size) {
            pushBack(value);
            return;
        }

        DListNode *newNode = __createNode(value);
        if (newNode) {
            if (isEmpty()) {
                _head = newNode;
                _tail = newNode;
                _size++;
                return;
            }

            DListNode *temp = _head;
            unsigned _i = 0;

            while ((_i < index - 1) && \
                    temp->next != NULL)
            {
                temp = temp->next;
                _i++;
            }
            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next)
                temp->next->prev = newNode;
            temp->next = newNode;
            _size++;
        }
    }

    int front()
    {
        if (!isEmpty())
            return _head->data;
        exit(-1);
    }

    int back()
    {
        if (!isEmpty())
            return _tail->data;
        exit(-1);
    }

    void popFront()
    {
        if (!isEmpty()) {
            DListNode *temp = _head;
            if (_head == _tail) {
                _head = NULL;
                _tail = NULL;
                free(temp);
            }
            else {
                _head = _head->next;
                _head->prev = NULL;
                free(temp);
            }
            _size--;   
        }
    }

    void popBack()
    {
        if (!isEmpty()) {
            DListNode *temp;
            if (_head == _tail) {
                temp = _head;
                _head = NULL;
                _tail = NULL;
                free(temp);
            }
            else {
                temp = _tail;
                _tail = _tail->prev;
                _tail->next = NULL;
                free(temp);
            }
            _size--;
        }
    }

    unsigned size() {
        return _size;
    }
};

int main(int argc, char const *argv[])
{
    // Buat objek SinglyList
    List myList;
    // PENTING! Jangan lupa di-init()
    myList.init();
    
    myList.pushBack(2);
    myList.pushBack(3);
    myList.pushBack(4);
    myList.pushBack(5);
    myList.pushBack(6);
    // isi list => [2, 3, 4, 5, 6]

    myList.pushFront(9);
    myList.pushFront(8);
    myList.pushFront(7);
    myList.pushFront(6);
    // isi list => [6, 7, 8, 9, 2, 3, 4, 5, 6]
    
    myList.popFront();
    myList.popBack();
    myList.insertAt(2, 11);
    myList.insertAt(4, 17);
    // isi list => [7, 8, 11, 9, 17, 2, 3, 4, 5]

    // print list reversed
    while (!myList.isEmpty()) {
        printf("%d ", myList.back());
        myList.popBack();
    }
    printf("\n");    
    return 0;
}