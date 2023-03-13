int main(int argc, char *argv[])
{
    int fd1, fd2;

    if(argc != 3)
    {
        printf("Usage: %s <source> <destination>", argv[0]);
        exit(1);
    }

    fd1 = link(argv[1], argv[2]);
    if(fd1 == -1)
    {
        perror("link");
        exit(1);
    }

    fd2 = unlink(argv[1]);
    if(fd2 == -1)
    {
        perror("unlink");
        exit(1);
    }

}