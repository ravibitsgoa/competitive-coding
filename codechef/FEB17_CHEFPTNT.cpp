/*#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, m, x, k;
		cin>>n>>m>>x>>k;
		string s;
		cin>>s;
		int e=0, o=0;
		for(char c: s)
		{
			if(c=='O')
				o++;
			else
				e++;
		}
		for(int i=1; i<=m; i++)
		{
			if(i%2)
			{
				n-= min(x, o);
			}
			else
			{
				n-= min(x, e);
			}
		}
		if(n<=0)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}*/