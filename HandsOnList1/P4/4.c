/*
===========================================================================================================================
Name : 4.c
Author : Piyush
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
===========================================================================================================================
*/
#include <stdio.h>
#include <fcntl.h>   // for open()
#include <unistd.h>  // for close()
#include <stdlib.h>  // for exit()

int main() {
    int fd;

    // Open file "myfile.txt" in read/write mode
    fd = open("myfile.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    printf("File opened successfully. File descriptor: %d\n", fd);
    close(fd);

    // Try opening with O_CREAT | O_EXCL
    fd = open("myfile.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        perror("open with O_EXCL");
    } else {
        printf("File created (unexpected, since it already exists). FD: %d\n", fd);
        close(fd);
    }

    return 0;
}

/*
======================================================================================
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P4$ touch myfile.txt
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P4$ vim 4.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P4$ cc 4.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P4$ ./a.out
File opened successfully. File descriptor: 3
open with O_EXCL: File exists
======================================================================================
*/

