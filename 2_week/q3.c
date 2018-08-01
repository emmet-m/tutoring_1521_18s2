#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int  x;  // a variable located at address 1000 with initial value 0
    int *p;  // a variable located at address 2000 with initial value 0

    p = &x;

    x = 5;

    *p = 3;

    x = (int)p;

    x = (int)&p;

    p = NULL;

    *p = 1;

    return 0;
}
