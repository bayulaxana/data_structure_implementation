/*
-- Created by Bayu Laksana on 9 January 2019
-- Implemented for C++ (Data Structure 2020)
----------------------------------------------
*/

#include <stdlib.h>

/* Structure of Doubly Linked List */

template <typename T=int>
struct ListDoubly
{
    // Node Structure
    struct DListNode {
        T data;
        DListNode *next, *prev;
    } *_head, *_tail;
    unsigned _size;

    ListDoubly() {
        _head = _tail = NULL;
        _size = 0;
    }

    // Utility function
    DListNode* __createNode(T value)
    {
        DListNode *newNode = \
            (DListNode*) malloc (sizeof(DListNode));
    
        if (!newNode) return NULL;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        return (DListNode*) newNode;
    }

    bool isEmpty() {
        return (_head == NULL && _tail == NULL);
    }

    void pushFront(T value)
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

    void pushBack(T value)
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

    void insert(T value, unsigned index)
    {
        if (index == 0) {
            pushFront(value);
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

    T front()
    {
        if (!isEmpty())
            return _head->data;
        exit(-1);
    }

    T back()
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