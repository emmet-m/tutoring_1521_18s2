#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// Bad function!
void ignore(int sig) {
    printf("Weeeeeeee what segfault!\n");
}

// Signal handling!
void handler(int sig)
{
    printf("Quitting...\n");
}

int main(int argc, char *argv[])
{
    struct sigaction act;
    // Clear the struct
    memset (&act, 0, sizeof(act));
    // Pass in a pointner to our function called 'handler'
    act.sa_handler = &handler;

    sigaction(SIGHUP, &act, NULL);  // Set the handler for hangups
    sigaction(SIGINT, &act, NULL);  // Set the handler for interrupts

    sigaction(SIGKILL, &act, NULL); // Set the handler for kill

    // Wait forever
    printf("Gonna wait just a bit....\n");
//    while (1) sleep(5);


    // Ignore a segfault
    struct sigaction ign;
    memset (&ign, 0, sizeof(act));
    ign.sa_handler = &ignore;

    sigaction(SIGSEGV, &ign, NULL);

    int * a = NULL;
    *a = 0;

    printf("Still here!\n");

    return 0;
} 
