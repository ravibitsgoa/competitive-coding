#include<stdio.h>
int main()
{ int n, k;
  scanf("%d%d",&n,&k);
  int open[n+1], c=0;
  for(int i=0; i<n+1; i++)
    open[i]=0;
  while(k--)
  { char x[10]; int i;
    scanf("%s",x);
    if(x[2]=='I')
    { scanf("%d",&i);
      if(open[i]==0)
      {open[i]=1; c++;}
      else
      {open[i]=0; c--;}
    }
    else
    { for(int i=1; i<=n; i++)
      { open[i]=0;
      }
      c=0;
    }
    printf("%d\n",c);
  }
  return 0;
}
