/*
======================================================================================
Name        : 28.c
Author      : Piyush
Description : Write a program to get maximum and minimum real time priority.
======================================================================================
*/
#include<sys/types.h>
#include<sched.h>
#include<stdio.h>
#include<unistd.h>

int main(){

	printf("The max real time priority(FIFO) = %d\n", sched_get_priority_max(SCHED_FIFO));
	printf("The min real time priority(FIFO) = %d\n", sched_get_priority_min(SCHED_FIFO));
	printf("The max real time priority(RR) = %d\n", sched_get_priority_max(SCHED_RR));
	printf("The min real time priority(RR) = %d\n", sched_get_priority_max(SCHED_RR));
	printf("The max real time priority = %d\n", sched_get_priority_max(SCHED_OTHER));
	printf("The min real time priority(FIFO) = %d\n", sched_get_priority_max(SCHED_OTHER));

}

/*
===================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P28$ vim 28.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P28$ cc 28.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P28$ ./a.out
The max real time priority(FIFO) = 99
The min real time priority(FIFO) = 1
The max real time priority(RR) = 99
The min real time priority(RR) = 99
The max real time priority = 0
The min real time priority(FIFO) = 0
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P28$ 

=====================================================================================
*/
