#include<stdio.h>
int main()
{	int t, i, x, y, n;
  scanf("%d",&t);
	while(t--)
  { scanf("%d", &n);
    int a;
    scanf("%d",&x);scanf("%d",&y);
    n-=2;
    if(y<x) {int t=x; x=y; y=t;}
    while(n--)
    { scanf("%d", &a);
      if(a<x) {y=x; x=a;}
      else if(a<y) {y=a;}
    }
    printf("%d\n", x+y);
  }
	return 0;
}
