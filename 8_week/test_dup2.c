#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv[], char * envp[])
{
    // Open some random file
    int fd = open ("output.txt", O_CREAT | O_RDWR | O_TRUNC);

    if (fd < 0) {
        fprintf(stderr, "Whoops! It broke\n");
    }

    // How to redirect this to a file?

    printf("Testing!\n");
    return 0;
}
