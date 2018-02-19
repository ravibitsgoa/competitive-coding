#include<iostream>
#define M 1000000007
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { unsigned long long int x, y, z, a, b, c;
    cin>>x>>y>>z;
    a=max(max(x,y),z);//a is biggest.
    c=min(min(x,y),z);//c is smallest.
    b=x+y+z-a-c;
    c %= M;
    c = (c*((b-1) % M))%M;
    c = (c*((a-2) % M))%M;
    if(c<0)
      c+=M;
    cout<<c<<endl;
  }
return 0;
}
