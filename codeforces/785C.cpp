#include<cmath>
#include<iostream>
#define eps 0.0000000000001
using namespace std;
long long f(double x)
{ if((x-(long long int)x) < eps)
    return (long long int)x;
  else
    return (long long int)(x+1);
}
int main()
{ long long int n, m;
  double i1, i2;
  cin>>n>>m;
  //i1=(2*m-1)-sqrt((double)8*n+1-8*m);
  i2=(2*m-1)+sqrt((double)8*n+1-8*m);
  //i1/=2;
  i2/=2;
  cout<<f(i2);
  return 0;
}
