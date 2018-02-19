#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, m, p;
	cin >> n >> m >> p;
	map<pair<int, int>, int> comm;
	for(int i=0; i<p; i++)
	{	int x, j;
		cin>> x>>j;
		comm[{x, j}]++;
	}
	for(int i=1; i<=n; i++)
	{	vector<int> row(m+1);
		for(int j=1; j<=m; j++)
		{	row[j] = j;
			if(comm.count({i, j}))
				row[j]+= comm[{i, j}];
		}
		long long ans=0;
		for(int j=m-1; j>=1; j--)
		{	if(row[j]<= row[j+1])
				ans += row[j+1] - row[j];
			else
			{	ans= -1;
				break;
			}
		}
		cout << ans << '\n';
	}
}