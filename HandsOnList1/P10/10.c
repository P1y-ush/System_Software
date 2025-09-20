/*
===========================================================================================================================
Name : 10.c
Author : Piyush
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
===========================================================================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int fd;
	off_t offset;
	char buf1[10] = "ABCDEFGHIJ";
	char buf2[10] = "1234567890";

	fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

	if(fd==-1){
		perror("open");
		exit(1);
	}

	if(write(fd, buf1, 10) != 10){
		perror("write buf1");
		close(fd);
		exit(1);
	}

	offset = lseek(fd,10, SEEK_CUR);
	if(offset == -1){
		perror("lseek");
		close(fd);
		exit(1);
	}

	printf("lseek return value (new offset) : %ld\n", (long)offset);

	if(write(fd,buf2,10) != 10){
		perror("write buf2");
		close(fd);
		exit(1);
	}

	close(fd);
	return 0;
}

/*
=========================================================================================================================
Output:

piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P10$ cc 10.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P10$ ./a.out
lseek return value (new offset) : 20


piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P10$ ls -l test.txt
-rw-r--r-- 1 piyush piyush 30 Sep  7 10:21 test.txt

# Check file contents with od
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P10$ od -c test.txt
0000000   A   B   C   D   E   F   G   H   I   J  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   1   2   3   4   5   6   7   8   9   0
0000036
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P10$ 



=========================================================================================================================
*/
