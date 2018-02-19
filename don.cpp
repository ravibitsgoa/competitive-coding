#include<iostream>
using namespace std;
int main()
{ string x;
  cin>>x;
  int ans=0, flag=0, len=0;
  for(int i=0; i<x.length(); i++)
  { if(x[i]=='I')
    { if(flag!=1) len=1;
      else len++;
      flag=1;
    }
    if(x[i]=='E')
    { if(flag!=2 && flag!=1) len=0;
      else len++;
      flag=2;
    }
    if(x[i]=='M')
    { if(flag!=2 && flag!=3) len=0;
      else len++;
      flag=3;
    }
    if(ans<len && len%3==0) ans=len;
  }
  cout<<ans;
  return 0;
}
