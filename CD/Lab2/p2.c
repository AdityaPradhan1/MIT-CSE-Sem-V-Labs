// Todiscard preprocessor directives from the given input ‘C’ file.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int isAlpha(char ca){
	if((ca >='a' && ca<='z') || (ca >= 'A' && ca<='Z') ){
		return 1;
	}
	return 0;

}
int main(){
	char empt[100];
	char str1[]="include";
	char str2[]="define";
	FILE *fa, *fb;
	int ca, cb;
	fa = fopen("input.c", "r");
	if (fa == NULL){
		printf("Cannot open file  \n");
		exit(0);
	}
	fb = fopen("outputp2.c", "w");
	ca = getc(fa);
	while (ca != EOF){
		if(ca==' '){
			putc(ca,fb);
			while(ca==' ')
				ca = getc(fa);
		}
		if(ca=='#'){
			char buf[100];
			buf[0]=ca;
			int k=0;
			ca = getc(fa);
			while(isAlpha(ca)){
				k++;
				buf[k]=ca;
				ca = getc(fa);
			}
			buf[k+1]='\0';
			printf("%s\n",buf );
			if((strcmp(str1,buf)==0 ) || 	(strcmp(str2,buf)==0)){
				for(int i=0;i<=k;i++){
					putc(buf[i],fb);
					printf("Hi\n");
				}
			}
			else{
				ca = getc(fa);
				while (ca != '\n') {
                ca = getc(fa);
           	 }
			}

		}

		if(ca=='\t'){
			putc(' ',fb);
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