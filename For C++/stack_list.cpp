/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C++
 *
 */

#include <stdlib.h>
#include <stdio.h>

using namespace std;

// Node structure
struct StackNode {
    int data;
    StackNode *next;
};

/* Structure of Stack using List */
struct Stack
{
    StackNode *_top;
    unsigned _size;

    void init() 
    {
        _size = 0;
        _top = nullptr;
    }

    bool isEmpty() {
        return (_top == nullptr);
    }

    void push(int value)
    {
        StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
        if (newNode) {
            _size++;
            newNode->data = value;

            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _top;
            _top = newNode;
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            StackNode *temp = _top;
            _top = _top->next;
            free(temp);
            _size--;
        }
    }

    int top()
    {
        if (!isEmpty())
            return _top->data;
        exit(-1);
    }
};

int main(int argc, char const *argv[])
{
    // Buat objek stack
    Stack myStack;
    // PENTING!! Jangan lupa di-init
    myStack.init();

    myStack.push(6);
    myStack.push(7);
    myStack.push(1);
    myStack.push(2);

    // Cetak isi stack
    while (!myStack.isEmpty()) {
        printf("%d", myStack.top());
        myStack.pop();
    }
    puts("");
    return 0;
}