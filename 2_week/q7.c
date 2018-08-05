#include <stdio.h>
#include <stdlib.h>

#define READING   0x01
#define WRITING   0x02
#define AS_BYTES  0x04
#define AS_BLOCKS 0x08
#define LOCKED    0x10

typedef unsigned char device_t;


int main (void) {

    // mark the device as locked for reading bytes
    // mark the device as locked for writing blocks
    // set the device as locked, leaving other flags unchanged
    // remove the lock on a device, leaving other flags unchanged
    // switch a device between reading and writing, leaving other flags unchanged
    
    return 0;
}
