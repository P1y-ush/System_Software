/*
======================================================================================
Name        : 26.c
Author      : Piyush
Description : Write a program to execute an executable program.
              a. use some executable program
              b. pass some input to an executable program.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *prog = "./test";   
    char *name = "Piyush";  

    execl(prog, prog, name, NULL);

    printf("this will not print if execl is successful\n");

    return 0;
}
/*
============================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P26$ vim 26.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P26$ cc 26.c -o main
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P26$ cc test.c -o test
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P26$ ./main
Hi! Piyush

============================================================================================
*/
