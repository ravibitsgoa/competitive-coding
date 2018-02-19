#include<iostream>
#include<string>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { string x;
    cin>>x;
    int f[58]={0}, ans=0;
    for(int i=0; i<x.length(); i++)
      f[x[i]-'A']++;
    cin>>x;
    for(int i=0; i<x.length(); i++)
    { if(f[x[i]-'A']>0)
      { f[x[i]-'A']--;
        ans++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
