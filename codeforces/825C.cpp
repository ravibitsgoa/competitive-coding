#include<algorithm>
#include<iostream>
using namespace std;
int main()
{ long long n, k;
  cin>>n>>k;
  long long a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  sort(a, a+n);
  int ans=0;
  for(int i=0; i<n; i++)
  { while(a[i] > 2*k)
    { ans++;
      k*=2;
    }
    k=max(a[i], k);
  }
  cout<<ans;
  return 0;
}
