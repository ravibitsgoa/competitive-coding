#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    int inp[n];
    for(int i=0; i<n; i++)
      cin>>inp[i];
    bool ans=true;
    for(int i=0; i<n; i++)
    { for(int j=i+2; j<n; j++)
      { if(inp[i]>inp[j])
          ans=false;
      }
    }
    if(ans)
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
return 0;
}
