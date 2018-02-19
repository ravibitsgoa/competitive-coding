#include<algorithm>
#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n, inp[10005], ans=0;
    cin>>n;
    for(int i=0; i<n; i++)
      cin>>inp[i];
    sort(inp, inp+n);
    for(int i=0; i<n-1; i++)
    { if(inp[i]!=inp[i+1])
        ans++;
    }
    if(inp[n-1]!=inp[n-2]) ans++;
    if(ans==0) ans=1;
    cout<<ans<<endl;
  }
return 0;
}
