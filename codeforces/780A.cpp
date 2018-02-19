#include<map>
#include<iostream>
using namespace std;
int main()
{ int n;
  cin>>n;
  n*=2;
  int oddsocks=0, x, ans=0;
  map<int, int> socks;
  while(n--)
  { cin>>x;
    if(socks[x]==1)
      oddsocks--;
    else
      oddsocks++;
    socks[x]++;
    ans=max(ans,oddsocks);
  }
  cout<<ans;
  return 0;
}
