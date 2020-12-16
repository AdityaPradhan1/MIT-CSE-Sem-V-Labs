#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<dirent.h>
#include<string.h>
char* formatTime(char* str, time_t val){
	strftime(str,36,"%d.%m.%Y %H:%M:%S",localtime(&val));
	return str;
}
int main(int argc, char* argv[]){
	if(argc<2){
		printf("Less arguments\n");
		exit(0);
	}
	struct stat sb;
	int ret=stat(argv[1],&sb);
	if(ret){
		perror("stat");
		exit(0);
	}
	char date[36];
	printf("Inode number for %s is%ld\n",argv[1],sb.st_ino );
	printf("Acces time is %s",formatTime(date,sb.st_atime));

}