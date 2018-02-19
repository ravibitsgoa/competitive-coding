#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { long long ans=0;
    int n, x;
    cin>>n;
    while(n--)
    { cin>>x;
      ans|=x;
    }
    cout<<ans<<'\n';
  }
  return 0;
}
