//This implements Floyd Warshall algorithm for all pairs- shortest paths.
#include<cstdio>
#include<algorithm>
const int INF=10000, NMAX=2048;
using namespace std;
int A[NMAX+1][NMAX+1];

int main()
{
  int n, m;   //n= vertices, m = edges.
  scanf("%d %d",&n,&m);
  //Initializing array of distances.
  for(int i=1; i<=n; i++)
  { for(int j=1; j<=n; j++)
    { A[i][j]=INF;
    }
    A[i][i]=0;
  }

  //Taking input of m edges and storing them.
  int x, y, dist;
  for(int i=0; i<m; i++)
  { scanf("%d %d %d",&x,&y,&dist);
    //if(A[x][y]>dist)
    A[x][y] = min(dist, A[x][y]);       // There is an edge with weight "dist", tail x and head y.
  }

  //Here, I have optimized it and have not taken into account number of edges of every path.
  for(int k=1; k<=n; k++)
  { for(int i=1; i<=n; i++)
    { for(int j=1; j<=n; j++)
      { //if(A[i][j] > A[i][k]+A[k][j])
        A[i][j] = min(A[i][j], A[i][k]+A[k][j]);
      }
    }
  }

  //This finds the minimum distance in shortest paths.
  int mindist=0, mini, minj;
  for(int i=1; i<=n; i++)
  { if(A[i][i]<0)           //This happens iff there is negative cycle.
    { printf("NULL\n");
      return 0;
    }
    for(int j=1; j<=n; j++) //Find the min distance between any pair of nodes.
    { mindist = min(mindist, A[i][j]);
    }
  }
  printf("%d\n",mindist);
  return 0;
}
