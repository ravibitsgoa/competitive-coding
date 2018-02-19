#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { long long n, k;
    cin>>n>>k;
    long long a[n], b[n];
    for(long long i=0; i<n; i++)
      cin>>a[i];
    for(long long i=0; i<n; i++)
      cin>>b[i];
    long long sum=0, maxsum=0;
    for(long long i=0; i<n; i++)
    { sum=b[i]*(long long)(k/a[i]);
      maxsum=max(maxsum, sum);
    }
    cout<<maxsum<<'\n';
  }
  return 0;
}
