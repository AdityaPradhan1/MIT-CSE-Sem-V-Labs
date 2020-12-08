#include <stdio.h>
#include <stdlib.h>

main()
{
	int i,a,b,sum,x[20];//Comment
	int z;
	a=1;
	b=1;
	for(i=0;i<20;i=i+1)
	{
		while(a<b){

		if(a<b)
		{
			a = a + 5;
		}
		else
		{
			b =b + a;
		}
	}
	}
	if(a<=b)
	{
		if(a==b)
		{
			if(a!=b)
			{
				a = b * 5;
			}
		}
		else
		{
			b = a * 10;
		}
	}
	else
	{
		a = 20;
		b = 20;
		a = b + a;
	}
	sum=a+b;
	sum = sum + 1;
}
