#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "lex_analyzer.h"
#include "initialize.h"

FILE* f1;
struct token tkn;


void Program();
void declarations();
int data_type();
void identifier_list(struct token);
void assign_stat(struct token);

void invalid(struct token* tkn)
{
	printf("error at row: %d, col: %d for lexeme \" %s \" \n", tkn->row, tkn->col, tkn->lexeme);
	printf("-----------------ERROR!----------------\n");
	exit(0);
}

void valid()
{
	printf("----------------SUCCESS!---------------\n");
	exit(0);
}

void Program()
{
	tkn = getNextToken(f1);
	if(strcmp(tkn.lexeme, "main") == 0)
	{
		tkn = getNextToken(f1);
		if(strcmp(tkn.lexeme, "(") == 0)
		{
			tkn = getNextToken(f1);
			if(strcmp(tkn.lexeme, ")") == 0)
			{
				tkn = getNextToken(f1);
				if(strcmp(tkn.lexeme, "{") == 0)
				{
					declarations();
					//printf("after coming back from declarations\n");
					tkn = getNextToken(f1);
					if(strcmp(tkn.lexeme, "}") == 0)
					{
						return;
					}
					else
					{

						invalid(&tkn);
					}
				}
				else
				{
					invalid(&tkn);
				}
			}
			else
			{
				invalid(&tkn);
			}
		}
		else
		{
			invalid(&tkn);
		}
	}
	else
	{
		invalid(&tkn);
	}
}

void declarations()
{
	//printf("here in declarations\n");
	tkn = getNextToken(f1);
		//printf("now the token is: %s \n", tkn.lexeme);
	if(data_type(tkn.lexeme))
	{
		tkn =  getNextToken(f1);
		identifier_list(tkn);
		tkn = getNextToken(f1);

		//printf("now then token is: %s \n", tkn.lexeme);
		if(strcmp(tkn.lexeme, ";") == 0)
		{
			declarations();
		}
		else
		{
			invalid(&tkn);
		}
	}
	else
	{
		//printf("here\n");
		assign_stat(tkn);
	}
}

int data_type(char* lx)
{

	if(strcmp(lx, "int") == 0 || strcmp(lx, "char") == 0)
	{
		return 1;
	}
	else
	{
					//printf("here\n");
		return 0;
	}
}

void identifier_list(struct token tkn)
{
	struct token tkn2;

	tkn2 = tkn;
	if(strcmp(tkn2.type, "identifier") == 0)
	{

		tkn2 = getNextToken(f1);
		if(strcmp(tkn2.lexeme, ",") == 0)
		{
			tkn2 = getNextToken(f1);
			identifier_list(tkn);
		}
		else if(strcmp(tkn2.lexeme, ";") == 0)
		{
		//printf("now the token is: %s \n", tkn2.lexeme);
			fseek(f1, -1, SEEK_CUR);
			return;
		}
		else
		{
			invalid(&tkn2);
		}
	}
	
}

void assign_stat(struct token tkn)
{
	struct token tkn2;
	if(strcmp(tkn.type, "identifier") == 0)
	{
		//printf("the lexeme before the error is: %s \n", tkn.lexeme);
		tkn2 = getNextToken(f1);
		//printf("the lexeme after the error is: %s \n", tkn.lexeme);
		if(strcmp(tkn2.lexeme, "=") == 0)
		{
			tkn2 = getNextToken(f1);
			if(strcmp(tkn2.type, "number") == 0 || strcmp(tkn2.type, "identifier"))
			{
				tkn2 = getNextToken(f1);
				if(strcmp(tkn2.lexeme, ";") == 0)
				{
					return;
				}
				else
				{
								//printf("here 1 \n");
					invalid(&tkn);
				}
			}
			else
			{			//printf("here 2 \n");
				invalid(&tkn);
			}
		}
		else
		{			//printf("here 3 \n");
			invalid(&tkn);
		}
	}
}


int main()
{

	//initialize();
	//initialize_list();
	f1 = fopen("op.c","r");
	// now we generate the tokens
	if(f1==NULL)
	{
	  	printf("Error! File cannot be opened!\n");
	  	return 0;
	}
	//struct token tkn;
	struct sttable st[10][100];
	int flag=0,i=0,j=0;
	int tabsz[10];
	char w[25];
	w[0]='\0';

	Program();
	valid();
	/*
	while((tkn=getNextToken(f1)).row!=-1)
	{
		printf("<%s, %d, %d, %s>\n",tkn.lexeme,tkn.row,tkn.col,tkn.type);
	}
	*/

}