#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int x = 1;

    pid_t pid = fork();
    if (pid < 0)
    { 
        fprintf(stderr, "Fork failed\n"); 
        exit(1);
    }
    else if (pid > 0) {
        // Who prints this?
        x++;  
        printf("x = %d\n", x);
    } else { 
        // Who prints this?
        x--;  
        printf("x = %d\n", x);
    }

    return 0;
}
