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
    int ticket = 0;

    fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Write initial ticket number (0)
    if (write(fd, &ticket, sizeof(ticket)) == -1) {
        perror("write");
        close(fd);
        exit(1);
    }

    printf("Ticket file initialized with ticket number %d\n", ticket);

    close(fd);
    return 0;
}

/*
=================================================================================
Output is in Implementation.txt file.
=================================================================================
*/
