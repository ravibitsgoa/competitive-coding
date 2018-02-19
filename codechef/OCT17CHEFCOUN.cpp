#include <iostream>
using namespace std;
long long MOD = 1ll<<32;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t;	
	cin>>t;
	while(t--)
	{	int n;
		cin>>n;
		long long xcount = 1, ycount = n-1;
		long long x, y;
		for(xcount = n-1; xcount>=1; xcount--)
		{	ycount = n-xcount;
			int a = xcount+1, b = ycount+1;
			y= ((1ll<<32) - ((1e5)*(a)) )/(ycount);
			if(y<0)
				y=1;
			x= ((1ll<<32) - (ycount*y)) / a;
			while(x>1e5 && x>y)	//This is a hack to remove x > 1e5. Only God knows its runtime bound. It's good if it stops! :P
			{	y++;
				x= ((1ll<<32) - (ycount*y)) / a;
			}
			if(x>y && ((a*x + ycount*y) % MOD) < ((xcount*x + b*y) %MOD))
				break;
		}
		for(int i=0; i<xcount; i++)
		{	cout<<x<<' ';
		}
		for(int i=0; i<ycount; i++)
		{	cout<<y<<' ';
		}
		cout<<'\n';
	}
}