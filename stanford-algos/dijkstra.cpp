//This implements dijkstra's single source shortest path algorithm with a heap DS. Runtime: O(VlogE) 
#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<cassert>
#include<set>
#include<utility>

const int INF=1000000;    //Given in the assignment.

using namespace std;

int main()
{ int n=200;            //no. of verticies in the graph.
  vector<int> gr[n+1];  //stored graph, i.e. the verticies bonded to the ith vertex.
  //cin>>n;
  int source=1;
  int dis[n+1][n+1];    //distance between ith and jth node.
  int min_distance[n+1];//computed shortest path distance between given 'source' (S=1) and ith node.
  int checked[n+1]={0}; //is ith vertex seen?
  set<pair<int,int> > unchecked_nodes;
  int distance_to[n+1]; //Min dijkstra score used for vertex i in the heap.

  int numchecked=1;     //no. of checked verticies. initially 1 (the source) is checked.

  for(int i=1; i<=n; i++)   //Setting distance between all nodes as INF.
  { for(int j=1; j<=n; j++)
    { dis[i][j]=INF;
    }
    dis[i][i]=0;
  }

  for(int i=1; i<=n; i++)
  { int icopy, x, y;
    scanf("%d",&icopy);
    //printf("%d\n",icopy);
    assert(icopy==i);       //icopy and i must be the same.
    char comma, space=' ';
    while(space==' ' || space=='\t')
    { scanf("%d%c%d%c",&x,&comma,&y,&space);
      dis[i][x] = min(dis[i][x], y);
      //dis[x][i] = min(dis[x][i], y);
      gr[i].push_back(x);
      //gr[x].push_back(i);
    }
  }//input phase complete :)
  //printf("%d\n",dis[55][41]);
  checked[source]=1;
  min_distance[source]=0;               //Distance between source 1 and itself is 0.
  for(int i=2; i<=n; i++)
  { unchecked_nodes.insert({ dis[source][i], i });
    min_distance[i]=distance_to[i]=dis[source][i];
    //cout<<i<<' '<<min_distance[i]<<'\n';
  }

  while(numchecked != n)
  { auto i = unchecked_nodes.begin();
    int w  = i->second;
    //cout<<w<<endl;
    //assert(!checked[w]);
    checked[w] = 1;
    min_distance[w] = distance_to[w];
    //cout<<w<<' '<<distance_to[w]<<endl;
    //assert(min_distance[w] == i->first);    //Just for debugging.
    for(int v: gr[w])
    { if(!checked[v])
      { int dist = distance_to[v];
        auto k = unchecked_nodes.find({dist, v});
        //assert(k != unchecked_nodes.end());
        distance_to[v]=dist=min(dist, min_distance[w]+dis[w][v]);
        unchecked_nodes.erase(k);
        unchecked_nodes.insert({dist, v});
      }
    }
    unchecked_nodes.erase(i);
    numchecked++;
  }
  int needed[10]={7,37,59,82,99,115,133,165,188,197};
  for(int i=0; i<10; i++)
  { cout<<min_distance[needed[i]];
    if(i!=9)
      cout<<',';
  }
  cout<<endl;
  //cout<<' ';
return 0;
}
