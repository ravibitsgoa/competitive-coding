#include<cstdio>
using namespace std;

int main()
{ int c, v0, v1, a, l;
  scanf("%d %d %d %d %d",&c,&v0,&v1,&a,&l);
  //int daysforv1= g((double)(v1 - v0) /a);
  //int direct =
  for(int i=1; 1; i++)
  { if(v0>v1)
      v0=v1;
    c-=v0;
    if(c<=0)
    { printf("%d",i);
      break;
    }
    v0+=a;
    c+=l;
  }
return 0;
}
