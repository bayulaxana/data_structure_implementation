/**
 * Implementasi ADT Dynamic Array
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

// Struktur ADT DynamicArray

typedef struct dynamicarr_t {
    int *_arr;
    unsigned _size, _capacity;
} DynamicArray;

// Prototipe fungsi

void dArray_init(DynamicArray *darray);
bool dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, int value);
void dArray_popBack(DynamicArray *darray);
int  dArray_back(DynamicArray *darray);
int  dArray_front(DynamicArray *darray);
void dArray_setAt(DynamicArray *darray, unsigned index, int value);
int  dArray_getAt(DynamicArray *darray, unsigned index);

// Definisi fungsi

void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int*) malloc(sizeof(int) * 2);
}

bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, int value)
{
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = value;
}

void dArray_popBack(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) darray->_size--;
    else return;
}

int dArray_back(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[darray->_size-1];
    else return 0;
}

int dArray_front(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[0];
    else return 0;
}

void dArray_setAt(
    DynamicArray *darray, unsigned index, int value)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            darray->_arr[darray->_size-1] = value;
        else
            darray->_arr[index] = value;
    }
}

int dArray_getAt(DynamicArray *darray, unsigned index)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_arr[darray->_size-1];
        else
            return darray->_arr[index];
    }
}

/* Gunakan ini untuk mempersingkat penulisan kode */

#define d_init dArray_init
#define d_isEmpty dArray_isEmpty
#define d_pushBack dArray_pushBack
#define d_popBack dArray_popBack
#define d_back dArray_back
#define d_front dArray_front
#define d_setAt dArray_setAt
#define d_getAt dArray_getAt

/* */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Buat objek DynamicArray
    DynamicArray myArray;

    // PENTING! Jangan lupa diinisialisasi
    dArray_init(&myArray);

    // Operasi-operasi
    // myArray => [11, 14, 17, 23]
    dArray_pushBack(&myArray, 11);
    dArray_pushBack(&myArray, 14);
    dArray_pushBack(&myArray, 17);
    dArray_pushBack(&myArray, 23);

    // isi myArray => [11, 14, 17]
    dArray_popBack(&myArray);

    int i = 0;
    for (; i < myArray._size; ++i) {
        printf("%d ", dArray_getAt(&myArray, i));
    }

    printf("\n");
    while (!dArray_isEmpty(&myArray)) {
        printf("%d ", dArray_back(&myArray));
        dArray_popBack(&myArray);
    }
    printf("\n");
    
    return 0;
}
