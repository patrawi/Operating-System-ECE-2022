#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#define KEY 4567
#define PERMS 0660
int main(int argc, char *argv[])
{
    int d = 0;
    int id;
    int *ptr;
    id = shmget(KEY, sizeof(int), IPC_CREAT | PERMS);
    system("ipcs -m");
    while (d == 0)
    {
        printf("When do you want to know ? please enter 0 for no 1 for yes");
        scanf("%d", &d);
    }
    ptr = (int *)shmat(id, NULL, 0);
    printf("Here is your input from another file %d", *ptr);
}