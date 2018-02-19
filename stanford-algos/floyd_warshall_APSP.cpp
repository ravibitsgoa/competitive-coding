//This implements Floyd Warshall algorithm for all pairs- shortest paths.
#include<cstdio>
#define INF 1<<30;
int main()
{ 	int n, m;                //n = number of nodes in the directed graph, m = number of verticies.
    scanf("%d %d", &n, &m);
    int A[n+1][n+1][n+1];   
    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
    {   if(i!=j)
            A[i][j][0]=INF;
        else
            A[i][j][0]=0;
    }
    for(int i=0; i<m; i++)
    {   int x, y, dist;
        scanf("%d %d %d",x,y,dist);
        A[x][y][0]=dist;
    }
    for(int k=1; k<=n; k++)
    {   for(int i=1; i<=n; i++)
        {   for(int j=1; j<=n; j++)
            {   A[i][j][k]=min(A[i][j][k-1], A[i][k][k-1] + A[k][j][k-1]);
            }
        }
    }
    int mindist=A[1][2][n];
    for(int i=1; i<=n; i++)
    {   for(int j=1; j<=n; j++)
        {   if(i!=j)
                mindist=min(mindist, A[i][j][n]);
            else if(A[i][i][n]<0)
            {   printf("NULL");
                return 0;
            }
        }
    }
    printf("%d",mindist);
    return 0;
}
