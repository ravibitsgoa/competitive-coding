/*#include <iostream>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int h;
	cin>>h;
	int a[h+1];
	int amb=0, n=0;
	for(int i=0; i<=h; i++)
	{	cin >> a[i];
		n+=a[i];
		if(i>0 && a[i-1]>=2 && a[i]>=2 && !amb)
			amb=i;
	}	
	if(!amb)
		cout << "perfect";
	else
	{	cout << "ambiguous\n";
		int root=0;
		for(int lev=0; lev<=h; lev++)
		{	int nodes = a[lev];
			while(nodes--)
				cout << root<<' ';
			root+= a[lev];
		}
		cout << '\n';
		root=0;
		for(int lev=0; lev<=h; lev++)
		{	int nodes = a[lev];
			if(lev== amb)
			{	cout << root-1 <<' ';
				nodes--;
			}
			while(nodes--)
				cout << root<<' ';
			root+= a[lev];
		}
	}
}*/