/*
===========================================================================================================================
Name : 3.c
Author : Piyush
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
===========================================================================================================================
*/
#include<stdio.h> 
#include<fcntl.h> //for creat()
#include<stdlib.h> //for exit()
#include<unistd.h> //for close()

int main(){
	int fd;
	//Create a file named "myfile.txt" with read/write permissions
	fd = creat("myfile.txt",0644);

	if(fd==-1){
	perror("creat");
	exit(1);
	}
	printf("File created successfully.\n");
	printf("File descriptor value: %d\n",fd);

	close(fd); //close the file

	return 0;
}


/*
=============================================================================================
Output: 
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P3$ vim 3.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P3$ cc 3.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P3$ ./a.out
File created successfully.
File descriptor value: 3

=============================================================================================
*/

