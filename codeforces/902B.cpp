/*#include <iostream>
#include <vector>
using namespace std;

const int VMAX = 1e4 +5;
int explored[VMAX+1]={0};     //All nodes are initially unexplored.

int DFS(int s, const vector<int> tree[], int parentCol, const int col[]) //start vertex s.
{ 
	//cout << s<<endl;
	explored[s]=1;
	int subtreeAns= 0;
	if(col[s] != parentCol)
		subtreeAns = 1;
	for(int x: tree[s])
	{	if(!explored[x])
			subtreeAns+= DFS(x, tree, col[s], col);
	}
	return subtreeAns;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	vector<int> adj[n+1];
	for(int i=2; i<=n; i++)
	{	int x;
		cin>>x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	int col[n+1];
	for(int i=0; i<n; i++)
		cin>>col[i+1];
	//cout << "hi";
	int ans=0;
	ans = DFS(1, adj, 0, col);
	cout << ans;
}*/