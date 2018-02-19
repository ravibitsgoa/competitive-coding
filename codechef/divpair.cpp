#include<cstdio>
using namespace std;
int main()
{ int t;
  scanf("%d",&t);
  while(t--)
  { int n, m;
    scanf("%d %d",&n,&m);
    int a=2/m, b=(2*n-1)/m;
    printf("%d\n",b-a);
  }
  return 0;
}
