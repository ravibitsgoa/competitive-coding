#include <iostream>
#include <cassert>
using namespace std;
/*int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int n, m, k;
	cin>>n>>m>>k;
	string mat[n];
	vector<vector<int> >graph(n*m);
	for(int i=0; i<n; i++)
		cin>>mat[i];
	int x1, x2, y1, y2;
	cin>>x1>>y1>>x2>>y2;
	
	for(int i=1; i<n; i++)
	{	for(int j=0; j<n; j++)
		{	if(mat[i][j]=='.' && j<n-1 && mat[i][j+1]=='.')
			{	graph[i*m + j].push_back(i*m + j+1);
				graph[i*m + j+1].push_back(i*m + j);
			}
			if(mat[i][j]=='.' && i<n-1 && mat[i+1][j]=='.')
			{	graph[i*m + j].push_back((i+1)*m + j);
				graph[(i+1)*m + j].push_back(i*m + j);
			}
			if(mat[i][j]=='#')
				assert(graph[i*m + j].size())==0;
		}
	}
	
	return 0;
}
*/