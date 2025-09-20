/*
======================================================================================
Name        : 20.c
Author      : Piyush
Description : Find out the priority of your running program. Modify the priority with nice command.
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int myid;
    int myprio;

    // get my process id
    myid = getpid();

    // get my priority
    myprio = getpriority(PRIO_PROCESS, myid);

    printf("My process id is: %d\n", myid);
    printf("My current priority is: %d\n", myprio);

    return 0;
}

/*
======================================================================================
Output:
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/MT2025087/P20$ cc 20.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/MT2025087/P20$ ./a.out
My process id is: 18452
My current priority is: 0
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/MT2025087/P20$ nice -n 19 ./a.out
My process id is: 18453
My current priority is: 19

======================================================================================
*/

