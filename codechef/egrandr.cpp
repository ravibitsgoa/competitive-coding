#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    int a, fail=0, full=0, sum=0;
    for(int i=0; i<n; i++)
    { cin>>a;
      if(a==2)
        fail=1;
      else if(a==5)
        full=1;
      sum+=a;
    }
    if(sum>=4*n && full && !fail)
      cout<<"Yes\n";
    else
      cout<<"No\n";
  }
  return 0;
}
