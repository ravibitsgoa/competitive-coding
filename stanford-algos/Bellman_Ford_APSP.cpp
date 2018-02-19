//This implements Bellman Ford algorithm to find all pairs- shortes paths.
#include<iostream>
#include<vector>
#include<utility>
const int INF=2000000, NMAX=2048;
using namespace std;
int A[NMAX+1];//shortest distance from S to ith node.
vector<int> inverted_graph[NMAX+1];
int C[NMAX+1][NMAX+1];

int main()
{ ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;   //n= vertices, m = edges.
  cin>>n>>m;

  //Initializing array of distances.
  for(int i=1; i<=n; i++)
  { A[i]=INF;
    for(int j=1; j<=n; j++)
      C[i][j]=INF;
    C[i][i]=0;
  }

  //Taking input of m edges and storing them.
  for(int i=0; i<m; i++)
  { int x, y, dist;
    cin>>x>>y>>dist;
    C[x][y] = min(C[x][y], dist);                   // There is an edge with weight "dist", tail x and head y.
    inverted_graph[y].push_back(x);
    //graph[x].push_back({y, dist});
  }

  int s=1;
  //cin>>s;                           //Source vertex.
  A[s]=0;                             //Min distance of source to itself will be zero.

  for(int i=1; i<n; i++)                      //number of edges in a graph can be at most n.
  { for(int j=1; j<=n; j++)                   //For all vertices in graph.
    { for(int x: inverted_graph[j])        //For all nodes pointing to node j.
      { if(A[x] + C[x][j] < A[j])
        { A[j] = A[x] + C[x][j];
        }
      }
    }
  }

  //Check for negative cycles: If the distances remain the same for one more iteration, we don't have negative cycles.
  int cycle=1;                         //If no edges are updated in this iteration, there is no negative cycle.
  for(int j=1; j<=n; j++)                   //For all vertices in graph.
  { for(int x: inverted_graph[j])           //For all nodes pointing to node j.
    { if(A[x] + C[x][j] < A[j])
      { //A[i][j] = A[i-1][x] + C[x][j];
        cycle=0;
        break;
      }
    }
  }

  if(cycle==0) //A negative cycle has been detected!
  { cout<<"NULL"<<'\n';
    return 0;
  }

  //This finds the minimum distance in shortest paths.
  int mindist=A[1];
  for(int i=2; i<=n; i++)
  { if(mindist > A[i])
      mindist = A[i];
    //cout<<i<<' '<<A[i]<<'\n';
  }
  cout<<mindist<<'\n';
  return 0;
}
