// That takes C program as input, recognizesall the keywords and printsthem in upper case.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void printupper(char buf[])
{
	for(int i=0;buf[i]!='\0';i++)
		printf("%c",toupper(buf[i]));
	printf("\n");		
}
int main()
{
	char keyWords[25][10]={"if","else","for","break","switch","do","while",
	"return","void","int","float","char","struct","define","include",
	 "\0"
	};
	char buf[10];
	int ca,cb,i;
	FILE *fa;
	fa=fopen("input.c","r");
	if(fa==NULL)
	{
	printf("Cannot open the file\n");
	exit(0);
	}
	ca = getc(fa);
	while(ca!=EOF)
	{
		i=0;
		buf[i]='\0';
		if(isalpha(ca))
		{
		 	while(isalpha(ca))
			{
				buf[i++]=ca;
				ca = getc(fa);
			}
			buf[i]='\0';
			for(int j=0;strcmp(keyWords[j],"\0")!=0;j++)
			{
				if(strcmp(buf,keyWords[j])==0)
					printupper(keyWords[j]);		
			}
		}
	else
	ca = getc(fa);
	}
	fclose(fa);
	return 0;
	}