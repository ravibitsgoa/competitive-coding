#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { string x;
    cin>>x;
    int ans=1;
    for(int i=1; i<x.length(); i++)
    { if(x[i]>=x[i-1]) ans+=x[i]-x[i-1];
      else ans+=26+x[i]-x[i-1];
    }
    if(ans<= 10*x.length())
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
