/*
-- Created by Bayu Laksana on 20 December 2019
-- Implemented for C (Data Structure 2020)
----------------------------------------------
*/

#include <stdlib.h>
#include <stdbool.h>

/* Actual structure */

typedef struct queuearr_t {
    int *_element;
    int _front, 
        _rear;
    unsigned _size, _capacity;
} QueueArray;

/* Function prototype */

void queueArray_init(QueueArray *queue, unsigned queueSize);
bool queueArray_isEmpty(QueueArray *queue);
void queueArray_push(QueueArray *queue, int value);
void queueArray_pop(QueueArray *queue);
int  queueArray_front(QueueArray *queue);
unsigned queueArray_size(QueueArray *queue);

/* Function definition below */

void queueArray_init(QueueArray *queue, unsigned queueSize)
{
    queue->_element = (int*) malloc(sizeof(int) * queueSize);
    queue->_front = -1;
    queue->_rear  = -1;
    queue->_size  = 0;
    queue->_capacity = queueSize;
}

bool queueArray_isEmpty(QueueArray *queue) {
    return (queue->_front == -1);
}

void queueArray_push(QueueArray *queue, int value)
{
    if (queue->_size + 1 <= queue->_capacity) {
        if (queue->_front == -1)
            queue->_front = 0;
        queue->_rear = (queue->_rear + 1) % queue->_capacity;
        queue->_element[queue->_rear] = value;
        queue->_size++; 
    }
}

void queueArray_pop(QueueArray *queue)
{
    if (!queueArray_isEmpty(queue)) {
        if (queue->_front == queue->_rear)
            queue->_front = queue->_rear = -1;
        else
            queue->_front = (queue->_front + 1) % queue->_capacity;
        queue->_size--;
    }
}

int queueArray_front(QueueArray *queue) 
{
    if (!queueArray_isEmpty(queue)) {
        return queue->_element[queue->_front];
    }
    return 0;
}

unsigned queueArray_size(QueueArray *queue) {
    return (queue->_size);
}