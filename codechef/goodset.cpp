#include<map>
#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    int ans[n];
    map<int, bool> sums;
    sums[1]=1;
    ans[0]=1;
    for(int i=1; i<n; i++)
    { for(int j=1; j<=500; j++)
      { if(sums[j]==0)
        { sums[j]=1;
          for(int k=0; k<i; k++)
          { sums[j+ans[k]]=1;
          }
          ans[i]=j;
          break;
        }
      }
    }
    for(int i=0; i<n; i++)
      cout<<ans[i]<<' ';
    cout<<'\n';
  }
return 0;
}
