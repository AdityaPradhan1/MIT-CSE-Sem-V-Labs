#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/stat.h>
#include<fcntl.h>
#include <string.h>

int main(int argc,char* argv[]){
	char c;
	int in,out;
	if(argc<2){
		printf("Insufficient arguments\n");
		exit(0);
	}
	in=open(argv[1],O_RDONLY);
	
	char buffer[1000];
	if(in==-1){
		printf("Wrong file\n");
		exit(0);
	}
	int l=1;
	while(read(in,&c,1)!=0){
		if(c=='\n'){
			l++;
		}
		write(0,&c,1);
		if(l==20){
			fgetc(stdin);
			l=0;

		}

	}
	
	
	exit(0);
}