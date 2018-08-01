#include <stdio.h>
#include <stdlib.h>

int main (void) {

    unsigned short a, b, c;
    a = 0x5555;  b = 0xAAAA;  c = 0x0001;

    (void) b;
    (void) c;

    printf("0x%x\n", a);

    return 0;
}
