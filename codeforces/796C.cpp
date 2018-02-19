using namespace std;
#include <bits/stdc++.h>
#define rep(i,n) for(auto i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define clr clear()
#define inf (1<<30)
#define ins insert
#define eps 1e-9
int main()
{ cin.tie(NULL);
  ios_base::sync_with_stdio(0);
  int n;
  cin>>n;
  vector<int> graph[n+1];
  long long int a[n+1]={0};
  for(int i=0; i<n; i++)
  { cin>>a[i];
  }
  int x, y, mxstr=1;
  for(int i=0; i<n-1; i++)
  { cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
    if(a[x]>a[mxstr])
      mxstr=x;
    if(a[y]>a[mxstr])
      mxstr=y;
  }
  long long int ans=a[mxstr], n0=n;
  x=mxstr;
  vector<int> visited;
  visited.push_back(x);
  a[x]=0;
  while(n0--)
  { int mx=0;
    for(int i=0; i<visited.size(); i++)
    { for(int j=0; j<graph[visited[i]].size(); j++)
      { if((a[graph[visited[i]][j]]!=0 && a[mx]<=a[j])||mx==0)
          mx=graph[visited[i]][j];
      }
    }
    visited.push_back(mx);
    ans=max(ans, a[mx]);
    a[mx]=0;
    bool once[n+1]={0};
    for(int i=0; i<visited.size(); i++)
    { for(int j=0; j<graph[visited[i]].size(); j++)
      { if(!once[n+1] && a[graph[visited[i]][j]]!=0)
        { once[n+1]=1;
          a[graph[visited[i]][j]]++;
        }
        for(int k=0; k<graph[j].size(); k++)
        { if(!once[n+1] && a[graph[visited[i]][j]]!=0)
          { once[n+1]=1;
            a[graph[visited[i]][j]]++;
          }
        }
      }
    }
  }
  cout<<ans;
  return 0;
}
