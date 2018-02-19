#include <iostream>
#include <vector>
using namespace std;
bool valid(vector<int> contest, int min, int max, int diff)
{	int sum=0;
	int mx=contest[0], mn=contest[0];
	for(int i: contest)
	{	sum += i;
		if(mx< i)
			mx = i;
		if(mn> i)
			mn =i;
	}	
	if(sum>=min && sum<=max && (mx - mn)>=diff)
		return true;
	return false;
}

int main()
{
	int n, l, r, x;
	cin >> n >> l >> r >> x;
	int c[n];
	for(int i=0; i<n; i++)
		cin >> c[i];
	
	int ways = 0;
	for(int i=0; i<(1<<n); i++)
	{	vector<int> contest;
		for(int j=0; j<n; j++)
		{	if(i&(1<<j))
				contest.push_back(c[j]);
		}
		if(contest.size()==0)
			continue;
		if(valid(contest, l, r, x))
			ways++;
	}
	cout << ways;
}