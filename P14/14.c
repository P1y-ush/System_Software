/*
===========================================================================================================================
Name : 14.c
Author : Piyush
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

    // Check if filename is given
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Get file info
    if (stat(argv[1], &fileStat) == -1) {
        perror("stat");
        exit(1);
    }

    // Check file type
    if (S_ISREG(fileStat.st_mode)) {
        printf("%s is a Regular File\n", argv[1]);
    } else if (S_ISDIR(fileStat.st_mode)) {
        printf("%s is a Directory\n", argv[1]);
    } else if (S_ISCHR(fileStat.st_mode)) {
        printf("%s is a Character Device\n", argv[1]);
    } else if (S_ISBLK(fileStat.st_mode)) {
        printf("%s is a Block Device\n", argv[1]);
    } else if (S_ISFIFO(fileStat.st_mode)) {
        printf("%s is a FIFO (named pipe)\n", argv[1]);
    } else if (S_ISLNK(fileStat.st_mode)) {
        printf("%s is a Symbolic Link\n", argv[1]);
    } else if (S_ISSOCK(fileStat.st_mode)) {
        printf("%s is a Socket\n", argv[1]);
    } else {
        printf("%s is of Unknown type\n", argv[1]);
    }

    return 0;
}

/*

=========================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P14$ vim 14.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P14$ cc 14.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P14$ ./a.out 14.c
14.c is a Regular File
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P14$ ./a.out /etc
/etc is a Directory
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P14$ ./a.out /dev/null
/dev/null is a Character Device
=========================================================================================
*/

