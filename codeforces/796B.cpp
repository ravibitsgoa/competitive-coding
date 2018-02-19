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
  int n, m, k;
  cin>>n>>m>>k;
  int x=1;//original posn
  int holes[n+1]={0};
  int temp;
  for(int i=0; i<m; i++)
  { cin>>temp;
    holes[temp]=1;
  }
  int u,v;
  while(k--)
  { cin>>u>>v;
    if(holes[x])
      break;
    if(u==x)
      x=v;
    else if(v==x)
      x=u;
  }
  cout<<x;
  return 0;
}
