#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int abs(int x)
{ if(x<0)
    x=-x;
  return x;
}
int main()
{ ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  { int n, m, x;
    cin>>n>>m;
    int a[n][m];//we will directly compute C=A-B, in place.
    for(int i=0; i<n; i++)
    { for(int j=0; j<m; j++)
        cin>>a[i][j];
    }
    for(int i=0; i<n; i++)
    { for(int j=0; j<m; j++)
      { cin>>x;
        a[i][j]-=x;
      }
    }
    int sum=0;
    for(int i=0; i<n; i++)//finding minimas in rows, and subtracting them.
    { int mn=abs(a[i][0]), sign=(a[i][0]>=0);
      if(!sign) sign--;
      for(int j=0; j<m; j++)
      { if(abs(a[i][j])<mn)
        { mn=abs(a[i][j]);
          if(a[i][j]<0) sign=-1;
          else sign=1;
        }
      }
      sum+=mn;
      for(int j=0; j<m; j++)
      { a[i][j]-=sign*mn;
        if(i==0)
          sum+=abs(a[i][j]);
        //cout<<sum<<' '<<a[i][j]<<endl;
      }
    }
    int flag=1;
    for(int i=1; i<n; i++)
    { for(int j=0; j<n && flag; j++)
      { if(a[i][j]!=a[i-1][j])
          flag=0;
      }
    }
    if(flag)
      cout<<sum<<endl;
    else
      cout<<-1<<endl;
  }
return 0;
}
