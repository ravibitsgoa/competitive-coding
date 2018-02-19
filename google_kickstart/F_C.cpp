#include <iostream>
#include <set>
#include <utility>
using namespace std;
int main()
{   int t;
    cin>>t;
    for(int T=1; T<=t; T++)
    {   int n, m, p;
        cin>>n>>m>>p;
        vector<pair<int, long long> > graph[n+1];
        for(int i=0; i<m; i++)
        {   int u, v, p;
            cin>>u>>v>>p;
            graph[u].push_back({v, p});
            graph[v].push_back({u, p});
        }
        //dijkstra coming up:
        int dis[n+1][n+1];    //distance between ith and jth node.
        for(int source=1; source<=N; source++)
        {
            int min_distance[n+1];//computed shortest path distance between given 'source' and ith node.
            int checked[n+1]={0}; //is ith vertex seen?
            set<pair<int,int> > unchecked_nodes;
            int distance_to[n+1]; //Min dijkstra score used for vertex i in the heap.

            int numchecked=1;     //no. of checked verticies. initially 1 (the source) is checked.

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
        }
    }
    return 0;
}
