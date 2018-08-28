#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


typedef struct _graphics {
    int   x;  // x coordinate
    int   y;  // y coordinate
    char  r;  // red level
    char  g;  // green level
    char  b;  // blue level
} Graphics;

int main () {

    Graphics a = {0,0, 0,0,0};
    Graphics b = {1,0, 100, 50, 255};
    Graphics c = {-3,5, 50, 200, 3};

    int fd = open("graphics_bytes", O_WRONLY | O_CREAT);

    if (fd < 0) return 1; // Fail
    
    printf("Writing the bytes...\n");

    write(fd, &a, sizeof(Graphics));
    write(fd, &b, sizeof(Graphics));
    write(fd, &c, sizeof(Graphics));

    return 0;
}
