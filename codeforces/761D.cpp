#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l, r;
  cin>>n>>l>>r;
  int a[n], b[n], c[n], m=0;
  for(int i=0; i<n; i++)
    cin>>a[i];
  for(int i=0; i<n; i++)
    cin>>c[i];
  for(int i=0; i<n; i++)
  { b[i]=a[i]+c[i]-1  ;
    if(b[i]<b[m])
      m=i;
  }
  int min=b[m], max=0;
  for(int i=0; i<n; i++)
  { b[i]-=min;
    b[i]+=l;
    if(b[i]>max)
      max=b[i];
  }
  if(max<=r)
    for(int i=0; i<n; i++)
      cout<<b[i]<<' ';
  else
    cout<<-1;
  //cout<<r<<max;
  return 0;
}
