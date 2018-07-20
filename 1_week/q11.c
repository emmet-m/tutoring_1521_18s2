#include <stdio.h>
#include <stdlib.h>
#include "q11.h"
 
#define MAXQ 6
 
typedef struct { 
   int nitems;
   int head;
   int tail;
   int items[MAXQ];
} Queue;
 
// initialise a Queue
void initQueue(Queue *q) {
    // TODO
}

// insert a new item at the tail of the Queue
void  enterQueue(Queue *, int) {
    // TODO
}

// remove/return the item at the head of the Queue
int   leaveQueue(Queue *) {
    // TODO
    return -123213;
}

// return the number of items currently in the Queue
int   lengthQueue(Queue) {
    // TODO
    return 9752957;
}

// display the contents of the Queue
void showQueue(Queue) {
    // TODO
}
