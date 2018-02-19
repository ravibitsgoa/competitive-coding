#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { long long n,b;
    cin>>n>>b;
    long long x=n/(2*b),y, ans=0;
    x-=2;
    for(int i=0; i<10; i++)
    { y=n-b*x;
      if(x>0 && y>0)
        ans=max(ans, x*y);
      x++;
    }
    cout<<ans<<'\n';
  }
  return 0;
}
