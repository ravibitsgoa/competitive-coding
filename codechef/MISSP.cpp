#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    int inp, ans;
    cin>>inp;
    ans=inp;
    n--;
    while(n--)
    { cin>>inp;
      ans^=inp;
    }
    cout<<ans<<'\n';
  }
  return 0;
}
