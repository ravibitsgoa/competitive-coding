#include<cmath>
#include<iostream>
const double EPS=1e-9;
using namespace std;
int main()
{ long long a, b;
  cin>>a>>b;
  long long ans=0;
  for(long long x=1; x<=a; x++)
  { ans+=(long long)sqrt(b+(double)(x*x))-(long long)sqrt(1+(double)x*x);
    //ans+= isint(sqrt(1+(double)x*x));
    //cout<<(long long)sqrt(b+(double)(x*x))<<' '<<(long long)sqrt(1+(double)(x*x));
  }
  cout<<ans;
  return 0;
}
