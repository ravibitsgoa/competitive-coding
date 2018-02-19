#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ string x,y;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>x>>y;
  int a=x.size(), b=y.size();
  if(a!=b)
    cout<<max(a,b);
  else if(x==y)
    cout<<-1;
  else
    cout<<a;
return 0;
}
