#include<iostream>
using namespace std;
long long f(long long x, long long y)
{ long long ans= (x+y+1)*(x+y)/2;
  ans+=x+1;
  return ans;
}
int main()
{ int t;
  cin>>t;
  while(t--)
  { int u, v;
    cin>>u>>v;
    cout<<max(max(f(u,0),f(0,v)),f(u,v))<<'\n';
  }
  return 0;
}
