/*
    Ubah string CHANGE_THIS menjadi salah satu dari
    - LIST_DOUBLY
    - LIST_SINGLY
    - STACK
    - QUEUE
    - PRIORITY_QUEUE
*/
#define LIST_SINGLY
#include <stdio.h>

#ifdef CHANGE_THIS
int main()
{
    puts("Hello World");
    return 0;
}
#endif

#ifdef LIST_DOUBLY
#include "list_doubly.h"
int main()
{
    List myList;
    dlist_init(&myList);

    dlist_pushBack(&myList, 5);
    dlist_pushBack(&myList, 6);
    dlist_pushBack(&myList, 7);
    dlist_pushFront(&myList, 11);
    dlist_pushFront(&myList, 10);

    // while (!dlist_isEmpty(&myList)) {
    //     printf("%d ", dlist_front(&myList));
    //     dlist_popFront(&myList);
    // }
    return 0;
}
#endif

#ifdef LIST_SINGLY
#include "list_singly.h"
int main()
{
    SinglyList myList;
    slist_init(&myList);

    slist_pushBack(&myList, 5);
    slist_pushBack(&myList, 6);
    slist_pushBack(&myList, 7);
    slist_pushFront(&myList, 11);
    slist_pushFront(&myList, 10);

    while (!slist_isEmpty(&myList)) {
        printf("%d ", slist_front(&myList));
        slist_popFront(&myList);
    }
    printf("\n");
    return 0;
}
#endif

#ifdef STACK
#include "stack_list.h"
int main()
{
    
    return 0;
}
#endif

#ifdef QUEUE
#include "queue_list.h"
int main()
{
    
    return 0;
}
#endif

#ifdef PRIORITY_QUEUE
#include "priority_queue_list.h"
int main()
{
    
    return 0;
}
#endif