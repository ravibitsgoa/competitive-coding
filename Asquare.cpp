#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  for(int i=1; i<=t; i++)
  { int r, c;
    cin>>r>>c;
    long long int ans=0;
    /*r--; c--;
    while(r>=1 && c>=1)
    { ans+=r*c;
      r--;
      c--;
    }*/
    r--; c--;
    int m=max(r,c),n=min(r,c);
    ans=n*(n-1)*(n-2)*n/12;
    m-=n;
    ans+=n*(n+1)*(2*n + 3*m +1)/6;
    cout<<"Case #"<<i<<": "<<ans<<endl;
  }

}
