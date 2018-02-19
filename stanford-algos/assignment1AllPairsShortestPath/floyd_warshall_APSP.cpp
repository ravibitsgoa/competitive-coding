//This implements Floyd Warshall algorithm for all pairs- shortest paths.
#include<cstdio>
#include<algorithm>
const int INF=10000, NMAX=2048; //According to the constraints of the test-files.
using namespace std;
int A[NMAX+1][NMAX+1];

int main()
{
    int n, m;   //n= number of vertices, m = number of edges in the directed graph.
    scanf("%d %d",&n,&m);
    //Initializing array of distances.
    for(int i=1; i<=n; i++)
    {   for(int j=1; j<=n; j++)
        {   A[i][j]=INF;        //This makes distance from every node to every other node = INF.
        }
        A[i][i]=0;              //distance from every node to itself is zero.
    }

    //Taking input of m edges and storing them.
    int x, y, dist;
    for(int i=0; i<m; i++)
    {   scanf("%d %d %d",&x,&y,&dist);

        if(A[x][y]>dist)        // HERE.
            A[x][y]=dist;       // There is an edge with weight "dist", tail x and head y.
    }

    for(int k=1; k<=n; k++)
    {   for(int i=1; i<=n; i++)
        {   for(int j=1; j<=n; j++)
            {   if(A[i][j] > A[i][k]+A[k][j])   //HERE.
                    A[i][j] = A[i][k]+A[k][j];
            }
        }
    }

    //This finds the minimum distance in shortest paths.
    int mindist=0, mini, minj;
    for(int i=1; i<=n; i++)
    {   if(A[i][i]<0)           //This happens iff there is negative cycle.
        {   printf("NULL\n");
            return 0;
        }
        for(int j=1; j<=n; j++) //Find the min distance between any pair of nodes.
        {   if(mindist > A[i][j])
            {   mindist= A[i][j];
            }
        }
    }
    printf("%d\n",mindist);
    return 0;
}
