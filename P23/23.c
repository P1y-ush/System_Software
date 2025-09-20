/*
====================================================================================================================
Name : 23.c
Author : Piyush
Description : Write a program to create a Zombie state of the running program.
====================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>   // fork, sleep

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) exiting...\n", getpid());
        _exit(0);  // child finishes immediately
    } else {
        // Parent process
        printf("Parent process (PID: %d), child PID = %d\n", getpid(), pid);
        printf("Parent is sleeping... child becomes zombie\n");
        sleep(30);  // keep parent alive, child becomes zombie
    }

    return 0;
}

/*
========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P23$ vim 23.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P23$ cc 23.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P23$ ./a.out
Parent process (PID: 15695), child PID = 15696
Parent is sleeping... child becomes zombie
Child process (PID: 15696) exiting...

#Checking child process status
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P23$ ps aux | grep Z
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
piyush     15696  0.0  0.0      0     0 pts/0    Z+   14:55   0:00 [a.out] <defunct>
piyush     15701  0.0  0.0   9144  2232 pts/1    S+   14:55   0:00 grep --color=auto Z

========================================================================================================================
*/

