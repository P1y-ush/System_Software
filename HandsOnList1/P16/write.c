/*
===========================================================================================================================
Name : 16
Author : Piyush
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    struct flock lock;
    int fd;

    fd = open("test.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    lock.l_type = F_WRLCK;   // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;          // Lock the whole file

    printf("Trying to acquire write lock...\n");
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        exit(1);
    }
    printf("Write lock acquired. Press Enter to release...\n");
    getchar();

    lock.l_type = F_UNLCK;   // Unlock
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}

/*
=================================================================================
Output is in Implementation.txt file.
=================================================================================
*/
