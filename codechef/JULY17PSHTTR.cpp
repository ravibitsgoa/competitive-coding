#include<vector>
#include<iostream>
using namespace std;
int main()
{ int T;
  cin>>T;
  while(T--)
  { int N;
    cin>>N;
    vector<pair<int,int> > graph[N+1];
    for(int i=0; i<N-1; i++)
    { int x, y, cost;
      cin>>x>>y>>cost;
      graph[x].push_back({y,cost});
      graph[y].push_back({x,cost});
    }
    vector<int> val[N+1];
    int ex[N+1]={0};
    ex[1]=1;
    int stack[N+1]={0}, size=1;
    stack[0]=1;

    for(int i=0; i<size; i++)
    { for(int y=0; y<graph[stack[i]].size(); y++)
      { int k=graph[stack[i]][y].first;
        if(ex[k]==0)
        { ex[k]=1;
          stack[size++]=k;
          val[k]=val[stack[i]];
          val[k].push_back(graph[stack[i]][y].second);
        }
      }
    }

    int Q;
    cin>>Q;
    while(Q--)
    { int u, v, k, ans=0;
      cin>>u>>v>>k;
      for(int i=0; i<val[u].size(); i++)
      { if(val[u][i] <= k)
          ans^=val[u][i];
      }
      for(int i=0; i<val[v].size(); i++)
      { if(val[v][i] <= k)
          ans^=val[v][i];
      }
      cout<<ans<<'\n';
    }
  }
return 0;
}
