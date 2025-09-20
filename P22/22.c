/*
====================================================================================================================
Name : 22.c
Author : Piyush
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
====================================================================================================================
*/


#include <stdio.h>    // printf
#include <unistd.h>   // fork, write, close
#include <fcntl.h>    // open

int main() {
    int fd;
    int pid;

    // open file (create if not exists, write only, append mode)
    fd = open("test.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);

    pid = fork();   // create child

    if (pid == 0) {
        // child process
        write(fd, "Hello I am child process\n", 25);
    } else {
        // parent process
        write(fd, "Hello I am parent process\n", 26);
    }

    close(fd);
    return 0;
}


/*
================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P22$ vim 22.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P22$ cc 22.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P22$ ./a.out
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P22$ cat test.txt
Hello I am parent process
Hello I am child process

================================================================================
*/
