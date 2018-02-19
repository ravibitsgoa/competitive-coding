#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
	int frogs, pairs, maxd;
	cin>>frogs>>maxd>>pairs;
	vector<pair<int, int> > coord_index(frogs);
	for(int i=0; i<frogs; i++)
	{	int x;
		cin>>x;
		coord_index[i]={x, i+1};		
	}
	sort(coord_index.begin(), coord_index.end());
	map<int, int> component_num;
	component_num[coord_index[0].second] = 1;
	for(int i=1; i<frogs; i++)
	{	component_num[coord_index[i].second]=component_num[coord_index[i-1].second];
		if(coord_index[i-1].first < coord_index[i].first - maxd)
			component_num[coord_index[i].second]++;
	}
	while(pairs--)
	{	int a, b;
		cin>>a>>b;
		if(component_num[a]==component_num[b])
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}