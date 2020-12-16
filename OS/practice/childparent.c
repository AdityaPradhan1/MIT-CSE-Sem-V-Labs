#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<dirent.h>
#include<string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int status;
	pid_t pid;
	pid=fork();
	if(pid==-1){
		printf("child not created\n");
		exit(-1);
	}
	else if (pid==0)
	{
		execlp("./printdiralpha.o","printdiralpha.c",NULL);
		exit(0);
	}
	else{
		wait(NULL);
		printf("Parent process\n");
		printf("Child is returned\n");
		exit(0);
	}

	return 0;
}