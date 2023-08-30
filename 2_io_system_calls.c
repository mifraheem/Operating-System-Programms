#include <stdio.h>
#include <unistd.h>  // Unix standard. used in program to use unix c methods.
#include <string.h>
#include <fcntl.h>  // linux file handling.
int main( )
{
    int fd[2];
    char buf1[50] = "Write this in first opened file.\n";
    char buf2[50];
    fd[0] = open("file1.txt", O_RDWR); // O_RDWR is file flag that indicate that : open file in both read and write method.
    fd[1] = open("file2.txt", O_RDWR);
    write(fd[0], buf1, strlen(buf1)); //  this will write the string from buf1 array to file1.txt
    printf("\n Enter the text now: "); 
    scanf("%s", buf1); // must enter a signle string not in two words. 
    printf("\n Cat file1 is	\n hai");
    write(fd[0], buf1, strlen(buf1));  // now it will write the userinput in file1
    lseek(fd[0], SEEK_SET, 0);        // Isseek => it will move the pointer in the begining of file after writing.(so that it can read data from beginning)
    read(fd[0], buf2, sizeof(buf1)); // it will read file1 and the content of file1 will be stored in bug2 variable.
    write(fd[1], buf2, sizeof(buf2)); // now the buf2 will write the stored data in file2.
    close(fd[0]);
    close(fd[1]);

    printf("\n");
    return 0;
}
