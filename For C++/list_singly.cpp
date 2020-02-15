/**
 * Implementasi ADT SInglyList (Singly Linked List)
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

// Node structure
struct SListNode 
{
    int data;
    SListNode *next;
}; 

/* Structure of Singly Linked List */
struct SinglyList
{
    SListNode *_head;
    unsigned _size;

    void init() {
        _head = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == NULL);
    }

    void pushFront(int value)
    {
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            
            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _head;
            _head = newNode;
        }
    }

    void pushBack(int value)
    {
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            newNode->next = NULL;
            
            if (isEmpty()) 
                _head = newNode;
            else {
                SListNode *temp = _head;
                while (temp->next != NULL) 
                    temp = temp->next;
                temp->next = newNode;
            }
        }
    }

    void popFront()
    {
        if (!isEmpty()) {
            SListNode *temp = _head;
            _head = _head->next;
            free(temp);
            _size--;
        }
    }

    void popBack()
    {
        if (!isEmpty()) {
            SListNode *nextNode = _head->next;
            SListNode *currNode = _head;

            if (currNode->next == NULL) {
                free(currNode);
                _head = NULL;
                return;
            }

            while (nextNode->next != NULL) {
                currNode = nextNode;
                nextNode = nextNode->next;
            }
            currNode->next = NULL;
            free(nextNode);
            _size--;
        }
    }

    void insertAt(int index, int value)
    {
        if (isEmpty() || index >= _size) {
            pushBack(value);
            return;
        }
        else if (index == 0) {
            pushFront(value);
            return;
        }

        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            SListNode *temp = _head;
            int _i = 0;
            
            while (temp->next != NULL && _i < index-1) {
                temp = temp->next;
                _i++;
            }
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            _size++;
        }
    }

    void removeAt(int index)
    {
        if (!isEmpty()) {
            
            /* Kasus apabila posisinya melebihi batas */
            if (index >= _size) {
                popBack();
                return;    
            }
            else if (index == 0 || index < 0) {
                popFront();
                return;
            }

            SListNode *temp = _head;
            int _i = 0;
            while (temp->next != NULL && _i < index-1) {
                temp = temp->next;
                _i++;
            }
            SListNode *nextinto = temp->next->next;
            free(temp->next);
            temp->next = nextinto;
            _size--;
        }
    }

    void remove(int value)
    {
        if (!isEmpty()) {
            SListNode *temp, *prev;
            temp = _head;

            if (temp->data == value) {
                popFront();
                return;
            }
            while (temp != NULL && temp->data != value) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL) return;
            prev->next = temp->next;
            free(temp);
            _size--;
        }
    }

    int front() {
        if (!isEmpty()) return _head->data;
        else exit(-1);
    }

    int back() 
    {
        if (!isEmpty()) {
            SListNode *temp = _head;
            while (temp->next != NULL)
                temp = temp->next;
            return temp->data;
        }
        else exit(-1);
    }

    int getAt(int index) {
        if (!isEmpty()) {
            SListNode *temp = _head;
            int _i = 0;
            while (temp->next != NULL && _i < index) {
                temp = temp->next;
                _i++;
            }
            return temp->data;
        }
        else exit(-1);
    }
};

int main(int argc, char const *argv[])
{
    // Buat objek SinglyList
    SinglyList myList;
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

    // print isi list dari depan ke belakang
    for (int i = 0; i < myList._size; i++) {
        printf("%d ", myList.getAt(i));
    }
    printf("\n");
    
    myList.popFront();
    myList.popBack();
    myList.insertAt(2, 11);
    myList.insertAt(4, 17);
    // isi list => [7, 8, 11, 9, 17, 2, 3, 4, 5]

    myList.removeAt(1);
    myList.remove(3);
    // isi list => [7, 11, 9, 17, 2, 4, 5]

    // print list reversed
    while (!myList.isEmpty()) {
        printf("%d ", myList.back());
        myList.popBack();
    }
    printf("\n");
    return 0;
}