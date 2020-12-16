#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	pid=fork();
	if(pid==0){
		sleep(10);
		printf("Child process\n" );
		system("ps");
		printf("PID:%d\n",getpid());
		printf("Parent PID:%d\n",getppid() );
		printf("Child PID:%d \n",pid);
		
		printf("\n");
		exit(0);
	}
	else{
		
		printf("Parent process\n" );
		system("ps");
		printf("PID:%d\n",getpid());
		printf("Parent PID:%d\n",getppid() );
		printf("Child PID:%d \n",pid);
		
		printf("\n");
		exit(0);
	}

	return 0;
}