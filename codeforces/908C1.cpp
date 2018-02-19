#include <bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int n;
	double r;
	cin >> n >> r;
	int x[n];
	map<int, int> xval;
	for(int i=0; i<n; i++)
	{	cin>>x[i];
	}
	double y[n];
	y[0]= r;
	xval[x[0]] = 0;//index.
	for(int i=1; i<n; i++)
	{	int x1=0, x2=0;
		for(int j=x[i]; j>=x[i]-r; j--)
		{	auto iter =xval.find(j);
			if(iter!=xval.end() )
			{	x1 = iter->second;
				break;
			}
		}
		for(int j=x[i]+1; j<=x[i]+r; j++)
		{	auto iter =xval.find(j);
			if(iter!=xval.end())
			{	x2 = iter->second;
				break;
			}
		}
		if(x1==0 && x2==0)
		{	y[i]=r;
		}
		else 
		{	int xmin;
			if(x[i]-x1 < x[i]-x2)
				xmin = x1;
			else
				xmin = x2;
			int index = xval[xmin];
			y[i] = y[index] + sqrt(4*r*r - (xmin - x[i])*(xmin-x[i]));
		}
		xval[x[i]] = i;
	}
	for(int i=0; i<n; i++)
		cout << y[i]<<' ';
}