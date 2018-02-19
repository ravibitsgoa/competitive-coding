#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    cout<<n<<'\n';
    for(int j=0; j<n; j++)
    { cout<<n<<'\n';
      for(int i=1; i<=n; i++)
      { cout<<i<<' '<<1+((i+j-1)%n)<<' '<<1+((i+j)%n)<<'\n';
      }
    }
  }
return 0;
}
