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
#include <iostream>

using namespace std;

/* Structure of Singly Linked List */

template <typename T=int>
class SinglyList
{
private:
    // Node structure
    struct SListNode {
        T data;
        SListNode *next;
    } *_head;
    unsigned _size;

public:
    SinglyList() {
        _head = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == NULL);
    }

    void pushFront(T value)
    {
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            _size++;
            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _head;

            newNode->data = value;
            _head = newNode;
        }
    }

    void pushBack(T value)
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

    void insertAt(int index, T value)
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
            SListNode *nextTo = temp->next->next;
            free(temp->next);
            temp->next = nextTo;
            _size--;
        }
    }

    void remove(T value)
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

    T front() {
        if (!isEmpty()) return _head->data;
        else exit(-1);
    }

    T back() 
    {
        if (!isEmpty()) {
            SListNode *temp = _head;
            while (temp->next != NULL)
                temp = temp->next;
            return temp->data;
        }
        else exit(-1);
    }

    T getAt(int index) {
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
    
    return 0;
}