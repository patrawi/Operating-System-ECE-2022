#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
// 2 Parallel Computing
#define KEY 4567
#define PERMS 0660

int main(int argc, char *argv[])
{
    int id;
    int *ptr;
    id = shmget(KEY, sizeof(int), IPC_CREAT | PERMS);
    ptr = (int *)shmat(id, NULL, 0);
    *ptr = 0;
    if (fork() == 0)
    {
        int a = 1 + 2;
        (*ptr) += a;
        if (fork() == 0)
        {
            int b = 3 + 4;
            (*ptr) *= b;

            if (fork() == 0)
            {
                int c = 5 + 6;
                (*ptr) *= c;
                exit(1);
            }
            else
            {
                wait(NULL);
            }
            exit(1);
        }
        else
        {
            wait(NULL);
        }
        exit(1);
    }
    else
    {
        wait(NULL);
        printf("Value of *ptr = %d \n", *ptr);
    }
}