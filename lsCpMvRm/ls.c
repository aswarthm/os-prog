#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main()
{
    DIR *d;
    struct dirent *de;
    struct stat buf;
    char P[10] = "rwxrwxrwx", AP[10] = " ";
    d = opendir(".");
    while ((de = readdir(d)) != NULL)
    {
        stat(de->d_name, &buf);

        // // File type
        // if (S_ISREG(buf.st_mode))
        //     printf("-");
        // else if (S_ISDIR(buf.st_mode))
        //     printf("d ");
        // else if (S_ISCHR(buf.st_mode))
        //     printf("c ");
        // else if (S_ISBLK(buf.st_mode))
        //     printf("b ");
        // else if (S_ISFIFO(buf.st_mode))
        //     printf("p ");
        // else if (S_ISLNK(buf.st_mode))
        //     printf("l ");
        // else if (S_ISSOCK(buf.st_mode))
        //     printf("s ");
        // else
        //     printf(" ");
        // File Permissions P-full Permissions AP-Actual Permissions
        int a = buf.st_mode;
        for(int i=0;i<9;i++)
        {
            if(a%2==0)
                AP[8-i]='-';
            else
                AP[8-i]=P[8-i];
            a=a/2;
        }
        printf("%s ", AP);

        // Hard Links
        printf("%d ", buf.st_nlink);

        // User Name
        printf("%s ", getpwuid(buf.st_uid)->pw_name);

        // Group Name
        printf("%s ", getgrgid(buf.st_gid)->gr_name);

        // File Size
        printf("%d ", buf.st_size);

        // File Name
        printf("%s ", de->d_name);

        // Last Modified Time
        printf("%s", ctime(&buf.st_mtime));
    }
}