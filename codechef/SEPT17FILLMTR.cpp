/**My editorial: the array can be thought of as a graph, with weight of edge (i,j) being difference (X).
 * Now, given that we will not have any difference more than 1, we can represent each node
 * only by its pairity. (0 or 1, which will be its coordinate%2).
 * So, we shall do BFS on the graph, and will assign a random pairity to first node of each connected component.
 * After that, pairity of node j adjacent to i will be pairity(i) xor edgeWeight. 
 * If a node is already explored, and doesn't satisfy this property, we halt and print NO.
 * else we print YES.
 * */
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N, Q;
		cin>>N>>Q;
		vector<int> arr(N+1, -1);
        vector<vector<pair<int, int> > > graph(N+1);
		bool ans= false;
		while(Q--)
		{	int i, j, x;
			cin>>i>>j>>x;
			if(i==j and x)
				ans = 1;
			else
			{	graph[i].push_back({j, x});
                graph[j].push_back({i, x});
			}
		}
		arr[1]=0;
		queue<int> bfsFrontier;
		vector<int> explored(N+1, 0);
		int exploredCount=0;
        //We will do BFS.
		for(int i=1; i<=N && ans==false; i++)
		{	if(!explored[i])
			{	bfsFrontier.push(i);
				explored[i]=1;
				exploredCount++;
				arr[i] = 0;//just randomly giving 0 as it's a new SCC.
				while(bfsFrontier.empty()==false and ans==false)
				{	int temp = bfsFrontier.front();
					for(pair<int, int> node : graph[temp])
					{	if(!explored[node.first])
						{	bfsFrontier.push(node.first);
							explored[node.first]=1;
							exploredCount++;
						}
						if(arr[node.first]==-1)
						{	//if(node.second== 0)
								//arr[node.first] = node.second;
							//else
								//arr[node.first] = !node.second;
							arr[node.first] = node.second ^ arr[temp];
						}
						else if(arr[node.first] != (node.second ^ arr[temp]))
						{	//cout<<temp<<' '<<node.first<<' '<<node.second<<' '<<arr[node.first]<<' '<<arr[temp];
							ans = true;
							break;
						}
					}
					bfsFrontier.pop();
				}
			}
		}
		if(ans)
			cout<<"no\n";
		else
			cout<<"yes\n";
	}
	return 0;
}
