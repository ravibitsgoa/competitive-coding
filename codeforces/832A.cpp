#include<iostream>
using namespace std;
int main()
{ unsigned long long n, k;
  cin>>n>>k;
  n/=k;
  if(n%2)
    cout<<"YES";
  else
    cout<<"NO";
  return 0;
}
