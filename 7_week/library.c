#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct _x {
    int num;
    char name[20];
} Data;

int update(int fd, int k, Data new);

int main (void) {

}

// Returns -1 if update failed, 0 if succsessful
int update(int fd, int k, Data new){
    
    // Fail
    return -1;
}

