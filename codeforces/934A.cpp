#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin>>n>>m;
	vector<long long> a(n), b(m);
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<m; i++)
		cin>>b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long mx=a[0]*b[0], index=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(mx < a[i]*b[j])
			{
				mx = a[i]*b[j];
				index = i;
			}
		}
	}
	
	a.erase(a.begin() + index);
	mx=a[0]*b[0];
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(mx < a[i]*b[j])
			{
				mx = a[i]*b[j];
			}
		}
	}
	cout << mx;
}*/