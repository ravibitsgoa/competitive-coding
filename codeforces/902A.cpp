/*#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin>>n>>m;
	int xmax = 0;
	for(int i=0; i<n; i++)
	{
		int x, len;
		cin>>x>>len;
		if(x<=xmax)
		{	//cout << x<<' '<<xmax<<endl;;
			xmax = max(len, xmax);
		}
	}
	if(xmax >= m)
		cout << "YES";
	else
		cout << "NO";
}*/