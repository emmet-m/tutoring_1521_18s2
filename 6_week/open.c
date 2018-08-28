#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/*
 * List of main open codes:
 *  
 * O_RDONLY
 * O_WRONLY
 * O_CREAT
 * O_APPEND
 * O_TRUNC
 * O_RDWR
 */

int main (int argc, char * argv, char * envp) {

    
    // fopen(FilePath, "r");
    open(FilePath, O_RDONLY);

    // fopen(FilePath, "a");
    open(FilePath, O_APPEND | O_CREAT);

    // fopen(FilePath, "w");
    open(FilePath, O_WRONLY | O_CREAT | O_TRUNC);

    // fopen(FilePath, "r+");
    open(FilePath, O_RDWR | O_CREAT);

    // fopen(FilePath, "w+");
    open(FilePath, O_RDWR | O_CREAT | O_TRUNC);


    return 0;
}
