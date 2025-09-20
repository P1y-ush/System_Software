/*
======================================================================================
Name        : 29.c
Author      : Piyush
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
              SCHED_RR).
======================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int policy;
    struct sched_param param;

    // Get current scheduling policy
    policy = sched_getscheduler(0);  // 0 = current process
    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current policy: ");
    if (policy == SCHED_OTHER) printf("SCHED_OTHER\n");
    else if (policy == SCHED_FIFO) printf("SCHED_FIFO\n");
    else if (policy == SCHED_RR) printf("SCHED_RR\n");
    else printf("Unknown\n");

    // Set priority (for FIFO / RR, must be > 0)
    param.sched_priority = 10;

    // Change policy to SCHED_FIFO
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler (FIFO)");
        return 1;
    }
    printf("Policy changed to SCHED_FIFO with priority %d\n", param.sched_priority);

    sleep(2);

    // Change policy to SCHED_RR
    param.sched_priority = 20;
    if (sched_setscheduler(0, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler (RR)");
        return 1;
    }
    printf("Policy changed to SCHED_RR with priority %d\n", param.sched_priority);

    return 0;
}
/*

===========================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P29$ vim 29.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P29$ cc 29.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P29$ sudo ./a.out
[sudo] password for piyush: 
Current policy: SCHED_OTHER
Policy changed to SCHED_FIFO with priority 10
Policy changed to SCHED_RR with priority 20
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P29$ 

===========================================================================================
*/


