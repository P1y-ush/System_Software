/*
===========================================================================================================================
Name : 9.c
Author : Piyush
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
===========================================================================================================================
*/
#include <stdio.h>
#include <sys/stat.h>   // for stat()
#include <unistd.h>
#include <stdlib.h>
#include <time.h>       // for ctime()

int main(int argc, char *argv[]) {
    struct stat fileStat;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    if (stat(argv[1], &fileStat) < 0) {
        perror("stat");
        exit(1);
    }

    printf("File: %s\n", argv[1]);
    printf("a. Inode number: %ld\n", (long) fileStat.st_ino);
    printf("b. Number of hard links: %ld\n", (long) fileStat.st_nlink);
    printf("c. UID: %d\n", fileStat.st_uid);
    printf("d. GID: %d\n", fileStat.st_gid);
    printf("e. Size: %ld bytes\n", (long) fileStat.st_size);
    printf("f. Block size: %ld bytes\n", (long) fileStat.st_blksize);
    printf("g. Number of blocks: %ld\n", (long) fileStat.st_blocks);
    printf("h. Time of last access: %s", ctime(&fileStat.st_atime));
    printf("i. Time of last modification: %s", ctime(&fileStat.st_mtime));
    printf("j. Time of last status change: %s", ctime(&fileStat.st_ctime));

    return 0;
}




/*
===============================================================================================
Output: 

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P9$ vim 9.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P9$ cc 9.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P9$ ./a.out test.txt
File: test.txt
a. Inode number: 10485991
b. Number of hard links: 1
c. UID: 1000
d. GID: 1000
e. Size: 0 bytes
f. Block size: 4096 bytes
g. Number of blocks: 0
h. Time of last access: Tue Aug 26 16:27:11 2025
i. Time of last modification: Tue Aug 26 16:27:11 2025
j. Time of last status change: Tue Aug 26 16:27:11 2025

===============================================================================================
*/
