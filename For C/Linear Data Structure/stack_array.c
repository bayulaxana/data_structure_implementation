/**
 * Implementasi ADT StackArray (Stack menggunakan static Array)
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

/* Struktur ADT StackArray */

typedef struct stackarr_t {
    int *_element, _topIndex;
    unsigned int _size, _capacity;
} StackArray;

/* Function prototype */

void stackArray_init(StackArray *stack, unsigned stackSize);
bool stackArray_isEmpty(StackArray *stack);
void stackArray_push(StackArray *stack, int value);
void stackArray_pop(StackArray *stack);
int  stackArray_top(StackArray *stack);

/* Function definition below */

void stackArray_init(StackArray *stack, unsigned int stackSize) 
{
    stack->_element  = (int*) malloc(sizeof(int) * stackSize);
    stack->_size     = 0;
    stack->_topIndex = -1;
    stack->_capacity = stackSize;
}

bool stackArray_isEmpty(StackArray *stack) {
    return (stack->_topIndex == -1);
}

void stackArray_push(StackArray *stack, int value)
{
    if (stack->_size + 1 <= stack->_capacity) {
        stack->_element[++stack->_topIndex] = value;
        stack->_size++;
    }
}

void stackArray_pop(StackArray *stack)
{
    if (!stackArray_isEmpty(stack)) {
        stack->_topIndex--;
        stack->_size--;
    }
}

int stackArray_top(StackArray *stack)
{
    if (!stackArray_isEmpty(stack)) {
        return stack->_element[stack->_topIndex];
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    // Buat objek StackArray
    StackArray myStack;

    // PENTING! Jangan lupa diinisialisasi
    stackArray_init(&myStack, 10);

    // Operasi pada stack
    stackArray_push(&myStack, 1);
    stackArray_push(&myStack, 2);
    stackArray_push(&myStack, 3);

    // cetak isi stack
    while (!stackArray_isEmpty(&myStack)) {
        printf("%d ", stackArray_top(&myStack));
        stackArray_pop(&myStack);
    }
    puts("");
    return 0;
}
