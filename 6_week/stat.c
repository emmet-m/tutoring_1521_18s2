#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main (void) {

    // Maybe stat the graphics file? :^)

    struct stat * s = malloc(sizeof(struct stat));

    stat("writer.c", s);

    printf("%lu\n", s->st_size);
    
    return 0;
}
