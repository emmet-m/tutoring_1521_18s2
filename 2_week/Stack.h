// Interface to Stack data type

#define MAX_STACK 1000

typedef char Item;

typedef struct _stack {
    int  top;
    Item items[MAX_STACK];
} Stack;

void initStack(Stack *s);
int  pushStack(Stack *s, Item val);
Item popStack(Stack *s);
int  isEmptyStack(Stack s);
void showStack(Stack s);
