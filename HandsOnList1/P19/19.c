/*
======================================================================================
Name        : 19.c
Author      : Piyush
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
======================================================================================
*/
#include <stdio.h>
#include <unistd.h>   // for getpid()
#include <stdint.h>   // for uint64_t

//  Function to read CPU cycle counter
unsigned long long read_tsc() {
    unsigned int low, high;
    // rdtsc puts result in EDX:EAX (high:low)
    __asm__ __volatile__("rdtsc" : "=a"(low), "=d"(high));
    return ((unsigned long long)high << 32) | low;
}

int main() {
    unsigned long long start, end;
    int pid;

    // take timestamp before system call
    start = read_tsc();

    // system call
    pid = getpid();

    // take timestamp after system call
    end = read_tsc();

    printf("Process ID: %d\n", pid);
    printf("Time taken by getpid() = %llu CPU cycles\n", end - start);

    return 0;
}

/*
=================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P19$ vim 19.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P19$ cc 19.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P19$ ./a.out
Process ID: 14300
Time taken by getpid() = 24026 CPU cycles

=================================================================================
*/

