#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
   S->aAcBe
   A->Ab|b
   B->d
*/
char lookahead[100];
int i=0;
int proc_s();
int proc_a_dash();
int proc_a();
int proc_b()
{
		if(lookahead[i]=='d')
		{
			i++;
			return 1;
		}
		else
			return 0;
}
int proc_a()
{
	if(lookahead[i]=='b')
	{
		i++;
		if(!proc_a_dash())
			return 0;
		return 1;
	}
    else
    	return 0;
}
int proc_s()
{
	if(lookahead[i]=='a')
	{
		i++;
		if(!proc_a())
			return 0;
		if(lookahead[i]=='c')
		{
			i++;
			if(!proc_b())
			return 0;
		   if(lookahead[i]=='e')
		   {
		   	i++;
		   	return 1;
		   }
		}
	}
	else
		return 0;
}
int proc_a_dash()
{
	if(lookahead[i]=='b')
	{
		i++;
		if(!proc_a_dash())
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