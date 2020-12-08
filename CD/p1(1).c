#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char p[30],t[50],table[27];
	printf("Enter text:\n");
	fgets(t,50,stdin);
	printf("Enter pattern:\n");
	fgets(p,30,stdin);
	int m=strlen(p)-1;
	int n=strlen(t)-1;
	printf("%d %d\n",m,n );
	for(int i=0;i<26;i++){
		printf("%c ",i+97);
		table[i]=m;
	}
	printf("\n");
	for(int i=0;i<m-1;i++){
		table[p[i]-97]=m-i-1;
	}
	for(int i=0;i<26;i++){
		printf("%d ",table[i]);
	}
	printf("\n");
	int j=m;
	int k;
	while(j<=n-1)
	{
		k=0;
		while(k<=m &&p[m-1-k]==t[j-k])
		{
			k++;
		}
		if(k==m)
		{
			printf("Match found at position: %d\n",j-(k-1)+1);
			return 0;
		}
		else
			j+=table[t[j]-97];
	}		
	printf("No match found\n");
	return 0;
}