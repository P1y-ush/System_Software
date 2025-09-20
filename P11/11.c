/*
===========================================================================================================================
Name : 11.c
Author : Piyush
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
===========================================================================================================================
*/
#include<stdio.h>
#include<unistd.h> //for dup, dup2, write, close
#include<fcntl.h>  // for open, fcntl
#include<stdlib.h> // for exit

int main(){
	int fd, fd_dup1, fd_dup2, fd_dup3;

	//1. open a file
	fd = open("test.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

	if(fd == -1){
		perror("open");
		exit(1);
	}
	printf("Original fd = %d\n", fd);

	//2. duplicate using dup
	fd_dup1 = dup(fd);
	if(fd_dup1 == -1){
		perror("dup");
		exit(1);
	}
	printf("Dup fd = %d\n", fd_dup1);

	//3. duplicate using dup2
	fd_dup2 = dup2(fd,20);
	if(fd_dup2==-1){
		perror("dup2");
		exit(1);
	}
	printf("dup2 fd = %d\n", fd_dup2);

	//4. duplicate using fcntl
	fd_dup3 = fcntl(fd, F_DUPFD, 100); //new fd >= 100
	if(fd_dup3==-1){
		perror("fcntl");
		exit(1);
	}
	printf("fcntl fd = %d\n", fd_dup3);

	//5. write to file using all fds
	write(fd, "Hello, I am fd\n",15 );
	write(fd_dup1, "Hello, I am dup\n",16);
	write(fd_dup2,"Hello, I am dup2\n",17);
	write(fd_dup3,"Hello, I am fcntl\n", 18);

	//6. close everything
	close(fd);
	close(fd_dup1);
	close(fd_dup2);
	close(fd_dup3);

	printf("Done with the tasks, check file test.txt\n");
	return 0;
}


/*
==========================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P11$ vim 11.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P11$ cc 11.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P11$ ./a.out
Original fd = 3
Dup fd = 4
dup2 fd = 20
fcntl fd = 100
Done with the tasks, check file test.txt

# Checking updated file
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P11$ cat test.txt
Hello, I am fd
Hello, I am dup
Hello, I am dup2
Hello, I am fcntl
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P11$ 

==========================================================================================================
*/
