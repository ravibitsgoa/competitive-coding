#include<iostream>
using namespace std;
long long int gcd(long long int a, long long int b)
{ if(a==0) return b;
  if(b==0) return a;
  if(a>=b) return gcd(a%b, b);
  return gcd(a, b%a);
}
int main()
{ int t;
  cin>>t;
  while(t--)
  { long long int n, x, y;
    cin>>n;
    cin>>x>>y;
    if(y<x){long long int t=y; y=x; x=t;}
    n-=2;
    while(n--)
    { long long int t;
      cin>>t;
      if(t<x) x=t;
      else if(t<y) y=t;
    }
    cout<<x*y/gcd(x,y)<<endl;
  }
  return 0;
} 
