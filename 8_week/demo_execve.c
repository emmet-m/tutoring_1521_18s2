#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char * argv[], char * envp[])
{
    execve("cat", argv, NULL);
    
    printf("Execve failed!\n");

    return 0;
}
