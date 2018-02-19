#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
long long int c(int n, int k)
{ if(k>(float)n/2)  return c(n, n-k);
  if(k<0) return 0;
  if(k==0)  return 1;
  long long int ans=1;
  int i=n, j=k;
  for(; i>=n+1-k && j>1; i--)
  {  ans*=i;
    if(ans%j==0)
    {  ans/=j; j--;}
  }
  for(; i>=n+1-k; i--)
    ans*=i;
  for(; j>1; j--)
    ans/=j;
  return ans;
}
long long int f(int n, int k, int a)
{ if(k<n || k>a*n) return 0;
  long long int sum=0;
  for(int i=0; i<=(float)(k-n)/a; i++)
  { if(i==0 || i%2==0)
      sum+=c(n,i)*c(k-a*i-1, n-1);
    else
      sum-=c(n,i)*c(k-a*i-1, n-1);
  }
  return sum;
}
int main()
{ int t;
  scanf("%d",&t);
  for(int i=1; i<=t; i++)
  { int h, s;
    scanf("%d%d",&h,&s);
    float max=0;
    while(s--)
    { int x, y, z=0;
      char c;
      scanf("%d%c%d%c",&x,&c,&y,&c);
      if(c!=' ' && c!='\n')
        scanf("%d",&z);
      if(c=='-')
        z=-z;
      float prob=0.0;
      for(int v=1; v<h; v++)
        prob+=f(x, v-z, y);
      prob/=pow(y,x);
      prob=1-prob;
      if(max<prob)
        max=prob;
    }
    printf("Case #%d: %f\n",i,max);
  }
return 0;
}
