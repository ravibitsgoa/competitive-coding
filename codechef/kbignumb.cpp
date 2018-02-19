#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{ int t;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>t;
  while(t--)
  { long long int a, n, m;
    cin>>a>>n>>m;
    long long int p=1;
    while(p<=a)
      p*=10;
    long long ans=a%m, pro=1;
    n--;
    while(n--)
    { pro=((pro%m)*(p%m)+1)%m;
    }
    cout<<(ans*pro)%m<<'\n';
  }
return 0;
}
