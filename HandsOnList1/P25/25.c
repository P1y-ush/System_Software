/*
====================================================================================================================
Name : 25.c
Author : Piyush
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
====================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t c1, c2, c3;
    int st,w;

    c1 = fork();
    if (c1 == 0) {
        printf("Child 1 running (PID: %d)\n", getpid());
        exit(1);
    }

    c2 = fork();
    if (c2 == 0) {
        printf("Child 2 running (PID: %d)\n", getpid());
        exit(2);
    }

    c3 = fork();
    if (c3 == 0) {
        printf("Child 3 running (PID: %d)\n", getpid());
        exit(3);
    }

    // Parent process
    printf("Parent (PID: %d) created children: %d, %d, %d\n", getpid(), c1, c2, c3);

    // Wait only for child 2
    w = waitpid(c2, &st, 0);
    
    if(WIFEXITED(st)){
    printf("Parent waited for Child 2 (PID: %d) exitstatus = %d\n", w, WEXITSTATUS(st));
   }
    

    return 0;
}

/*
===================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/MT2025087/P25$ vim 25.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/MT2025087/P25$ cc 25.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/MT2025087/P25$ ./a.out
Child 1 running (PID: 22947)
Child 2 running (PID: 22948)
Parent (PID: 22946) created children: 22947, 22948, 22949
Child 3 running (PID: 22949)
Parent waited for Child 2 (PID: 22948) exitstatus = 2


===================================================================================================================
*/

