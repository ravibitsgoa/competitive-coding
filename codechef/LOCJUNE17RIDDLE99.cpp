#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int a, b, m;
    cin>>a>>b>>m;
    b/=m;
    a=(a-1)/m;
    cout<<b-a<<'\n';
  }
  return 0;
}
