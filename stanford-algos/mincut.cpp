#include<set>
#include<random>
#include<cstdio>
#include<map>
#include<cassert>
using namespace std;
#define V 200
int ver[V+1]={0};
map<int, multiset<int> > inp;

int mincut(int n)
{ while(n>2)
  { random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, V);
    //Selecting two verticies, uniformly at random, for merging.
    int x = dis(gen);
    int y = dis(gen);
    while(ver[x]==0)
      {x=dis(gen)%(V+1);} //printf("%d ",x);
    while(ver[y]==0 || y==x || inp[x].find(y)==inp[x].end())
      {y=dis(gen)%(V+1);} //printf("%d\n",y);

    if(inp[x].size() <= inp[y].size())           //Now, x has strictly bigger degree than y.
      swap(x, y);

    inp[x].insert(inp[y].begin(), inp[y].end()); //merging the two lists.

    //Joining x with all verticies that were joined to y, and breaking their edges with y.
    for(auto iter=inp[y].begin(); iter!=inp[y].end(); iter++)
    { if(*iter == x)
        continue;
      inp[*iter].insert(x);
      auto it=inp[*iter].find(y); //Remove all edges with y, from all verticies joined with it.
      while(it!=inp[*iter].end())
      { inp[*iter].erase(it);
        it=inp[*iter].find(y);
      }
    }

    auto it=inp[x].find(x);                     //Removing self loops.
    while(it!=inp[x].end())
    { inp[x].erase(it);
      it=inp[x].find(x);
    }
    it=inp[x].find(y);
    while(it!=inp[x].end())
    { inp[x].erase(it);
      it=inp[x].find(y);
    }

    ver[y]=0; n--;                              //removed vertex y.
    //inp.erase(inp.find(y));
  }
  int i=1, ans=0; //Finding the first vertex that is remaining.
  for(; i<(V+1); i++)
  { if(ver[i]) break;
  }
  ans=inp[i].size();
  for(i++; i<(V+1); i++)  //Finding the second vertex that is remaining.
  { if(ver[i]!=0) break;
  }
  assert(ans==inp[i].size()); //If they don't have same degree, something has gone wrong.
  return ans;
}

int main()
{ map<int, multiset<int> > original_input;
  for(int i=1; i<=V; i++)
  { int x;
    scanf("%d",&x);
    assert(x==i);
    for(int j=1; j<=V; j++)
    { int x;
      scanf("%d", &x);
      if(x==0)  {break;}
      else      {original_input[i].insert(x);}
    }
  }             //inputted into the master copy.

  int ans=3000;
  for(int a=0; a<V*V; a++)                  //To run Karger's algorithm V^2 times.
  { inp= original_input;                    //copying the input.
    for(int i=1; i<=V; i++) ver[i]=1;
    int n=V, x;
    x=mincut(n);
    //printf("\n%d\n",x);
    ans=min(ans, x);
  }
  printf("%d",ans);
  return 0;
}
