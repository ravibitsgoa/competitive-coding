#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { long long a, b, n;
    cin>>a>>b>>n;
    if(n%2)
      cout<<max(a*2, b)/min(a*2, b);
    else
      cout<<max(a, b)/min(a, b);
    cout<<'\n';
  }
return 0;
}
