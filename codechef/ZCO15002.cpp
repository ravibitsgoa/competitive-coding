#include<algorithm>
#include<iostream>
using namespace std;
int main()
{ long long n, k;
  cin>>n>>k;
  long long a[n];
  for(int i=0; i<n; i++)  cin>>a[i];
  sort(a, a+n);
  long long ans=n*(n-1)/2;
  for(int i=1; i<n; i++)
  { auto iter=upper_bound(a, a+n, a[i]-k);
    //auto j=upper_bound(a, a+n, a[i]+k);
    //cout<<iter-a<<' '<<i<<endl;
    ans -= i - (iter-a);
  }
  cout<<ans;
return 0;
}
