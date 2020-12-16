#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/stat.h>
#include<fcntl.h>

int main(){
	char c;
	int in,out;
	in=open("abc.txt",O_RDONLY);
	out=open("xyz.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	while(read(in,&c,1)!=0){
		write(out,&c,1);
	}
	exit(0);

}