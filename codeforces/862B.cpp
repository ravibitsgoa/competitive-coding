/*#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
	int n, m;
	cin>>n>>m;
	vector<pair<int, int> > pairs(m);
	int chhe =1;
	
	if(m==0 && n!=1)
	{	cout<<-1;
		return 0;
	}
	else if(m==0)
	{	cout<<1;
		return 0;
	}
	
	for(int i=0; i<m; i++)
	{	int k, f;
		cin>>k>>f;
		pairs[i] = {k, f};
		if(k==1 && f!=1)
			chhe=0;
	}
	
	sort(pairs.begin(), pairs.end());
	int fin_alpha=0;
	for(int alpha =1; alpha<=1000; alpha++)
	{	int valid=1;
		for(int i=0; i<m; i++)
		{	int k=pairs[i].first, f= pairs[i].second;
			if(k%alpha == 0 && (k/ alpha != f))
			{	valid=0;
				break;
			}
			else if(k%alpha!=0 && (k/ alpha) != (f -1))
			{	valid=0;
				break;
				//cout<<pairs[i].first<<' '<<alpha<<' '<<pairs[i].second<<endl;
			}
		}
		if(valid && !fin_alpha)
			fin_alpha = alpha;
		else if(valid && fin_alpha)
		{	fin_alpha = -1;
			//break;
			//cout<<alpha;
		}
	}
	//cout<<fin_alpha;
	if(fin_alpha <=0 || chhe==0)
		cout<<-1;
	else if(n%fin_alpha == 0)
		cout<<n/fin_alpha;
	else
		cout<<(n/fin_alpha) + 1;
	return 0;
}*/