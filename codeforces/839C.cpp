#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{   int n;
    scanf("%d",&n);
    vector<int> graph[n+1];
    for(int i=0; i<n-1; i++)
    {   int x, y;
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int start;
    int V=n;
    int explored[V+1]={0};    //All nodes are initially unexplored.
    int depth[V+1]={0};       //Starting node is in layer 0.
    long double fun[V+1]={0};
    queue<int> Q;             //Insert starting node in the queue.

    start=1;
    explored[start]=1;        //Mark start vertex as explored.
    Q.push(start);
    depth[start]=0;
    fun[start]=1.00;
    vector<int> leafs;
    while(!Q.empty())         //Until Q is non-empty, explore the top node.
    {   int i=Q.front();
        //printf("%d ",i);
        Q.pop();
        int child=0;
        for(int x: graph[i])    //Explore all nodes adjacent to current node.
        {   if(!explored[x])      //If x node has not been explored yet, insert it into the queue.
            {   //explored[x]=1;
                Q.push(x);
                depth[x]=depth[i]+1;
                child++;
            }
        }
        for(int x: graph[i])
        {   if(!explored[x])
            {   fun[x]=fun[i]/(double)child;
                explored[x]=1;
            }
        }
        if(child==0)
            leafs.push_back(i);
    }
    long double ans=0;
    for(int i : leafs)
    {   ans+=depth[i]*fun[i];
    }
    printf("%Lf",ans);
    return 0;
}
