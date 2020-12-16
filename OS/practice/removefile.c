#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

void printDir(char *dir){
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if((dp=opendir(dir))==NULL){
		fprintf(stderr, "Cant open directory%s\n",dir );
		return;
	}
	chdir(dir);
	while((entry=readdir(dp))!=NULL){
		lstat(entry->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode)){
			if(strcmp(".",entry->d_name)==0 || strcmp("..",entry->d_name)==0)
				continue;
			printf("Directory name%s\n",entry->d_name);
			printDir(entry->d_name);
		}
		else{
			printf("File name i s %s\n",entry->d_name );
			printf("Do you want to remove this file:y/N\n" );
			char r;
			scanf("%c",&r);
			if(r=='y'|| r=='Y')
				remove(entry->d_name);
		}
	}
	chdir("..");
	closedir(dp);
}
int main(int argc,char *argv[]){
	printDir(argv[1]);

}