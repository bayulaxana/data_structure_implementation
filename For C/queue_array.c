/**
 * Implementasi ADT QueueArray (Queue menggunakan array)
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
#include <stdio.h>

/* Struktur ADT QueueArray */

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

int main(int argc, char const *argv[])
{
    // Buat objek QueueArray
    QueueArray myQueue;

    // PENTING! Jangan lupa diinisialisasi
    queueArray_init(&myQueue, 10);

    // Operasi pada queue
    queueArray_push(&myQueue, 1);
    queueArray_push(&myQueue, 2);
    queueArray_push(&myQueue, 3);

    // cetak isi queue
    while (!queueArray_isEmpty(&myQueue)) {
        printf("%d ", queueArray_front(&myQueue));
        queueArray_pop(&myQueue);
    }
    puts("");
    return 0;
}
