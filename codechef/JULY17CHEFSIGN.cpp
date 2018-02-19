#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXSIZE 100005
using namespace std;
int main()
{ int t;
  scanf("%d",&t);
  getchar();
  while(t--)
  { char x[MAXSIZE], ch;
    int n=0;
    ch=getchar();
    while(ch!=' ' && ch!='\n')
    { while(ch=='=')
        ch=getchar();
      if(ch=='\n')
        break;
      x[n]=ch;
      n++;
      ch=getchar();
    }
    if(n==0)
    { printf("1\n");
      continue;
    }
    int count=1, mx=2;
    for(int i=1; i<n; i++)
    { if(x[i]==x[i-1])
      { count++;
        mx=max(mx, 1+count);
      }
      else
      { mx=max(mx, 1+count);
        count=1;
      }
    }
    mx=max(mx, 1+count);
    printf("%d\n",mx);
  }
return 0;
}
