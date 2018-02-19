#include<algorithm>
#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n, total;
    cin>>n>>total;
    int a[n], sum[n]={0};
    for(int i=0; i<n; i++)
    { cin>>a[i];
      if(i>0)
        sum[i]=sum[i-1]+a[i];
      else
        sum[0]=a[0];
    }
    auto iter0=upper_bound(sum, sum+n, total);
    int ans=(int)(iter0-sum);
    for(int i=1; i<n; i++)
    { auto iter= upper_bound(sum+i, sum+n, total+sum[i-1]);
      int index=iter-sum;
      if(iter!=sum + n)
      { ans=max(ans, index-i);
      }
      else
      { iter--;
        auto iter1=upper_bound(sum, sum+n, total-(*iter-sum[i-1]));
        if(iter1<sum+i)
        { int ind=iter1-sum;
          ans=max(ans, ind + n-i);
        }
        else
          ans=n;
      }
    }
    cout<<ans<<'\n';
  }
return 0;
}
