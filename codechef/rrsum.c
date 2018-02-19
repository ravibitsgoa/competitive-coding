#include<stdio.h>
int abs(int x)
{ if(x<0) x=-x;
return x;
}
int main()
{ int n, m;
  scanf("%d %d",&n,&m);
  while(m--)
  { int q, ans;
    scanf("%d",&q);
    //ans=n-abs(q-2*n-1);
    if(q<n+2) printf("0");
    else if(q<=2*n + 1) printf("%d",q-n-1);
    else printf("%d",3*n+1-q);
    printf("\n");
  }
return 0;
}
