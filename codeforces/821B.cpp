#include<iostream>
#define EPS 1e-9
using namespace std;
long double abs(long double x)
{ if(x<0)
    return -x;
  else
    return x;
}
unsigned long long f(unsigned long long a, unsigned long long b)
{ unsigned long long ans=(a+1)*(b+1)*(a+b)/2;
  return ans;
}
unsigned long long g(long double x)
{ if(abs(x-(unsigned long long)x)<=EPS)
    return x;
  else
    return x+1;
}
int main()
{ unsigned long long m, b;
  cin>>m>>b;
  unsigned long long ans=0;
  for(unsigned long long alpha=0; alpha<=m*b; alpha++)
  { unsigned long long beta=b;
    beta-=g(alpha/(long double)m);
    //cout<<alpha<<' '<<beta<<' ';
    if(beta<0)
      continue;
    ans=max(ans, f(alpha, beta));
    //cout<<ans<<endl;
  }
  cout<<ans;
return 0;
}
