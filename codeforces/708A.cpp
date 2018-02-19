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
  int n,m,k;
  cin>>n>>m>>k;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  int mi=inf;
  for(int i=0; i<m; i++)
  { if(a[i]!=0 && a[i]<=k)
      mi=min(mi, 10*(m-i-1));
  }
  for(int i=m+1; i<n; i++)
  { if(a[i]!=0 && a[i]<=k)
      mi=min(mi, 10*(i+1-m));
  }
  cout<<mi;
  return 0;
}
