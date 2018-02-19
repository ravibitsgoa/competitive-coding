#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int n, l;
  cin>>n>>l;
  int a[n], b[n];
  for(int i=0; i<n; i++)
  {  cin>>a[i];
  }
  for(int i=1; i<n; i++)
  {  a[i]-=a[i-1];
    cout<<a[i]<<i<<endl;
  }
  a[0]=0;
  for(int i=0; i<n; i++)
    cin>>b[i];
  for(int i=n-1; i>0; i--)
  {  b[i]-=b[i-1];
    cout<<b[i]<<i<<endl;
  }
  b[0]=0;
  sort(a, a+n);
  //mergesort(a, 0, n);
  sort(b, b+n);
  //mergesort(b, 0, n);
  for(int i=0; i<n; i++)
    if(a[i]!=b[i])
    { cout<<"NO";
      return 0;
    }
  cout<<"YES";
  return 0;
}
