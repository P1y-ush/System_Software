/*
===========================================================================================================================
Name : 2.c
Author : Piyush
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
===========================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
        printf("Running process with PID: %d\n", getpid());
        sleep(5);  // sleep for 5 seconds to reduce CPU usage
    }
    return 0;
}

/*
======================================================================================================================================================================================
#Starting the Process
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P2$ vim 2.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P2$ cc 2.c
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~/Desktop/SS/P2$ ./a.out
Running process with PID: 21637
Running process with PID: 21637
Running process with PID: 21637


# Detailed status (state, memory, signals, etc.):
piyush@piyush-Lenovo-ideapad-330S-15IKB-D:~$ cat /proc/21637/status
Name:	a.out
Umask:	0002
State:	S (sleeping)
Tgid:	21637
Ngid:	0
Pid:	21637
PPid:	12387
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 100 114 1000 
NStgid:	21637
NSpid:	21637
NSpgid:	21637
NSsid:	12387
Kthread:	0
VmPeak:	    2680 kB
VmSize:	    2680 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	    1500 kB
VmRSS:	    1500 kB
RssAnon:	       0 kB
RssFile:	    1500 kB
RssShmem:	       0 kB
VmData:	     224 kB
VmStk:	     132 kB
VmExe:	       4 kB
VmLib:	    1748 kB
VmPTE:	      48 kB
VmSwap:	       0 kB
HugetlbPages:	       0 kB
CoreDumping:	0
THP_enabled:	1
untag_mask:	0xffffffffffffffff
Threads:	1
SigQ:	0/30856
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000000000
SigCgt:	0000000000000000
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	thread vulnerable
SpeculationIndirectBranch:	conditional enabled
Cpus_allowed:	ff
Cpus_allowed_list:	0-7
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	9
nonvoluntary_ctxt_switches:	1
x86_Thread_features:	
x86_Thread_features_locked:
======================================================================================================================================================================================
*/
