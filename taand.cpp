#include<bits/stdc++.h>
using namespace std;
int main()
{ int n, a, b, //imin=0, freq[30]={0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  int ans=0;
  cin>>b;
  n--;
  while(n--)
  { cin>>a;
    if(ans<(a&b))
      ans=a&b;
    b=a;
  }
  cout<<ans;
  return 0;
}
