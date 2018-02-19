#include<time.h>
#include<stdlib.h>
#include<stdio.h>
int mincut(int (&ver)[201], int (&inp)[201][2500], int n)
{ if(n>2)
  { srand(time(NULL));
    int x=random()%201, y=random()%201;
    while(ver[x]==0)         {x=random()%201;} //printf("%d ",x);
    while(ver[y]==0 || y==x) {y=random()%201;} //printf("%d\n",y);
    int i=1, j=1, k=1;
    while(inp[x][i]!=0 && i<2500)
    { i++;
    }
    while(inp[y][j]!=0 && j<2500)
    { if(inp[y][j]!=x)
      { inp[x][i]=inp[y][j];  i++; }
      inp[y][j]=0;
      j++;
    }
    //merging the two lists.
    ver[y]=0; n--;//removed vertex y.
    inp[y][0]=0;
    //now, copying the rest of the graph.
    return mincut(ver, inp, n);
  }
  if(n==2)
  { int i=1, j, ans=0;
    for(; i<201; i++)
    { if(ver[i]!=0) break;
    }
    for(j=1; inp[i][j]!=0; j++)
    { ans++;
    }
    return ans;
  }
}
int main()
{ int v[201], in[201][2500];
  for(int i=1; i<201; i++)
  {v[i]=1;}
  for(int i=1; i<201; i++)
  { scanf("%d",&in[i][0]);
    for(int j=1; j<201; j++)
    { int x1;
      scanf("%d", &x1);
      if(x1==0){break;}
      else {in[i][j]=x1;}
    }
  }//input into the master copy.

  int x1, i, j, a, n=200, an=3000, v1[201], in1[201][2500];
  for(a=0; a<10000; a++)
  { n=200;
    for(i=1; i<201; i++)
    { v1[i]=v[i];
      for(j=0; in[i][j]!=0 && j<201; j++)
      { in1[i][j]=in[i][j];
      } //printf("h");
    }//copying into new array.
    x1=mincut(v1, in1, 200);
    if(an>x1){an=x1;}
  }
  printf("%d",an);
  return 0;
}
