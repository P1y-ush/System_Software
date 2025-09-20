/*
===========================================================================================================================
Name : 12.c
Author : Piyush
Description : Write a program to find out the opening mode of a file. Use fcntl.
===========================================================================================================================
*/

#include<stdio.h>
#include<fcntl.h>  // open, fcntl
#include<unistd.h> // close
#include<stdlib.h> // exit

int main(){
	int fd, flags;
	
	// 1. open a file in read/write and append mode
	fd = open("test.txt", O_RDWR | O_APPEND);

	if(fd==-1){
		perror("open");
		exit(1);
	}

	// 2. get file status flags using fcntl
	flags = fcntl(fd, F_GETFL);
	if(flags==-1){
		perror("fcntl");
		close(fd);
		exit(1);
	}

	// 3. Extract access mode(O_RDONLY, O_WRONLY, O_RDWR)
	int acmode = flags & O_ACCMODE;
	
	printf("File opened with: ");
	if(acmode == O_RDONLY)
		printf("Read only\n");
	else if(acmode == O_WRONLY)
		printf("Write only\n");
	else if(acmode == O_RDWR)
		printf("Read and Write\n");

	// 4. Check for extra flags
	if(flags & O_APPEND)
		printf("Append flag is set\n");
	if(flags & O_NONBLOCK)
		printf("Non-Blocking flag is set\n");
	if(flags & O_SYNC)
		printf("Sync flag is set\n");

	close(fd);
	return 0;

}

/*
=====================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P12$ cc 12.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P12$ ./a.out
File opened with: Read and Write
Append flag is set

=====================================================================================
*/
