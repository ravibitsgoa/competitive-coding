#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ int n;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  long long int sum=0, ans=0;
  for(int i=0; i<n; i++)
    sum+=a[i];
  for(int i=0; i<n; i++)
  { sum-=a[i];
    ans+=a[i]&sum;
    cout<<sum;
  }
  cout<<ans;
return 0;
}
