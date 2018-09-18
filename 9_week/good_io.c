#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <semaphore.h>

int main(void)
{
    void delay(int);
    int pid;
    sem_t * lock;

    // What does man init say about this?
    lock = sem_open("mysemaphore", O_CREAT, 0644, 1);
    if (lock == SEM_FAILED) {
        fprintf(stderr, "Semaphor broke :(\n");
        exit(1);
    }

    setbuf(stdout, NULL);
    if ((pid = fork()) != 0) {
        for (int i = 0; i < 5; i++) {
            sem_wait(lock);
            for (int j = 0; j < 26; j++) putchar('a'+j);
            putchar('\n');
            sem_post(lock);
            delay(100000);
        }
    }
    else {
        for (int i = 0; i < 5; i++) {
            sem_wait(lock);
            for (int j = 0; j < 26; j++) putchar('A'+j);
            putchar('\n');
            sem_post(lock);
            delay(100000);
        }
    }
    sem_destroy(lock);
    return 0;
}

void delay(int max)
{
    for (int i = 0; i < max; i++) /* waste time */;
}

