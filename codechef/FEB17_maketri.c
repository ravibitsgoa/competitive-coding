#include<stdlib.h>
#include<stdio.h>
long long int ab(long long int x)
{ if(x<0) return -x;
  return x;
}
long long int a[1000005];
int main()
{ long long int n, l, r;
  scanf("%lld %lld %lld",&n,&l,&r);
  for(long long int i=0; i<n; i++)
    scanf("%lld",&a[i]);
  char *flag=(char*)malloc(sizeof(char)*(r+4));
  long long int ans=0;
  for(long long i=0; i<=r; i++)
    flag[i]='0';
  for(long long int i=0; i<n; i++)
  { for(long long int j=i+1; j<n; j++)
    { for(long long int k=ab(a[i]-a[j])+1; (k<=r) && (k<(a[i]+a[j])) ; k++)
      { if(k>=l && flag[k]=='0')
        {  ans++;
        }
        flag[k]='1';
      }
    }
  }

  printf("%lld",ans);
  return 0;
}
