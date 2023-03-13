#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
#include<string.h>

int main(int argc, char *argv[])
{
    printf("Main Function\n");
    int retval = 1;
    pid_t pid = fork();
    if(pid<0){
        printf("Fork Failed\n");
    }
    if (pid == 0)
    {
        printf("Child Process\n");
        printf("Child Process ID: %d\nParent Process ID: %d\n", getpid(), getppid());
        execl("./binarysearch", argv[1], NULL);
    }
    else{
        printf("Parent Process\n");
        printf("Parent Process ID: %d\nChild Process ID: %d\n", getpid(), pid);
        wait(&retval);
        printf("Child Process Exited with Status: %d\n", retval);
    }

}