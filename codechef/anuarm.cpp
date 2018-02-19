#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n, m;
    cin>>n>>m;
    int mx=0, mn=n, x;
    while(m--)
    { cin>>x;
      if(x>mx)
        mx=x;
      if(x<mn)
        mn=x;
    }
    for(int i=0; i<n; i++)
      cout<<max(mx-i, i-mn)<<' ';
    cout<<endl;
  }
  return 0;
}
