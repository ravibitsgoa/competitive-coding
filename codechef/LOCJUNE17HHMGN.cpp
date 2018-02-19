#include<algorithm>
#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    long long s;
    cin>>n>>s;
    long long a[n], sum[n]={0};
    for(int i=0; i<n; i++)
    { cin>>a[i];
    }
    sort(a, a+n);
    int i;
    for(i=0; i<n; i++)
    { if(i>0)
        sum[i]=sum[i-1]+a[i];
      else
        sum[0]=a[0];
      if(sum[i]+ a[i]*(n-i-1) == s)
      { cout<<a[i]<<'\n';
        break;
      }
    }
    if(i==n)
      cout<<-1<<'\n';
  }
return 0;
}
