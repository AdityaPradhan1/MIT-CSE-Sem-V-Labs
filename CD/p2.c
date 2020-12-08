#include <stdio.h>
#include <stdlib.h>
int main()
{
    int E,V,n;
    int G[20][20];
    int i,j,v1,v2;
    printf("\t\t\tGraphs\n");
    printf("Enter the no of edges:");
    scanf("%d",&E);
    printf("Enter the no of vertices:");
    scanf("%d",&V);
    n=V;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            G[i][j]=0;
    }
    for(i=0;i<E;i++)
    {
        printf("Enter the edges (format: V1 V2) : ");
        scanf("%d%d",&v1,&v2);
        G[v1-1][v2-1]=1;

    }
    printf("\n********ADJACENCY MATRIX*********\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            printf(" %d ",G[i][j]);
        printf("\n");
    }
    int k,indeg[10],flag[10],count=0;
    for(i=0;i<n;i++)
    {
        indeg[i]=0;
        flag[i]=0;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            indeg[i]=indeg[i]+G[j][i];
    printf("\nTopological Sort: ");
    while(count<n)
    {
        for(k=0;k<n;k++)
        {
            if((indeg[k]==0) && (flag[k]==0))
            {
                printf("%d\t",(k+1));
                flag [k]=1;
            }
            for(i=0;i<n;i++)
            {
                if(G[i][k]==1)
                    indeg[k]--;
            }
        }
        count++;
    }
    printf("\n");
    return 0;
}
