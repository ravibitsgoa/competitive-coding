#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ int n;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  int inp[n];
  for(int i=0; i<n; i++)
    cin>>inp[i];
  sort(inp, inp+n);
  for(int i=0; i<n; i++)
    for(int j=i+1; j<n-1; j++)
    { if((inp[i])>(inp[j+1]-inp[j]))
      { cout<<"YES";
        return 0;
      }
    }
  cout<<"NO";
return 0;
}
