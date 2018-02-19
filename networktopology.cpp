#include <iostream>
#include <vector>
using namespace std;
int main()
{ int n, m, x, y;
  cin>>n>>m;
  vector<int> graph[n+1];
  for(int i=0; i<m; i++)
  { cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  int ones=0, twos=0, centre=0;
  x=y=0;
  //This part counts the number of nodes of the graph joint with 1, 2 or multi nodes.
  for(int i=1; i<=n; i++)
  { if(graph[i].size()==1)
      ones++;
    else if(graph[i].size()==2)
      twos++;
    else
      centre++;
    if(graph[i].size()==1 && x==0)
      x=i;
    else if(graph[i].size()==1 && y==0)
      y=i;
  }

  bool explored[n+1];
  int ex=0;

  if(ones==2 && twos+ones==n)//This is either a line or unknown.
  { explored[x]=1;
    explored[graph[x][0]]=1;
    ex=2;
    int i;
    for(i=graph[x][0];  ex<n && i!=y; )
    { if(graph[i].size()==2 && explored[graph[i][0]]==0)
      { explored[graph[i][0]]=1;
        ex++;
        i=graph[i][0];
      }
      else if(graph[i].size()==2 && explored[graph[i][1]]==0)
      { explored[graph[i][1]]=1;
        ex++;
        i=graph[i][1];
      }
      else
        break;
    }
    if(i==y && ex==n)
      cout<<"line topology";
    else
      cout<<"unknown topology";
  }

  else if(ones==0 && twos==n)//This graph is either a ring or unknown.
  { explored[1]=1;
    explored[graph[1][0]]=1;
    ex=2;
    int i;
    //cout<<x;
    for(i=graph[1][0];  ex<n && i!=1; )
    { //cout<<i;
      if(graph[i].size()==2 && explored[graph[i][0]]==0)
      { explored[graph[i][0]]=1;
        ex++;
        i=graph[i][0];
        //cout<<'a';
      }
      else if(graph[i].size()==2 && explored[graph[i][1]]==0)
      { explored[graph[i][1]]=1;
        ex++;
        i=graph[i][1];
      }
      else
        break;
    }
    if(i==graph[1][1] && ex==n)
      cout<<"ring topology";
    else
      cout<<"unknown topology";
  }

  else if(ones==n-1 && centre==1)//This graph must be a star one.
    cout<<"star topology";
  else
    cout<<"unknown topology";
return 0;
}
