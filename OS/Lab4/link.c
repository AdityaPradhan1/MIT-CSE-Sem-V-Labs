#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<dirent.h>
#include<string.h>

int int main(int argc, char* argv[])
{
	struct stat sb1,sb2,sb3;
	int ret1,ret2,ret3;
	ret1=stat(argv[1],&sb1);
	printf("No of hardlinks for %s is %d\n",argv[1],sb1.st_nlink);
	link(argv[1],argv[2]);
	ret2=stat(argv[1],&sb2);
	printf("No of hardlinks for %s is %d\n",argv[1],sb2.st_nlink);
	unlink(argv[1]);
	ret3=stat(argv[1],&sb32);
	printf("No of hardlinks for %s is %d\n",argv[1],sb3.st_nlink);
	
	return 0;
}