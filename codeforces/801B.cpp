#include<iostream>
using namespace std;
int main()
{ string x, y;
  char z[105]={0};
  cin>>x>>y;
  bool notpossible=0;
  for(int i=0; i<x.length(); i++)
  { if(y[i]>x[i])
    { notpossible=1;
      break;
    }
    z[i]=min(x[i],y[i]);
  }
  if(notpossible)
    cout<<-1;
  else
    cout<<z;
return 0;
}
