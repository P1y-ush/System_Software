/*
===========================================================================================================================
Name : 5.c
Author : Piyush
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
===========================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h> //for exit()
#include<fcntl.h>  //for open()
#include<unistd.h> //for close(), sleep()

int main(void){
	const char *names[5] ={"file1.txt", "file2.txt", "file3.txt","file4.txt","file5.txt"};
	int fds[5];
	mode_t mode = 0644;

	printf("PID: %d\n",getpid());

	for(int i =0;i<5;i++){
		fds[i] = creat(names[i], mode);
		if(fds[i] == -1){
			perror("creat");
			exit(EXIT_FAILURE);
		}
		printf("Created %s with fd = %d\n", names[i], fds[i]);

	
	}
        //Infinite loop so we can inspect /proc/<pid>/fd
	while(1){
		sleep(10); // avoid busy CPU loop
	}
	return 0;
	
}



/*
=============================================================================================
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P5$ vim 5.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P5$ cc 5.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P5$ ./a.out
PID: 12444
Created file1.txt with fd = 3
Created file2.txt with fd = 4
Created file3.txt with fd = 5
Created file4.txt with fd = 6
Created file5.txt with fd = 7



piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~$ ls -l /proc/12444/fd
total 0
lrwx------ 1 piyush piyush 64 Aug 26 00:35 0 -> /dev/pts/0
lrwx------ 1 piyush piyush 64 Aug 26 00:35 1 -> /dev/pts/0
lrwx------ 1 piyush piyush 64 Aug 26 00:35 2 -> /dev/pts/0
l-wx------ 1 piyush piyush 64 Aug 26 00:35 3 -> /home/piyush/Desktop/SS/P5/file1.txt
l-wx------ 1 piyush piyush 64 Aug 26 00:35 4 -> /home/piyush/Desktop/SS/P5/file2.txt
l-wx------ 1 piyush piyush 64 Aug 26 00:35 5 -> /home/piyush/Desktop/SS/P5/file3.txt
l-wx------ 1 piyush piyush 64 Aug 26 00:35 6 -> /home/piyush/Desktop/SS/P5/file4.txt
l-wx------ 1 piyush piyush 64 Aug 26 00:35 7 -> /home/piyush/Desktop/SS/P5/file5.txt

==============================================================================================
*/
