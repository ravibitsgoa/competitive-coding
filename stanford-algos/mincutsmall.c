#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using std::cout;

int mincut(int ver[], int inp[][5], int &n);
int main()
{
  cout<<'b';
  int v[5]={0,1,1,1,1},in[5][5]={{0,0,0,0},{1,2,3,0},{2,1,3,4},{3,1,4,2},{4,2,3,0}}, i=4;
  //for(i=1; i<5; i++) {v[i]=1;}
  /*for(i=1; i<5; i++)
  { scanf("%d",&in[i][0]);
    for(int j=1; j<5; j++)
    { int x;
      scanf("%d", &x);
      if(x==0){break;}
      else {in[i][j]=x;}
    }
  }*/
  /*for(int i=1; i<5; i++)
  { for(int j=0; j<5; j++)
      cout<<in[i][j]<<' ';
    cout<<endl;
  }*/
  cout<<mincut(v, in, i);
  return 0;
}
int mincut(int ver[], int inp[][5], int &n)
{
  cout<<"hello";
  if(n>2)
  { int graph[5][5], x=rand()%5, y=rand()%5;
    while(ver[x]==0)         {x=rand()%5;} cout<<x;
    while(ver[y]==0 || y==x) {y=rand()%5;}
    graph[x][0]=inp[x][0];
    for(int i=1, j=1, k=1; inp[x][i]||inp[y][j]; k++)
    { if(inp[x][i]!=0 && inp[x][i]<=inp[y][j] && inp[x][i]!=y)
      { graph[x][k]=inp[x][i]; i++;
      }
      else if(inp[y][j]!=0 && inp[y][j]<inp[x][j] && graph[x][k-1]!=inp[y][j])
      { graph[x][k]=inp[y][j]; j++;
      }
    }//merging the two lists.
    ver[y]=0; n--;//removed vertex y.
    //now, copying the rest of the graph.
    for(int i=1; i<5; i++)
    { if(i==x || i==y) {continue;}
      for(int j=0; inp[i][j]; j++)
      { graph[i][j]=inp[i][j]; cout<<graph[i][j]<<' ';
      }
      cout<<endl;
    }

    printf("a");
    return 5;
    //return mincut(ver, graph, n);
  }
  if(n==2)
  { int i=1, j, ans=0;
    for(; i<5; i++)
    { if(ver[i]!=0) break;
    }
    for(j=1; inp[i][j]; j++)
    { ans++;
    }
    return ans;
  }
}
