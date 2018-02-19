#include<stdio.h>
long long int ch(int n, int c)
{ long long int ans=1;
  if(c==0 || n==c)
    return 1;
  if(c>n-c)
    c=n-c;
  int i=n-c+1, j=c;
  for(; i<=n && j>0; i++, j--)
  { ans*=i;
    ans/=j;
  }
  for(; i<=n; i++)
    ans*=i;
  for(; j>0; j--)
    ans/=j;
  return ans;
}
int main()
{ int t;
  scanf("%d",&t);
  while(t--)
  { int n, k;
    scanf("%d%d",&n,&k);
    printf("%lld\n",ch(n-1,k-1));
  }
return 0;
}
