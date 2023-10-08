#include<stdio.h> 
#include<stdlib.h>  // for exit()
#include<unistd.h>  // Unix Standard => fork(), execlp(), getpid(),
#include<sys/wait.h> // wait.
void main()

{
	int pid;
	pid=fork(); // fork() => duplicate the current process, createing a parent-child relationship
	
	// fork will return:
	// -ve value: if creating new process is failled.
	// 0 : newly created child process.
	// +ve value: return value to caller or parent. value contains process id of newsly created child process.

	if(pid<0) {  // check if fork (creating new process) faills ( on faill it will return a -ve value)

		printf("fork failed!");
		exit(1);
	}

	else if(pid==0)  // newly created child process. if pid is 0 i means that child process is running.
	{
		// execlp("date","ls",NULL); // whoami will print the current username. ls(will not do anything) if whoami replace with ls it will print names of all files in directory
		execlp("whoami","ls",NULL); // whoami will print the current username. ls(will not do anything) if whoami replace with ls it will print names of all files in directory
        // execlp command is used to run another command inside program. full form -> execute list with path
		exit(0);
	}

	else

	{

		printf("\n Process id is: %d\n",getpid());
        //getpid() is used to get current process id.
		wait(NULL); // wait to kill child process
		exit(0);

	}

}