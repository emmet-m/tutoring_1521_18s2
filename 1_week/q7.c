#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h> // strerror()

int main (int argc, char * argv[], char * env[]) {
    int n, a, b, c;
    n = scanf("%d %d %d", &a, &b, &c);

    // How can we deal with errors from the above function?

    return EXIT_SUCCESS;
}
