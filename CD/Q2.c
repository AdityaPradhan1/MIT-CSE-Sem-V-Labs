#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
   E->E+T
   T->T+F
   F->(E)|id
*/
char lookahead[100];
int i=0;
int proc_e();
int proc_e_dash();
int proc_t();
int proc_t_dash();
int proc_f()
{
	if(lookahead[i]=='(')
	{
		i++;
		if(!proc_e())
			return 0;
		if(lookahead[i]==')')
		{
			i++;
			return 1;
		}
	}
	if(lookahead[i]=='i')
	{
		i++;
		if(lookahead[i]=='d')
			i++;
		return 1;
	}
	else
		return 0;
}
int proc_e()
{
	if(!proc_t())
		return 0;
	if(!proc_e_dash())
		return 0;
	return 1;
}
int proc_t()
{
	if(!proc_f())
		return 0;
	if(!proc_t_dash())
		return 0;
	return 1;
}
int proc_e_dash()
{
	if(lookahead[i]=='+')
	{
		i++;
		if(!proc_t())
			return 0;
		if(!proc_e_dash())
			return 0;
		return 1;
	}
	else
		return 1;
}
int proc_t_dash()
{
	if(lookahead[i]=='*')
	{
		i++;
		if(!proc_f())
			return 0;
		if(!proc_t_dash())
			return 0;
		return 1;
	}
	else
		return 1;
}
int main()
{
	printf("Enter the string : ");
	gets(lookahead);
	if(!proc_e())
	{
		printf("Rejected\n");
		return 0;
	}
	if(i==strlen(lookahead))
		printf("Accepted!\n");
	else
		printf("Rejected\n");
}