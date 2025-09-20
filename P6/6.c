/*
===========================================================================================================================
Name : 6.c
Author : Piyush
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
===========================================================================================================================
*/

#include <unistd.h>   // for read(), write()
#include <stdlib.h>   // for exit()

int main() {
    char buffer[100];
    int n;

    // Read from STDIN (fd = 0)
    n = read(0, buffer, sizeof(buffer));
    if (n < 0) {
        write(2, "Error reading input\n", 20); // write to STDERR (fd = 2)
        exit(1);
    }

    // Write to STDOUT (fd = 1)
    write(1, buffer, n);

    return 0;
}

/*
============================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P6$ vim 6.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P6$ cc 6.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P6$ ./a.out
Hi! My name is Piyush.
Hi! My name is Piyush.
============================================================================
*/
