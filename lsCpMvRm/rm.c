int main(int argc, char *argv[])
{
    if (unlink(argv[1]) == -1)
    {
        perror("unlink");
        return 1;
    }
}
