// Interface to Stack data type

#include <stdio.h>
#include "Stack.h"


void initStack(Stack *s){
    s->top = 0;
}

int pushStack(Stack *s, Item val){
    if (s->top == MAX_STACK) {
        return 0; // Failure
    }

    s->items[s->top] = val;
    s->top++;
    return 1; // Success
}

Item popStack(Stack *s){
    return s->items[(s->top--) - 1];
}

int isEmptyStack(Stack s){
    return (s.top == 0);
}

void showStack(Stack s){
    printf("Stack: '");
    for (int i = 0; i < s.top; ++i) {
        putchar(s.items[i]);
    }
    printf("' | top\n");
}

