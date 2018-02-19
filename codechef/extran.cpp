#include<bits/stdc++.h>
using namespace std;
int main()
{ int t;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    int inp[n];
    for(int i=0; i<n; i++)
      cin>>inp[i];
    sort(inp, inp+n);
    if(inp[1]!=inp[0]+1)
      cout<<inp[0]<<'\n';
    else if(inp[n-2]+1!=inp[n-1])
      cout<<inp[n-1]<<'\n';
    else
    { for(int i=0; i<n-1; i++)
      { if(inp[i]==inp[i+1])
        { cout<<inp[i]<<'\n';
          break;
        }
      }
    }
  }
  return 0;
}
