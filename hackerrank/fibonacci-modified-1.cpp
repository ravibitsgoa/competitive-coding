#include <iostream>
using namespace std;
const int MOD = 1e9 +7;
int main()
{
  int t;
  cin>>t;
  for(int i=1; i<=t; i++)
  {
    long long x=1, y=1, n=i;
    n--;
    //cin>>x>>y>>n;
    n%=6;
    long long ans;
    if(n%3 == 0)
      ans=x;
    if(n%3 == 1)
      ans=y;
    if(n%3 == 2)
      ans=y-x;
    if(n>2)
      ans*=-1;
    ans%=MOD;
    if(ans<0)
      ans+=MOD;
    cout<<ans<<'\n';
  }
return 0;
}
