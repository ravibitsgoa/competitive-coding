#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	cin>>n>>m;
	string names[n];
	for(int i=0; i<n; i++)
		cin >> names[i];		
	
	set<pair<string, string> > pairs;
	for(int i=0; i<m; i++)
	{	string x, y;
		cin >> x >> y;
		pairs.insert({x, y});
	}
	int num_people=-1;
	vector<string> best_team={};
	for(int i=0; i<(1<<n); i++)
	{	int thissize= __builtin_popcount(i);
		if(thissize <= num_people)
			continue;
		vector<string> team;
		int valid = 1;
		for(int j=0; j<n; j++)
		{	if(i & (1<<j))
			{	team.push_back(names[j]);		
			}
		}
		for(int j=0; j<thissize; j++)
		{	for(int k=0; k<thissize; k++)
			{	if(pairs.find({team[j], team[k]}) != pairs.end())
					valid=0;
			}
		}
		if(valid)
		{	num_people= thissize;
			best_team = team;
		}
	}
	cout << num_people << '\n';
	sort(best_team.begin(), best_team.end());
	for(string s: best_team)
		cout << s << '\n';
}