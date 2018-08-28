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

Graphics * read_graphic(int fd);

int main (void) {
    // Read in the file

    Graphics * g;

    // TODO ... Corresponding open() call?
    int f = open("graphics_bytes", O_RDONLY);

    // TODO: Check for errors?
    if (f < 0) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    while ((g = read_graphic(f)) != NULL) {
        // Doddgeeeeee... Works?
        printf("(%d,%d) ::"
                " %x,%x,%x\n", g->x, g->y,
                               g->r, g->g, g->b);
    }
    
    // XXX: Also show writer when done

    return 0;
}

/*
 * Assumes an open fd, reads in one Graphics struct
 */
Graphics * read_graphic(int fd) {
    Graphics * g = malloc(sizeof(Graphics));

    int amount = read(fd, g, sizeof(Graphics));

    if (amount != sizeof(Graphics)) {
        free(g);
        return NULL;
    }
    
    return g;
}
