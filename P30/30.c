/*
===========================================================================================
Name        : 30.c
Author      : Piyush
Description : Write a program to run a script at a specific time using a Daemon process.
===========================================================================================
*/
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    if(!fork()) {
        setsid();
        chdir("/");
        umask(0);

        while(1) {
            time_t t;
            struct tm *ti;
            t = time(NULL);
            ti = localtime(&t);

            if(ti->tm_hour == 16 && ti->tm_min == 16) {
                system("/home/piyush/Desktop/SS/P30/myscript.sh");
                sleep(60);
            }
            sleep(1);
        }
    }
    else    
        exit(0);
    return 0;
}


/*
===============================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P30$ nano myscript.sh
//Making file executable
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P30$ chmod +x myscript.sh
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P30$ ./myscript.sh
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P30$ vim 30.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P30$ cc 30.c -o daemon
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P30$ ./daemon &
[4] 20034

//Checking Output file
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P30$ cat output.txt
Script ran at Sun Sep  7 04:02:52 PM IST 2025
Script ran at Sun Sep  7 04:15:10 PM IST 2025
Script ran at Sun Sep  7 04:16:00 PM IST 2025
[4]   Done                    ./daemon

================================================================================================================

*/
