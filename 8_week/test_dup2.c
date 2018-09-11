#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv[], char * envp[])
{
    // Open some random file
    open ("output.txt", O_CREAT | O_RDWR | O_TRUNC);
    return 0;
}
