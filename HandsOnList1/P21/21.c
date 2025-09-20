/*
======================================================================================================================================================
Name : 21.c
Author : Piyush
Description : Write a program, call fork and print the parent and child process id.
======================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else {
        // Parent process
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}


/*
---------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------
Output : 

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P21$ vim 21.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P21$ cc 21.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P21$ ./a.out
Parent Process: PID = 4900, Child PID = 4901
Child Process: PID = 4901, Parent PID = 4900

---------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------
*/
