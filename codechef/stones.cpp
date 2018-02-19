#include<map>
#include<string>
#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { string x, y;
    cin>>x>>y;
    map<char, bool> allowed;
    for(int i=0; i<x.length(); i++)
      allowed[x[i]]=1;
    int ans=0;
    for(int i=0; i<y.length(); i++)
    { ans+=allowed[y[i]];
    }
    cout<<ans<<'\n';
  }

  return 0;
}
