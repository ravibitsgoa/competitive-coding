#include<stdio.h>

long long int coins[10001];
long long int max(long long int a, long long int b)
{ if(a>=b)
    return a;
  return b;
}
long long int count(long long int n)
{ if(n<10001)
    return max(n, coins[n]);
  return max(n, count(n/2)+count(n/3)+count(n/4));
}
int main()
{ long long int n, i, x=-1;
  long long int ans[15];
  for(i=0; i<12; i++)
    coins[i]=(long long)i;
  for(i=12; i<10001; i++)
    coins[i]=max(i, coins[i/2] + coins[i/3] + coins[i/4]);
  scanf("%lld",&n);
  i=0;
  do
  { if(x==n)
      break;
    if(n<10001)
      //printf("%lld\n",coins[n]);
      ans[i]=coins[n];
    else
      //printf("%lld\n",count(n));
      ans[i]=count(n);
    i++;
    x=n;
  }
  while(scanf("%lld",&n) && i<11);
  int j;
  for(j=0; j<i; j++)
    printf("%lld\n",ans[j]);
return 0;
}
