#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(int start, const vector<vector<int> > &graph)
{
	bool is_visited[graph.size()]={0};
	queue<pair<int, int> > visited;
	visited.push({start, 0});
	is_visited[start] = 1;
	while(!visited.empty())
	{
		int current = visited.front().first;
		for(int node: graph[current])
		{
			int dist = visited.front().second+1;
			if(node == start)
				return dist;
			if(!is_visited[node])
			{	visited.push({node, dist});
				is_visited[node] = true;
			}
		}
		visited.pop();
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int> > graph(n, vector<int>() );
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			int x;
			cin>>x;
			if(x)
				graph[i].push_back(j);
		}
	}
	for(int i=0; i<n; i++)
	{
		int dist = BFS(i, graph);
		if(dist != -1)
			cout << dist << '\n';
		else
			cout << "NO WAY\n";
	}
}