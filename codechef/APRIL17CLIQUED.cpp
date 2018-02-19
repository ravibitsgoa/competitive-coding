#include<set>
#include<vector>
#include<iostream>
#include<climits>
const long long INF=INT_MAX;
using namespace std;
struct edge { long long to, length; };

void dijkstra(vector< vector<edge> > &graph, long long source)
{   vector<long long> min_distance( graph.size(), INF );
    min_distance[ source ] = 0;
    set< pair<long long, long long> > active_vertices;
    active_vertices.insert( {0,source} );

    while (!active_vertices.empty())
    {   long long where = active_vertices.begin()->second;
        active_vertices.erase( active_vertices.begin() );
        for (auto ed : graph[where])
            if (min_distance[ed.to] > min_distance[where] + ed.length)
            {   active_vertices.erase( { min_distance[ed.to], ed.to } );
                min_distance[ed.to] = min_distance[where] + ed.length;
                active_vertices.insert( { min_distance[ed.to], ed.to } );
            }
    }
    for(long long i=0; i<graph.size(); i++)
    { cout<<min_distance[i]<<' ';
    }
    cout<<'\n';
}
void solve()
{ long long N, K, X, M, S;
  cin>>N>>K>>X>>M>>S;
  vector< vector<edge> > gr(N);//first element in the pair is the node number and 2nd one is distance.
  for(long long i=0; i<K; i++)
  { for(long long j=0; j<K; j++)
    { struct edge one={j, X}, two={i, X};
      gr[i].push_back(one);
      gr[j].push_back(two);
    }
  }
  while(M--)
  { long long a, b, c;
    cin>>a>>b>>c;
    struct edge one={b-1, c}, two={a-1, c};
    gr[a-1].push_back(one);
    gr[b-1].push_back(two);
  }
  dijkstra(gr, S-1);
}
int main()
{ ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  { solve();
  }
  //cout<<INF;
return 0;
}
