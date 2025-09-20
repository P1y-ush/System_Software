/*
======================================================================================
Name        : 18.c
Author      : Piyush
Description : Write a program to perform Record locking.
              a. Implement write lock
              b. Implement read lock
              Create three records in a file. Whenever you access a particular record,
              first lock it then modify/access to avoid race condition.
======================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd;
    struct flock mylock;
    char buff[50];
    int rec_size = 20; // size of each record (20 bytes)

    // open file
    fd = open("records.txt", O_RDWR);
    if (fd < 0)
    {
        perror("open");
        exit(1);
    }

    int rec_no;
    printf("Enter record number (0,1,2): ");
    scanf("%d", &rec_no);

    // prepare lock
    mylock.l_type = F_WRLCK;      // change this to F_RDLCK for read lock
    mylock.l_whence = SEEK_SET;
    mylock.l_start = rec_no * rec_size; // which record to lock
    mylock.l_len = rec_size;            // length of record

    // set lock
    fcntl(fd, F_SETLKW, &mylock);

    // move file pointer to that record
    lseek(fd, rec_no * rec_size, SEEK_SET);

    // read existing record
    read(fd, buff, rec_size);
    printf("Old Record: %s\n", buff);

    // write new data if write lock
    if (mylock.l_type == F_WRLCK)
    {
        printf("Enter new data: ");
        scanf("%s", buff);

        // move again
        lseek(fd, rec_no * rec_size, SEEK_SET);
        write(fd, buff, strlen(buff));
        printf("Record Updated!\n");
    }

    // unlock
    mylock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &mylock);

    close(fd);
    return 0;
}


/*
========================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P18$ vim 18.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P18$ echo -n "Record0  " >records.txt
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P18$ echo -n "Record1  " >records.txt
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P18$ echo -n "Record2  " >records.txt
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P18$ cc 18.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P18$ ./a.out
Enter record number (0,1,2): 2
Old Record: 
Enter new data: Hello
Record Updated!
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P18$ cat records.txt
Record2  Hello

========================================================================================================
*/
