#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack_array.h"

int main(int argc, char const *argv[])
{
    // Testing
    StackArray *myStack = (StackArray*) malloc(sizeof(StackArray));
    stackArray_init(myStack, 100);

    char str[20];
    scanf("%s", str);
    int len = (int) strlen(str),
        bound = (int) ceil((double)len/2.0);
    
    int i = bound;
    for (; i < len; ++i) stackArray_push(myStack, (int) str[i]);

    bool isPalindrome = true;
    for (i = 0; i < len/2; i++) {
        if ((char) stackArray_top(myStack) != str[i])
            isPalindrome = false;
        stackArray_pop(myStack);
    }

    puts(isPalindrome ? "PALINDROM" : "NOT PALINDROM");
    return 0;
}
