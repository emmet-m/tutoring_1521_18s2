#include <stdio.h>
#include <stdlib.h>


int main (int argc, char * argv[], char * env[]) {

    if (argc == 1) {
        printf("Supply an x value as an argument!\n");
        exit(1);
    }

    int x = atoi(argv[1]);

    if (x == 0) {
        printf("One\n");
    }

    if (x == 0)
        printf("Two\n");

    if (x == 0) {
        printf("Three A\n");
        printf("Three B\n");
    }

    if (x == 0)
        printf("Four A\n");
        printf("Four B\n");

    return 0;
}
