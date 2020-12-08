#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
   le->at|li
   at->n|id
   li->(ls)
   ls->leL
   L->le|E
*/
char lookahead[100];
int i=0;
int proc_le();
int proc_at();
int proc_li();
int proc_L();
int proc_ls()
{
	if(!proc_le())
		return 0;
    else if(!proc_L())
		  return 0;
		else
	 return 1;
}
int proc_L()
{
	if(!proc_le())
		return 0;
	else if(!proc_L())
		return 0;
	else
    return 1;
}
int proc_li()
{
    if(lookahead[i] == '(')
	{
		i++;
		if(!proc_ls())
			return 0;
		if(lookahead[i] == ')')
		{
			i++;
			return 1;
		}
	}
	else
		return 0;
}
int proc_at()
{
	if(lookahead[i]=='n')
	{
		i++;
		return 1;
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
int proc_le()
{
   if(!proc_at())
     return 0;
   if(!proc_li())
     return 0;
   return 1; 
}
int main()
{
	printf("Enter the string : ");
	gets(lookahead);
	if(!proc_le())
	{
		printf("Rejected\n");
		return 0;
	}
	if(i==strlen(lookahead))
		printf("Accepted!\n");
	else
		printf("Rejected\n");
}