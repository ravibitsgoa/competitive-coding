#include<stdio.h>
int main()
{ int n=1;
  while(n)
  { scanf("%d",&n);
    if(n==0) break;
    int inp[n+1], i, flag=0;
    for(i=1; i<=n; i++)
    { scanf("%d",&inp[i]);
      if(inp[i]==i) {}
      else if(i>n/2 && inp[inp[i]]!=i) flag=1;
    }
    if(flag) printf("not ambiguous\n");
    else printf("ambiguous\n");
  }
return 0;
}
