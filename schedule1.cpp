#include<bits/stdc++.h>
using namespace std;
int main()
{ int t;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>t;
  while(t--)
  { int n, k;
    cin>>n>>k;
    string x;
    cin>>x;
    int i=0, j=0;
    while(k--)
    { int lenmax=0, imax=0;
      if(j==n)
      { i=0;
        j=0;
      }
      while(j<n)
      { if(x[i]==x[j])
          j++;
        else
        { if(j-i>lenmax)
          { lenmax=j-i;
            imax=i;
          }
          i=j;
        }
      }
      if(j==n && x[j-1]==x[i] && j-i>lenmax)
      { lenmax=j-i;
        imax=i;
      }
      if(lenmax==1)
        break;
      if(x[imax+ (lenmax)/2]=='1')
        x[imax+ (lenmax)/2]='0';
      else
        x[imax+ (lenmax)/2]='1';
      //x[imax+ (lenmax)/2]=!x[imax+ (lenmax)/2];
      //cout<<lenmax<<endl;
    }
    int ans=0; i=0; j=0;
    while(j<n)
    { if(x[i]==x[j])
        j++;
      else
      { ans=max(ans,j-i);
        i=j;
      }
    }
    if(j==n && x[j-1]==x[i] )
    { ans=max(ans,j-i);
    }
    cout<<ans<<'\n';
  }
return 0;
}
