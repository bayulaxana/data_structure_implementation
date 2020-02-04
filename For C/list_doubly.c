/**
 * Implementasi ADT List (Doubly Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>

/* Struktur Node */

typedef struct dnode_t {
    int data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT List */

typedef struct dlist_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} List;

/* DAFTAR FUNGSI YANG TERSEDIA */

DListNode* __dlist_createNode(int value);
void dlist_init(List *list);
bool dlist_isEmpty(List *list);
void dlist_pushFront(List *list, int value);
void dlist_pushBack(List *list, int value);
void dlist_insertAt(List *list, unsigned index, int value);
int  dlist_front(List *list);
int  dlist_back(List *list);
void dlist_popFront(List *list);
void dlist_popBack(List *list);
// void dlist_remove(List *list, int element);
// void dlist_removeAt(List *list, int index);

/* Function definition */

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void dlist_init(List *list)
{
    list->_head = list->_tail = NULL;
    list->_size = (unsigned) 0;
}

bool dlist_isEmpty(List *list) {
    return (list->_head == NULL && \
            list->_tail == NULL);
}

void dlist_pushFront(List *list, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        list->_size++;
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        newNode->next = list->_head;
        list->_head->prev = newNode;
        list->_head = newNode;
    }
}

void dlist_pushBack(List *list, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        list->_size++;
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        list->_tail->next = newNode;
        newNode->prev = list->_tail;
        list->_tail = newNode;
    }
}

void dlist_insertAt(List *list, unsigned index, int value)
{
    if (index == 0) { 
        dlist_pushFront(list, value);
        return;
    }
    else if (index >= list->_size) {
        dlist_pushBack(list, value);
        return;
    }

    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        DListNode *temp = list->_head;

        unsigned _i = 0;
        while (_i < index - 1 && temp->next != NULL) {
            temp = temp->next;
            _i++;
        }
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        list->_size++;
    }
}

int dlist_front(List *list) {
    if (!dlist_isEmpty(list)) {
        return (list->_head->data);
    }
    return 0;
}

int dlist_back(List *list) {
    if (!dlist_isEmpty(list)) {
        return (list->_tail->data);
    }
    return 0;
}

void dlist_popFront(List *list)
{
    if (!dlist_isEmpty(list)) {
        DListNode *temp = list->_head;
        if (list->_head == list->_tail) {
            list->_head = NULL;
            list->_tail = NULL;
            free(temp);
        }
        else {
            list->_head = list->_head->next;
            list->_head->prev = NULL;
            free(temp);
        }
        list->_size--;
    }
}

void dlist_popBack(List *list)
{
    if (!dlist_isEmpty(list)) {
        DListNode *temp;
        if (list->_head == list->_tail) {
            temp = list->_head;
            list->_head = NULL;
            list->_tail = NULL;
            free(temp);
        }
        else {
            temp = list->_tail;
            list->_tail = list->_tail->prev;
            list->_tail->next = NULL;
            free(temp);
        }
        list->_size--;
    }
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Buat objek List
    List myList;

    // PENTING! Jangan lupa diinisialisasi
    dlist_init(&myList);

    // Gunakan operasi linked list
    dlist_pushBack(&myList, 1);
    dlist_pushBack(&myList, 2);
    dlist_pushBack(&myList, 3);
    dlist_pushBack(&myList, 4);

    dlist_pushFront(&myList, 10);
    dlist_pushFront(&myList, 9);
    dlist_pushFront(&myList, 8);
    dlist_pushFront(&myList, 7);

    dlist_popBack(&myList);
    dlist_popFront(&myList);

    // Isi List => [8, 9, 10, 1, 2, 3]
    dlist_insertAt(&myList, 6, 100);
    dlist_insertAt(&myList, 1, 13);
    
    // Isi List => [8, 13, 9, 10, 1, 2, 3, 100]
    // printlist
    while (!dlist_isEmpty(&myList)) {
        printf("%d ", dlist_front(&myList));
        dlist_popFront(&myList);
    }
    puts("");
    return 0;
}
