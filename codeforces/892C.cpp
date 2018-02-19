#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int n, c=0;
	cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; ++i)
	{	cin>>a[i];
		if(a[i] == 1)
			c++;
	}
	int ans= n*n;
	if(c>0)
		ans = n-c;
	int g = a[0];
	for(int i=0; i<n; i++)
		g = __gcd(a[i], g);
	if(g!=1)
	{	cout << -1;
		return 0;
	}
	
	for(int start=0; start<n; start++)
	{
		vector <int> b= a;
		for(int j=start+1; j<n; j++)
		{	if(b[j] == 1)
				ans = min(ans, j-start+n-1);
			b[j] = __gcd(b[j], b[j-1]);
			if(b[j] == 1)
				ans = min(ans, j-start+n-1);
		}
		for(int j=start-1; j>=0; j--)
		{	if(b[j] == 1)
				ans = min(ans, start-j+n-1);
			b[j] = __gcd(b[j], b[j+1]);
			if(b[j] == 1)
				ans = min(ans, start-j+n-1);
		}
	}
	cout << ans;
	return 0;
}