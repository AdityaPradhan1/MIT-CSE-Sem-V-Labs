#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
// extern int errno;
int main(){
	int a=25;
	float b=3.1;
	char c='z';
	char str[]="Hello World";
printf("a=%d b=%f c=%c str=%s hexadecimal for a=%x \n",a,b,c,str,a);
	errno=EPERM;
	printf("Error Access Errno= %m\n");
	
}