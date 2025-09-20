/*
====================================================================================================================
Name : 24.c
Author : Piyush
Description : Write a program to create an orphan process.
====================================================================================================================
*/
#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid > 0) {
        // Parent process terminates immediately
        exit(0);
    } else if(pid==0){
        // Child process
        sleep(20);
        printf("I am child process, my PID is %d, my parent PID is %d\n", getpid(), getppid());
    }

    return 0;
}


/*
=========================================================================================================================
Output:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/MT2025087/P24$ vim 24.c 
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/MT2025087/P24$ cc 24.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/MT2025087/P24$ ./a.out
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/MT2025087/P24$ I am child process, my PID is 20800, my parent PID is 2257


=========================================================================================================================
*/

