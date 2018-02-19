#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n, b;
    cin>>n>>b;
    if(b>1)
      cout<<"NO"<<'\n';
    else if(b==0)
    { cout<<"YES"<<'\n';
      for(int j=2; j<=n; j++)
        cout<<1<<' '<<j<<'\n';
    }
    else
    { cout<<"YES"<<'\n';
      for(int j=2; j<n; j++)
        cout<<1<<' '<<j<<'\n';
      cout<<2<<' '<<n<<'\n';      
    }
  }
return 0;
}
