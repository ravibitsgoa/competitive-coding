#include<iostream>
#include<cassert>
typedef unsigned long long ull;
using namespace std;
int character(ull k)
{ ull i=1;
  if((k&(k-1)) == 0)
    return 0;
  while(i<=k)
    i*=2;
  if(i>k)  return !character(i-k);
  else  {cout<<i<<' '<<k<<"error"; assert(0);}
}
char f(ull k)
{ if(character(k)==0)
    return 'a';
  else
    return 'c';
}
int main()
{ int t;
  cin>>t;
  while(t--)
  { ull k;
    cin>>k;
    cout<<f(k)<<'\n';
  }
return 0;
}
