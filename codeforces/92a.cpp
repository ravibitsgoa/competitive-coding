#include<iostream>
using namespace std;
int main()
{ int n, k, ans;
  cin>>n>>k;
  ans=k%(n*(n+1)/2);
  for(int i=1; i<=ans; i++)
  { ans-=i;
  }
  cout<<ans;
  return 0;
}
