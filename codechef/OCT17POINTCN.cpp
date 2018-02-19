/*#include <cstdio>
#include <set>
#include <vector>
#include <utility>

const unsigned long long INFINITY = 1e17;
unsigned long long s[2];
unsigned long long xorshift128plus() {
	unsigned long long x = s[0];
	const unsigned long long y = s[1];
	x ^= x << 23;
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
	return s[0] = y;
}

const int MX = 1000;

int C[MX][MX];
int H[MX][MX];
char graph[MX][MX];

using namespace std;

int main() 
{
	int T;
	scanf("%d", &T);
	while(T--) 
	{
		for(int i=0; i<MX; i++)
			for(int j=0; j<MX; j++)
				graph[i][j]='0';
		
		int n, Cmax, Hmax;
		scanf("%d %d %d", &n, &Cmax, &Hmax);
		for (int i = 0; i < n; i++) 
		{	C[i][i] = 0;
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = i + 1; j < n; j++) 
			{	C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
			}
		}
		
		for (int i = 0; i < n; i++)
		{	scanf("%llu %llu", &s[0], &s[1]);
			for (int j = 0; j < n; j++)
			{	H[i][j] = xorshift128plus() % (Hmax + 1);
			}
		}
		{	int nodes=n;
			vector<vector<pair<int, int> > >adj_list(nodes+1);//adj_list[i]={edge_cost, node};
			for(int i=0; i<nodes; i++)
			{	for(int j=0; j<nodes; j++)
					adj_list[i].push_back({C[i][j], j});
			}

			vector<int> visited(nodes, 0);				
			set<pair<int, int> > min_weight_for_vertex;	
			vector<int> parent(nodes);					
			const int root=0;
			visited.at(root)=1;							//We mark the root node as visited.
			min_weight_for_vertex.insert({0, root});	//We push root into the heap, with distance from itself as 0.
			vector<int> min_cost(nodes);				//min_cost[i] = "known least cost edge to node i."

			while(!min_weight_for_vertex.empty())		//While heap is not empty.
			{ 	auto cheapest_node = min_weight_for_vertex.begin();
				int vert = cheapest_node->second;				//find the cheapest edge.
				min_weight_for_vertex.erase(cheapest_node);		//pop it from the heap.
				for(pair<int, int> p : adj_list.at(vert))	//for all vertices adjacent to vert.
				{	if(!visited.at(p.second))				//If we haven't processed this vertex so far.
					{	min_weight_for_vertex.insert(p);	//we push it into the heap.
						visited[p.second]=1;				//We mark it as visited. (just used in place of set.find() )
						min_cost.at(p.second)= p.first;		//minimum cost known for this vertex is W(vert, p).
						parent.at(p.second)= vert;			//node vert is the temporarily parent of node p, in proposed MST.
					}
					else if((p.first < min_cost.at(p.second)) and
					min_weight_for_vertex.find({min_cost.at(p.second), p.second}) != min_weight_for_vertex.end())	//If it's in the heap.
					{	parent.at(p.second) = vert;				//now, parent of p node is vert.
						min_weight_for_vertex.erase(min_weight_for_vertex.find({min_cost[p.second], p.second}));
						//remove old pair.
						min_cost[p.second] = p.first;			//minimum known cost of p, is W(vert, p).
						min_weight_for_vertex.insert(p);		//insert new pair.
					}
				}
			}

			long long sum_Of_MST=0;						//Sum of cost of all edges in the MST.
			for(int i=0; i<nodes; i++)					//We find MST cost like this, because each node has only 1 parent.
			{	if(i== root)
					continue;
				graph[i][parent[i]]='1';
				graph[parent[i]][i]='1';
				//MST[parent[i]].push_back(i);
				//MST[i].push_back(parent[i]);
				sum_Of_MST += min_cost[i];
				//cout<<i<<' '<<parent[i]<<' '<<min_cost[i]<<endl;	//To really print the MST.
			}
		}
		
		for(int i=0; i<n; i++)
		{	for(int j=0; j<n; j++)
			{	printf("%c", graph[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}*/