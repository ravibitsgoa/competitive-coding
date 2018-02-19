//This is a solution to question "Strings and graphs" from August long challenge 2017.
/*
editorial:
All we need is BFS on the graph to find numbers in the sequence.
invariant: ith node of array, with value v on it, has to have an edge towards all remaining elements of its own level,
and all elements of subsequent levels that come first.
*/
#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {   int n, m;
        scanf("%d %d",&n,&m);
        int a[n+1]={0}, level[n+1]={0}, out[n+1]={0};
        //a is value of ith node. level is level number. "out[i]" is out degree.
        pair<int, int> edges[m];    //storing graph as an adjency list.
        for(int i=0; i<m; i++)
            scanf("%d %d",&edges[i].first, &edges[i].second);
        sort(edges, edges+m);
        int count=1, i, stack=0;
        //count is the value of currently found pointed node. stack = number of elements currently on stack.
        for(i=0; i<m; i++)
        {   if(edges[i].first == 0)         //If current edge is from 0 to anything,
            {   a[edges[i].second]=count;   //Set its number to 'count'.
                level[edges[i].second]=1;   //As its being pointed by 0, level = 1
                count++;
                stack++;                    //push current node onto the stack.
            }
            else
                break;                      //As we run out of (0,v) edges, stop this loop.
        }
        count=1;
        int ans=0;
        //ans==0 means everything is fine, whereas 1 means current graph is not possible.
        for(; i<m; i++)
        {   if(edges[i-1].first!=0 && edges[i].first != edges[i-1].first)   //If we hit a new pointing node.
            {   count=a[edges[i].first];             //Value of first new node of next level will be value of current node.
                //^-> explanation: If we have any new node with value less than current node, it must have already been discovered.
                stack--;                             //Remove last node off stack.
                if(out[edges[i-1].first] < stack)    //If out degree of last node was even less than stacked nodes, something is wrong.
                {   ans=1;
                }
            }
            if(a[edges[i].second]==0)               //If we discover a new node.
            {   a[edges[i].second]=count;           //Set its value.
                level[edges[i].second]=level[edges[i].first]+1; //and its level.
                stack++;                            //Add it onto the stack.

                if(count> a[edges[i].first])        //If we discover more than one new node, something is wrong with the graph.
                {   ans=1;
                }// necessary. don't mess with this.

                count++;
            }
            out[edges[i].first]++;
        }
        for(int i=1; i<=n; i++)
        {   if(!a[i])           //If ith node was never discovered.
            {   ans=1;
            }
        }
        if(ans)
        {   printf("-1\n");
            continue;
        }
        for(int i=1; i<=n; i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
