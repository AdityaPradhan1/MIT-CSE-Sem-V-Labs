#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*
	T -> ST'
	T' -> ,ST'|e
	S -> a|>|(T)
*/
char lookahead[100];
int i=0;
int proc_s();
int proc_t_dash();

int proc_t()
{
	if(!proc_s())
		return 0;
	if(!proc_t_dash())
		return 0;
	return 1;
}
int  proc_s()
{
	if(lookahead[i] == 'a')
	{
		i++;
		return 1;
	}
	else if(lookahead[i] == '^')
	{
		i++;
		return 1;
	}
	else if(lookahead[i] == '(')
	{
		i++;
		if(!proc_t())
			return 0;
		if(lookahead[i] == ')')
		{
			i++;
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

int proc_t_dash()
{
	if(lookahead[i] == ',')
	{
		i++;
		if(!proc_s())
		return 0;
		if(!proc_t_dash())
		return 0;
		return 1;
	}
	else
	{
		return 1;
	}
}

int main()
{
	printf("Enter the string : ");
	gets(lookahead);
	if(!proc_s())
	{
		printf("Rejected\n");
		return 0;
	}
	if(i==strlen(lookahead))
		printf("Accepted!\n");
	else
		printf("Rejected\n");
}