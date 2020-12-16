#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/stat.h>
#include<fcntl.h>
#include <string.h>

int main(int argc,char* argv[]){
	char c;
	int in,out;
	if(argc<3){
		printf("Insufficient arguments\n");
		exit(0);
	}
	in=open(argv[1],O_RDONLY);
	
	char buffer[1000];
	if(in==-1){
		printf("Wrong file\n");
		exit(0);
	}
	read(in,buffer,1000);
	char *ret=strstr(buffer,argv[2]);
	if(ret==NULL){
		printf("String is not found\n");
		exit(0);
	}
	printf("%s\n",ret );
	exit(0);

}