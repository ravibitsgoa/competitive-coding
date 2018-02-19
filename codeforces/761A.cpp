#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int x, y;
  cin>>x>>y;
  if(x-y <2 && x-y>-2)
    cout<<"YES";
  else
    cout<<"NO";
  return 0;
}
