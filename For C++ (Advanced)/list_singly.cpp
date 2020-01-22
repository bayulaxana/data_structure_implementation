/**
 * Implementasi ADT SInglyList (Singly Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C++
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <iostream>

using namespace std;

/* Structure of Singly Linked List */

template <typename T=int>
struct SinglyList
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
    SinglyList<long long> myList;
    
    myList.pushBack(5);
    myList.pushBack(6);
    myList.pushBack(7);
    myList.pushFront(11);
    myList.pushFront(10);
    myList.pushFront(14);

    myList.popBack();

    while (!myList.isEmpty()) {
        cout << myList.front() << endl;
        myList.popFront();
    }

    SinglyList<char> myList2;
    myList2.pushBack('A');
    myList2.pushBack('V');
    myList2.pushBack('L');
    myList2.pushBack('X');
    myList2.pushFront(' ');
    myList2.pushFront('E');
    myList2.pushFront('E');
    myList2.pushFront('R');
    myList2.pushFront('T');
    myList2.pushFront('T');

    myList2.popBack(); myList2.popFront();

    while (!myList2.isEmpty()) {
        cout << myList2.front();
        myList2.popFront();
    }
    puts("");
    return 0;
}