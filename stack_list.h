/*
-- Created by Bayu Laksana on 20 December 2019
-- Implemented for C (Data Structure 2020)
----------------------------------------------
*/

#include <stdlib.h>
#include <stdbool.h>

/* Node structure */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Actual structure */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        if (stack_isEmpty(stack)) {
            newNode->data = value;
            newNode->next = NULL;
            stack->_top = newNode;
        }
        else {
            newNode->data = value;
            newNode->next = stack->_top;
            stack->_top = newNode;
        }
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}