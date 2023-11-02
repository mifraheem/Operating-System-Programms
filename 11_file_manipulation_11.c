#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int ag, char *arg[])
{
    char buf[100];
    struct stat s;
    int fd1, fd2, n;
    fd1 = open(arg[1], O_RDONLY);
    fd2 = open(arg[2], O_CREAT | O_WRONLY, 0777);
    stat(arg[2], &s);
    if (fd2 == -1)
    {
        printf("ERROR IN CREATION");
        return 1; // Add return statement to exit the program
    }
    while ((n = read(fd1, buf, sizeof(buf))) > 0)
    {
        if (write(fd2, buf, n) != n)
        {
            close(fd1);
            close(fd2);
            return 1; // Add return statement to exit the program
        }
    }
    printf("\t\n UID FOR FILE.......>%d \n FILE ACCESS TIME.....>%s \n FILE MODIFIED TIME........>%s \n FILE I-NODE NUMBER......>%lu \n PERMISSION FOR FILE .... >%o\n\n", s.st_uid, ctime(&s.st_atime), ctime(&s.st_mtime), s.st_ino, s.st_mode);


    close(fd1);
    close(fd2);

    return 0; // Add return statement to indicate successful execution
}
