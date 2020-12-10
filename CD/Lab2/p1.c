// That takes a file as input and replacesblank spacesand tabs by single space andwrites the output toa file.
#include <stdio.h>
#include<stdlib.h>
int main(){
	FILE *fa, *fb;
	int ca, cb;
	fa = fopen("input.c", "r");
	if (fa == NULL){
		printf("Cannot open file  \n");
		exit(0);
	}
	fb = fopen("outputp1.c", "w");
	ca = getc(fa);
	while (ca != EOF){
		if(ca==' '){
			putc(ca,fb);
			while(ca==' ')
				ca = getc(fa);
		}
		if(ca=='\n'){
			putc(ca,fb);
			while(ca=='\n')
				ca = getc(fa);
		}
		if(ca=='\t'){
			putc('*',fb);
			while(ca=='\t')
				ca = getc(fa);
		}
		
		if (ca=='/'){
			cb = getc(fa);
			if (cb == '/'){
				while(ca != '\n')
					ca = getc(fa);
			}else if (cb == '*'){
				do{
					while(ca != '*')
						ca = getc(fa);
					ca = getc(fa);
				} while (ca != '/');
			}else{
				putc(ca,fb);
				putc(cb,fb);
			}
		}
		else
		 putc(ca,fb);
		ca = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	return 0;
}