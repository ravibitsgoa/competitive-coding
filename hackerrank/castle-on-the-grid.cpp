#include <queue>
#include <iostream>
using namespace std;


int main() 
{
    int n;
    cin>>n;
    string s[n];
    for(int i=0; i<n; i++)
        cin >> s[i];
		
    int startX, startY, goalX, goalY;
    cin >> startX >> startY >> goalX >> goalY;
	int dmin[n][n], inf = 1e9;
	
	for(int i=0; i<n; i++)
	{	for(int j=0; j<n; j++)
			dmin[i][j] = inf;
	}
	
	queue<pair<int, int> > cells;
    cells.push({startX, startY});
	dmin[startX][startY]=0;
	while(!cells.empty())
	{	pair<int, int> thisCell = cells.front();
		int i0=thisCell.first, j0=thisCell.second;
		for(int i=i0-1; i>=0 && s[i][j0]!='X'; i--)
		{	if(dmin[i][j0] == inf)
				cells.push({i, j0});
			dmin[i][j0] = min(dmin[i][j0], dmin[i0][j0] + 1);
		}
		for(int i=i0+1; i<n && s[i][j0]!='X'; i++)
		{	if(dmin[i][j0] == inf)
				cells.push({i, j0});
			dmin[i][j0] = min(dmin[i][j0], dmin[i0][j0] + 1);
		}
		for(int j=j0-1; j>=0 && s[i0][j]!='X'; j--)
		{	if(dmin[i0][j] == inf)
				cells.push({i0, j});
			dmin[i0][j] = min(dmin[i0][j], dmin[i0][j0] + 1);
		}
		for(int j=j0+1; j<n && s[i0][j]!='X'; j++)
		{	if(dmin[i0][j] == inf)
				cells.push({i0, j});
			dmin[i0][j] = min(dmin[i0][j], dmin[i0][j0] + 1);
		}
		cells.pop();
	}
	cout << dmin[goalX][goalY];
}
