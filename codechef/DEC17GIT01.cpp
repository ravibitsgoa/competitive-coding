#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, m;
		cin>>n>>m;
		string cake[n];
		for(int i=0; i<n; i++)
			cin>>cake[i];
		int ans1=0, ans2=0;
		for(int i=0; i<n; i++)
		{	for(int j=0; j<m; j++)
			{	if(((i+j) % 2))
				{	ans1+= 3*(cake[i][j]=='G');
					ans2+= 5*(cake[i][j]=='R');
				}
				else
				{	ans1+= 5*(cake[i][j]=='R');
					ans2+= 3*(cake[i][j]=='G');
				}
			}
		}
		cout << min(ans1, ans2)<<'\n';
	}
}