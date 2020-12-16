#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lex.c"
void program();
void declarations();
void datatype();
void idlist();
void idlistprime();
void assignstat();
void statementlist();
void statement();
void expn();
void eprime();
void simpleexp();
void seprime();
void term();
void tprime();
void factor();
void relop();
void addop();
void mulop();
struct token curr;
FILE *f1;
char *rel[]={"==","!=","<=",">=",">","<"};
char *add[]={"+","-"};
char *mul[]={"*","/","%"};
int isrel(char *w)
{
	int i;
	for(i=0;i<sizeof(rel)/sizeof(char*);i++)
	{
		if(strcmp(w,rel[i])==0)
		{
			return 1;
		}
	}
	return 0;
}
int isadd(char *w)
{
	int i;
	for(i=0;i<sizeof(add)/sizeof(char*);i++)
	{
		if(strcmp(w,add[i])==0)
		{
			return 1;
		}
	}
	return 0;
}
int ismul(char *w)
{
	int i;
	for(i=0;i<sizeof(mul)/sizeof(char*);i++)
	{
		if(strcmp(w,mul[i])==0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	FILE *fa, *fb;
    int ca, cb;
    fa = fopen("inp.c", "r");
    if (fa == NULL){
        printf("Cannot open file \n");
        exit(0);
    }

    fb = fopen("fileout.c", "w+");
    ca = getc(fa);
	while (ca != EOF){
		if(ca==' ')
		{
			putc(ca,fb);
			while(ca==' ')
				ca = getc(fa);
		}
		if (ca=='/')
		{
			cb = getc(fa);
			if (cb == '/')
			{
				while(ca != '\n')
					ca = getc(fa);
			}
			else if (cb == '*')
			{
				do
				{
					while(ca != '*')
						ca = getc(fa);
					ca = getc(fa);
				} while (ca != '/');
			}
			else{
				putc(ca,fb);
				putc(cb,fb);
			}
		}
		else putc(ca,fb);
		ca = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	fa = fopen("fileout.c", "r");
	if(fa == NULL){
		printf("Cannot open file");
		return 0;
	}
	fb = fopen("temp.c", "w+");
	ca = getc(fa);
	while (ca != EOF)
    {
        if(ca=='"')
        {
            putc(ca,fb);
            ca=getc(fa);
            while(ca!='"')
            {
                putc(ca,fb);
                ca=getc(fa);
            }
        }
        else if(ca=='#')
        {

            while(ca!='\n')
            {

                ca=getc(fa);

            }
            ca=getc(fa);
        }
    putc(ca,fb);
    ca = getc(fa);
    }
	fclose(fa);
	fclose(fb);
	
	fa = fopen("temp.c", "r");
	fb = fopen("fileout.c", "w");
	ca = getc(fa);
	while(ca != EOF){
		putc(ca, fb);
		ca = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	remove("temp.c");
	f1=fopen("fileout.c","r");
	if(f1==NULL)
	{
	  	printf("Error! File cannot be opened!\n");
	  	return 0;
	}
	
	while((curr=getNextToken(f1)).row!=-1)
	{
		if(strcmp(curr.lexeme,"main")==0)
		{
			program();
			break;
		}
	}
    fclose(f1);
}
void program()
{

	if(strcmp(curr.lexeme,"main")==0)
	{
		curr=getNextToken(f1);
		if(strcmp(curr.lexeme,"(")==0)
		{
			curr=getNextToken(f1);
			if(strcmp(curr.lexeme,")")==0)
			{
				curr=getNextToken(f1);
				if(strcmp(curr.lexeme,"{")==0)
				{
					curr=getNextToken(f1);
					declarations();
					statementlist();
					if(strcmp(curr.lexeme,"}")==0)
					{
						printf("\ncompiled\n\n");
						return;
					}
					else
					{
						printf("} missing at row=%d col=%d",curr.row,curr.col);
						exit(1);
					}
				}
				else
				{	
					printf("{ missing at row=%d col=%d",curr.row,curr.col);
					exit(1);
				}
			}
			else
			{
				printf(") missing at row=%d col=%d",curr.row,curr.col);
				exit(1);
			}
		}
		else
		{
			printf("( missing at row=%d col=%d",curr.row,curr.col);
			exit(1);
		}
	}
}
void declarations()
{
	if(isdtype(curr.lexeme)==0)
	{
		return;
	}
	datatype();
	idlist();
	if(strcmp(curr.lexeme,";")==0)
	{
		curr=getNextToken(f1);
		declarations();
	}
	else
	{
		printf("; missing at row=%d col=%d",curr.row,curr.col);
		exit(1);
	}
}
void datatype()
{
	if(strcmp(curr.lexeme,"int")==0)
	{
		curr=getNextToken(f1);
		return;
	}
	else if(strcmp(curr.lexeme,"char")==0)
	{
		curr=getNextToken(f1);
		return;
	}
	else
	{
		printf("%s missing datatype at row=%d col=%d",curr.lexeme, curr.row,curr.col);
		exit(1);
	}
}
void idlist()
{
	if(strcmp(curr.type,"IDENTIFIER")==0)
	{
		curr=getNextToken(f1);
		idlistprime();
	}
	else
	{
		printf("missing identifier at row=%d col=%d",curr.row,curr.col);
	}
}
void idlistprime()
{
	if(strcmp(curr.lexeme,",")==0)
	{
		curr=getNextToken(f1);
		idlist();
	}
	if(strcmp(curr.lexeme,"[")==0)
	{
		curr=getNextToken(f1);
		if(strcmp(curr.type,"NUMBER")==0)
		{
			curr=getNextToken(f1);
			if(strcmp(curr.lexeme,"]")==0)
			{
				curr=getNextToken(f1);
				if(strcmp(curr.lexeme,",")==0)
				{
					curr=getNextToken(f1);
					idlist();
				}
				else
				{
					return;
				}
			}
		}
	}
	else
	{
		return;
	}
}
void statementlist()
{
	if(strcmp(curr.type,"IDENTIFIER")!=0)
	{
		return;
	}
	statement();
	statementlist();
}
void statement()
{
	assignstat();
	if(strcmp(curr.lexeme,";")==0)
	{
		curr=getNextToken(f1);
		return;
	}
}
void assignstat()
{
	if(strcmp(curr.type,"IDENTIFIER")==0)
	{
		curr=getNextToken(f1);
		if(strcmp(curr.lexeme,"=")==0)
		{
			curr=getNextToken(f1);
			expn();
		}
		else
		{
			printf("= missing at row=%d col=%d",curr.row,curr.col);
			exit(1);
		}
	}
	else
	{
		printf("missing identifier at row=%d col=%d",curr.row,curr.col);
		exit(1);
	}
}
void expn()
{
	simpleexp();
	eprime();
}
void eprime()
{
	if(isrel(curr.lexeme)==0)
	{
		return;
	}
	relop();
	simpleexp();
}
void simpleexp()
{
	term();
	seprime();
}
void seprime()
{
	if(isadd(curr.lexeme)==0)
	{
		return;
	}
	addop();
	term();
	seprime();
}
void term()
{
	factor();
	tprime();
}
void tprime()
{
	if(ismul(curr.lexeme)==0)
	{
		return;
	}
	mulop();
	factor();
	tprime();
}
void factor()
{
	if(strcmp(curr.type,"IDENTIFIER")==0)
	{
		curr=getNextToken(f1);
		return;
	}
	else if(strcmp(curr.type,"NUMBER")==0)
	{
		curr=getNextToken(f1);
		return;
	}
}
void relop()
{
	if(strcmp(curr.lexeme,"==")==0)
	{
		curr=getNextToken(f1);
		return;
	}
	if(strcmp(curr.lexeme,"!=")==0)
	{
		curr=getNextToken(f1);
		return;
	}
	if(strcmp(curr.lexeme,"<=")==0)
	{
		curr=getNextToken(f1);
		return;
	}
	if(strcmp(curr.lexeme,">=")==0)
	{
		curr=getNextToken(f1);
		return;
	}
	if(strcmp(curr.lexeme,"<")==0)
	{
		curr=getNextToken(f1);
		return;
	}
	if(strcmp(curr.lexeme,">")==0)
	{
		curr=getNextToken(f1);
		return;
	}
}
void addop()
{
	if(strcmp(curr.lexeme,"+")==0)
	{
		curr=getNextToken(f1);
		return;
	}
	if(strcmp(curr.lexeme,"-")==0)
	{
		curr=getNextToken(f1);
		return;
	}
}
void mulop()
{
	if(strcmp(curr.lexeme,"*")==0)
	{
		curr=getNextToken(f1);
		return;
	}
	if(strcmp(curr.lexeme,"/")==0)
	{
		curr=getNextToken(f1);
		return;
	}
	if(strcmp(curr.lexeme,"*")==0)
	{
		curr=getNextToken(f1);
		return;
	}
}