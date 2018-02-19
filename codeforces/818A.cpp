#include<iostream>
using namespace std;
int main()
{ long long n, k;
  cin>>n>>k;
  long long diplo=n/(2*(k+1));
  n-=diplo*(k+1);
  cout<<diplo<<' '<<diplo*k<<' '<<n;
return 0;
}
