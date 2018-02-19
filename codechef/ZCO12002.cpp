#include<algorithm>
#include<iostream>
#include<utility>
#include<cassert>
using namespace std;
int main()
{ long long n, x, y;
  cin>>n>>x>>y;
  pair<long long, long long> a[n];
  for(int i=0; i<n; i++)
  { cin>>a[i].first>>a[i].second;
  }
  sort(a, a+n);
  long long v[x], w[y];
  for(int i=0; i<x; i++)
    cin>>v[i];
  for(int i=0; i<y; i++)
    cin>>w[i];
  sort(v, v+x);
  sort(w, w+y);
  long long ans=1e17;
  for(int aiter=0; aiter<n; aiter++)
  { if(a[aiter].first < v[0])
      continue;
    if(a[aiter].second > w[y-1])
      continue;
    auto i1=lower_bound(v, v+x, a[aiter].first);
    while(*i1 > a[aiter].first)
      i1--;
    auto i2=lower_bound(w, w+y, a[aiter].second);
    //if(i1<v || i2>=w+y)
      //assert(0);
    ans = min(ans, (*i2-*i1+1));
  }
  cout<<ans;
return 0;
}
