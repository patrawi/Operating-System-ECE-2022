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
    int id;
    int i;
    int *ptr;
    id = shmget(KEY, sizeof(int), IPC_CREAT | PERMS);
    ptr = (int *)shmat(id, NULL, 0);
    *ptr = 0;
    printf("Enter your input for displaying :");
    scanf("%d", ptr);
}