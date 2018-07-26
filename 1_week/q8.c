#include <stdlib.h>
#include <stdio.h>

int getInt(int * potential_error) {
    *potential_error = 0;
    // ...
    if (something_wrong) {
        *potential_error = 1;
    }
    return 0;
}

int main (int argc, char * argv[], char * env[]) {

    int a;
    int b;

    b = getInt(&a);

    if (a == 1) {
        // whatever
    }

    return EXIT_SUCCESS;
}


