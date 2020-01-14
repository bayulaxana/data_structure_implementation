/*
-- Created by Bayu Laksana on 20 December 2019
-- Implemented for C (Data Structure 2020)
----------------------------------------------
*/

#include <stdlib.h>
#include <stdbool.h>

/* Node structure */

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

/* Actual list structure */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* Function prototype */

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, int value);
void slist_popFront(SinglyList *list);
void slist_pushBack(SinglyList *list, int value);
void slist_popBack(SinglyList *list);
int  slist_front(SinglyList *list);
int  slist_back(SinglyList *list);

/* Function definition below */

void slist_init(SinglyList *list) 
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, int value) 
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        
        newNode->data = value;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;

            temp->next = newNode;
        }
    }
}

void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

int slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL) 
            temp = temp->next;
        return temp->data;
    }
    return 0;
}