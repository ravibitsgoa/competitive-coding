/*#include <iostream>
#include <queue>
using namespace std;

void recurse(int i, int j, const int n, const int m, vector<vector<int>> &dmin, const vector<vector<int> > &s)
{
	if(i<0 || i>=n || j<0 || j>=m)
		return;
	if(i+1 < n && s[i+1][j]!=-1 && dmin[i+1][j] < dmin[i][j]-1)
	{	dmin[i+1][j] = dmin[i][j]-1;
		recurse(i+1, j, n, m, dmin, s);
	}	
	
	if(i-1 >=0 && s[i-1][j]!=-1 && dmin[i-1][j] < dmin[i][j]-1)
	{	dmin[i-1][j] = dmin[i][j]-1;
		recurse(i-1, j, n, m, dmin, s);
	}	
	
	if(j+1 < m && s[i][j+1]!=-1 && dmin[i][j+1] < dmin[i][j]-1)
	{	dmin[i][j+1] = dmin[i][j]-1;
		recurse(i, j+1, n, m, dmin, s);
	}	
	
	if(j-1 >=0 && s[i][j-1]!=-1 && dmin[i][j-1] < dmin[i][j]-1)
	{	dmin[i][j-1] = dmin[i][j]-1;
		recurse(i, j-1, n, m, dmin, s);
	}	
	
}

void solve(const int n, const int m, const vector<vector<int> > &s)
{
	vector<vector<int> > dmin(n, vector<int>(m));
	const int inf = 1e8;
	//char ans[n][m];
	for(int i=0; i<n; i++)
	{	for(int j=0; j<m; j++)
		{	dmin[i][j] = -inf;
		}
	}
	
	queue<pair<int, int> > cells;
	for(int i=0; i<n; i++)
	{	for(int j=0; j<m; j++)
		{	if(s[i][j] > 0)
			{	cells.push({i, j});
				dmin[i][j]= s[i][j];
			}
		}
	}
	
	while(!cells.empty())
	{	pair<int, int> thisCell = cells.front();
		int i0=thisCell.first, j0=thisCell.second;
		recurse(i0, j0, n, m, dmin, s);
		cells.pop();
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			//cout << dmin[i][j]<<' ';
			if(s[i][j]==-1)
				cout << 'B';
			else if(dmin[i][j]>=0)
				cout << 'Y';
			else
				cout << 'N';
		}
		cout <<'\n';
	}
}

int main()
{
	int min=1;
	int t;
	cin>>t;
	while(t--)
	{
		int n, m;
		cin>>n>>m;
		vector<vector<int> > s(n, vector<int>(m, 0));
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin >> s[i][j];
			
		solve(n, m, s);
	}
}*/