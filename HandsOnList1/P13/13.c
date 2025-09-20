/*
===========================================================================================================================
Name : 13.c
Author : Piyush
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
===========================================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/select.h>

int main(){
	fd_set fds;
	struct timeval tv;
	int res;

	//Watch stdin (fd 0) to see when it has input
	FD_ZERO(&fds);
	FD_SET(0,&fds);

	//Set timeout = 10s
	tv.tv_sec = 10;
	tv.tv_usec = 0;

	printf("Type within 10s: \n");

	//Wait for input on stdin
	res = select(1,&fds, NULL, NULL, &tv);

	if(res == -1){
		printf("Error using select()\n");
	}else if(res == 0){
		printf("No input within 10s\n");
	}else{
		char buf[100];
		int n = read(0,buf, sizeof(buf)-1); // Read input
		buf[n] = '\0';
		printf("You typed: %s\n", buf);
	
	}

	return 0;
	

}
/*
=======================================================================================================

Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P13$ vim 13.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P13$ cc 13.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P13$ ./a.out
Type within 10s: 
HI!
You typed: HI!

=======================================================================================================
*/
