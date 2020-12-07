#include<stdio.h>
#include <unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
	
	char c;
	int in,out;
	char buffer[128];
	int nread;
	in=open("abc.txt",O_RDWR);	
	nread=read(in,buffer,128);
	printf("File Contents=%s and Number of characters are=%d",buffer, nread);
	exit(0);

}