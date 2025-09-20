/*
===========================================================================================================================
Name : 17
Author : Piyush
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    int ticket;
    struct flock lock;

    fd = open("test.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Set up write lock
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;   // Lock whole file
    lock.l_pid = getpid();

    printf("Process %d: Waiting for lock...\n", getpid());

    // Acquire lock (wait if necessary)
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        exit(1);
    }

    printf("Process %d: Lock acquired.\n", getpid());

    // Read current ticket
    lseek(fd, 0, SEEK_SET);
    if (read(fd, &ticket, sizeof(ticket)) == -1) {
        perror("read");
        close(fd);
        exit(1);
    }

    // Increment ticket number
    ticket++;
    printf("Process %d: Reserved ticket number %d\n", getpid(), ticket);

    // Write new ticket back to file
    lseek(fd, 0, SEEK_SET);
    if (write(fd, &ticket, sizeof(ticket)) == -1) {
        perror("write");
        close(fd);
        exit(1);
    }

    // Unlock
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl");
        close(fd);
        exit(1);
    }

    printf("Process %d: Lock released.\n", getpid());

    close(fd);
    return 0;
}

/*
=================================================================================
Output is in Implementation.txt file.
=================================================================================
*/
