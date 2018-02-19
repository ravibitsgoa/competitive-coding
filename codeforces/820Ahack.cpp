#include<cstdio>
using namespace std;

int main()
{ int c, v0, v1, a, l;
  scanf("%d %d %d %d %d",&c,&v0,&v1,&a,&l);
  //int daysforv1= g((double)(v1 - v0) /a);
  //int direct =
  int i=0;
  if(c!=0)
  { i++;
    c-=v0;
    while(c>0)
    { v0+=a;
      if(v0>v1)
        v0=v1;
      if(l>v0)
        c+=v0;
      else
        c+=l;
      c-=v0;
      i++;
    }
  }
  printf("%d",i);
return 0;
}
