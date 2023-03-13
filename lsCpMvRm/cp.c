#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>

#define BUF_SIZE 8192

int main(int argc, char *argv[])
{
    int fd1, fd2, n;
    char buf[BUF_SIZE];

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <source> <destination>", argv[0]);
        exit(1);
    }

    if ((fd1 = open(argv[1], O_RDONLY)) == -1)
    {
        perror("open");
        exit(1);
    }

    if ((fd2 = open(argv[2], 577, 777)) == -1)
    {
        perror("open");
        exit(1);
    }

    while ((n = read(fd1, buf, BUF_SIZE)) > 0)
    {
        if (write(fd2, buf, n) != n)
        {
            perror("write");
            exit(1);
        }
    }

    close(fd1);
    close(fd2);

    return 0;
}