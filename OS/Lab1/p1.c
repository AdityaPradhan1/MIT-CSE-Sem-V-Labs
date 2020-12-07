#include<stdio.h>
#include <unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
	
	char c;
	int in,out;
	char buffer[128];
	char str1[128],str2[128],temp[128];
	int l;
	char *ret;
	int nread;
	in=open(argv[1],O_RDWR);	
	nread=read(in,buffer,128);
	// printf("File Contents=%s and Number of characters are=%d",buffer, nread);
	l=strlen(buffer);

	ret = strstr(buffer,argv[2]);
	if(ret==NULL){
		printf("String is not found\n");
		exit(0);
	}
	printf("%s\n",ret );

	exit(0);

}