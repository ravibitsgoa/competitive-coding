#include<functional>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { long long int n, m, i=0;
    cin>>n>>m;
    long long int inp[n];
    for(; i<n; i++)
      cin>>inp[i];
    sort(inp, inp+n, greater<long long int>());
    long long int s=0;
    for(i=0; i<n && s<m; i++)
    {  s+=inp[i];
    }
    if(i==n && s<m) cout<<-1;
    else cout<<i;
    cout<<endl;
  }
  return 0;
}
