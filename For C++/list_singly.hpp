/*
-- Created by Bayu Laksana on 9 January 2019
-- Implemented for C++ (Data Structure 2020)
----------------------------------------------
*/

#include <stdlib.h>

/* Structure of Singly Linked List */

template <typename T=int>
struct SinglyList
{
    // Node structure
    struct SListNode {
        T data;
        SListNode *next;
    } *_head;
    unsigned _size;

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
};