#include<cstdio>
#include<iostream>
using namespace std;
int main()
{ int n, m;
  scanf("%d %d",&n,&m);
  long long int arr[n], &sum[n];
  sum[0]=0;
  for(int i=1; i<=n; i++)
  {  scanf("%lld",&arr[i]); sum[i]=sum[i-1]+arr[i];
  }
  for(int i=0; i<m; i++)
  { int q, x;
    long long int y;
    scanf("%d",&q);
    if(q==1)
    { scanf("%d %lld",&x,&y); arr[x]=y;
      cout<<sum[i]<<' '<<sum[i-1];
      //for(int j=x; j<n+1; j++) sum[j]+=y;
    }
    else if(q==2)
    { scanf("%d",&x); long long int j;
      for(j=1; j<=n; j++)
      { if(sum[j]==x) {printf("Found %lld\n",j); break;}
      }
      if(j==n+1) printf("Not Found\n");
    }
  }
  return 0;
}
