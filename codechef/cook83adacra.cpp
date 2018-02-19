#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { string x;
    cin>>x;
    int u=0, d=0;
    for(int i=1; i<x.length(); i++)
    { if(x[i]!=x[i-1])
      { if(x[i-1]=='U')
          u++;
        else
          d++;
      }
    }
    if(x[x.length()-1]=='U')
      u++;
    else
      d++;
    cout<<min(u,d)<<'\n';
  }
return 0;
}
