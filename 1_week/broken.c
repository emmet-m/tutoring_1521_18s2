#include <stdio.h>
int main () {
    int * ptr = NULL;
    *ptr = 1; // Will crash

    return 0;
}
