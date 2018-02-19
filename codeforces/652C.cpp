#include <vector>
#include <set>
#include <iostream>
using namespace std;/*
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int perm[n];
	for(int i=0; i<n; i++)
		cin >> perm[i];
	
	vector<int> foe[n+1];
	
	for(int i=0; i<m; i++)
	{	int x, y;
		cin >> x >> y;
		foe[x].push_back(y);
		foe[y].push_back(x);		
	}
	
	int this_interval[n+1]={0};
	long long ans=0, start=0;
	for(int i=0; i<n; i++)
	{	if(this_interval[perm[i]] == 0)
		{
		}
		else
		{	int j;
			for(j=start; j<i && this_interval[perm[i]]>0; j++)
			{	for(int node: foe[perm[j]])
					this_interval[node]--;
			}
			long long sz= i-start;
			start = j;
			ans += sz*(sz-1)/2;
			//cout << i<< ' ' << ans<<endl;
		}
		for(int node: foe[perm[i]])
			this_interval[node]++;
	}
	long long sz = n-start;
	ans += sz*(sz-1)/2;
	ans += n;
	cout << ans;
}*/