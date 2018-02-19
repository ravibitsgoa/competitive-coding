#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n, flag=0, a, ans=0;
    cin>>n;
    while(n--)
    { cin>>a;
      if(a==0 && flag==0)
      { flag=1; ans+=100*(n+1) + 1000;
      }
      else if(a==0)
        ans+=1000;
    }
    cout<<ans<<endl;
  }
  return 0;
}
