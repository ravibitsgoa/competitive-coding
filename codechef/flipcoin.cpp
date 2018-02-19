#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{ int n, q;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n>>q;
  int heads[n]={0}, side[n]={0};
  while(q--)
  { int a, x, y;
    cin>>a>>x>>y;
    if(a)
    { if(y+1<n)
        cout<<heads[y+1]-heads[x]<<'\n';
      else
        cout<<heads[y]+side[y]-heads[x]<<'\n';
    }
    else
    { for(int i=x; i<=y; i++)
      { side[i]=!side[i];
        if(i>0)
          heads[i]=heads[i-1]+side[i-1];
        //cout<<heads[i]<<' ';
      }
      //cout<<endl;
    }
  }
return 0;
}
