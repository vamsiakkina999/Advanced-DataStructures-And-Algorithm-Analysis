#include<stdio.h>
#define INF 9999
#define MAX 20

int main()
{
    int n,cost[MAX][MAX],dist[MAX],visited[MAX];
    int i,j,src,min,u,v;

    printf("Enter the number of nodes:\n");
    scanf("%d",&n);

    printf("Enter the cost matrix (use 0 for no direct path):\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0 && i!=j)
                cost[i][j]=INF;
        }
    }

    printf("Enter the source node (0 to %d):\n",n-1);
    scanf("%d",&src);

    for(i=0;i<n;i++)
    {
        dist[i]=cost[src][i];
        visited[i]=0;
    }

    dist[src]=0;
    visited[src]=1;

    for(i=1;i<n;i++)
    {
        min=INF;
        for(j=0;j<n;j++)
        {
            if(!visited[j] && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }

        visited[u]=1;

        for(v=0;v<n;v++)
        {
            if(!visited[v] && dist[u]+cost[u][v] < dist[v])
            {
                dist[v]=dist[u]+cost[u][v];
            }
        }
    }

    printf("Shortest path(s) from node %d:\n",src);
    for(i=0;i<n;i++)
    {
        if(i!=src)
            printf("%d -> %d, cost = %d\n",src,i,dist[i]);
    }

    return 0;
}
