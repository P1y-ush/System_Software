/*
===========================================================================================================================
Name : 8.c
Author : Piyush
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
===========================================================================================================================
*/
#include <stdio.h>   // for printf, fopen, fgets, fclose

int main() {
    FILE *fp;                
    char line[256];          

    // Open file in read-only mode
    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;   // exit with error
    }

    // Read file line by line until EOF
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);  
    }

   
    fclose(fp);

    return 0;
}


/*
====================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P8$ vim 8.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P8$ cc 8.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P8$ ./a.out
Hi! This is Piyush.
I am MTech First year student.
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P8$

====================================================================================
*/
