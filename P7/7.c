/*
===========================================================================================================================
Name : 7.c
Author : Piyush
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
===========================================================================================================================
*/
#include <stdio.h>
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()
#include <stdlib.h>    // for exit()

#define SIZE 1024

int main(int argc, char *argv[]) {
    int fd1, fd2;
    char buffer[SIZE];
    ssize_t n;

    if (argc != 3) {
        write(2, "Usage: ./a.out <source> <destination>\n", 38);
        exit(1);
    }

    // Open source file (read-only)
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        perror("open source");
        exit(1);
    }

    // Open destination file (write-only, create if not exists, truncate if exists)
    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 == -1) {
        perror("open destination");
        close(fd1);
        exit(1);
    }

    // Copy loop
    while ((n = read(fd1, buffer, SIZE)) > 0) {
        if (write(fd2, buffer, n) != n) {
            perror("write");
            close(fd1);
            close(fd2);
            exit(1);
        }
    }

    if (n < 0) {
        perror("read");
    }

    close(fd1);
    close(fd2);

    return 0;
}

/*
================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P7$ vim 7.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P7$ echo "Hello, Piyush!" > src.txt
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P7$ cc 7.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P7$ ./a.out src.txt dst.txt

# Checking destination file.
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P7$ cat dst.txt
Hello, Piyush!
================================================================================================
*/



