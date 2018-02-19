#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    int ans=0, x, y;
    while(n--)
    { cin>>x>>y;
      ans+=x-y;
    }
    cout<<ans<<endl;
  }
return 0;
}
