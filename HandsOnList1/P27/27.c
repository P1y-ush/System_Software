/*
===========================================================================================================================
Name : 27.c
Author : Piyush
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    char *args[] = {"ls", "-Rl", NULL};
    char *envp[] = {NULL};  // custom environment for execle

    // a) execl
    pid = fork();
    if (pid == 0) {
        printf("\nUsing execl:\n");
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl failed");
        exit(1);
    } else {
        wait(NULL);
    }

    // b) execlp
    pid = fork();
    if (pid == 0) {
        printf("\nUsing execlp:\n");
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp failed");
        exit(1);
    } else {
        wait(NULL);
    }

    // c) execle
    pid = fork();
    if (pid == 0) {
        printf("\nUsing execle:\n");
        execle("/bin/ls", "ls", "-Rl", NULL, envp);
        perror("execle failed");
        exit(1);
    } else {
        wait(NULL);
    }

    // d) execv
    pid = fork();
    if (pid == 0) {
        printf("\nUsing execv:\n");
        execv("/bin/ls", args);
        perror("execv failed");
        exit(1);
    } else {
        wait(NULL);
    }

    // e) execvp
    pid = fork();
    if (pid == 0) {
        printf("\nUsing execvp:\n");
        execvp("ls", args);
        perror("execvp failed");
        exit(1);
    } else {
        wait(NULL);
    }

    return 0;
}

/*
============================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P27$ vim 27.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P27$ cc 27.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P27$ ./a.out

Using execl:
.:
total 20
-rw-rw-r-- 1 piyush piyush  1331 Sep  7 19:19 27.c
-rwxrwxr-x 1 piyush piyush 16384 Sep  7 19:19 a.out

Using execlp:
.:
total 20
-rw-rw-r-- 1 piyush piyush  1331 Sep  7 19:19 27.c
-rwxrwxr-x 1 piyush piyush 16384 Sep  7 19:19 a.out

Using execle:
.:
total 20
-rw-rw-r-- 1 piyush piyush  1331 Sep  7 19:19 27.c
-rwxrwxr-x 1 piyush piyush 16384 Sep  7 19:19 a.out

Using execv:
.:
total 20
-rw-rw-r-- 1 piyush piyush  1331 Sep  7 19:19 27.c
-rwxrwxr-x 1 piyush piyush 16384 Sep  7 19:19 a.out

Using execvp:
.:
total 20
-rw-rw-r-- 1 piyush piyush  1331 Sep  7 19:19 27.c
-rwxrwxr-x 1 piyush piyush 16384 Sep  7 19:19 a.out

=============================================================================================
*/

