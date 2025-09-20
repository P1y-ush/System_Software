
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

    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    lock.l_type = F_RDLCK;   // Read lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;          // Entire file

    printf("Trying to acquire read lock...\n");
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        exit(1);
    }
    printf("Read lock acquired. Press Enter to release...\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}

/*
=================================================================================
Output is in Implementation.txt file.
=================================================================================
*/
