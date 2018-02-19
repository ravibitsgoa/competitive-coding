#include<algorithm>
#include<iostream>
using namespace std;
int main()
{ ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    int a[2*n], acopy[2*n];
    for(int i=0; i<2*n; i++)
    { cin>>a[i];
    }
    sort(a, a+2*n);
    
    for(int i=0; i<n; i++)
      acopy[2*i]=a[i];
    for(int i=n; i<2*n; i++)
      acopy[1+(2*(i-n))]=a[i];
    cout<<acopy[n]<<'\n';
    for(int i=0; i<2*n; i++)
      cout<<acopy[i]<<' ';
    cout<<'\n';
  }
  return 0;
}
