/*#include <iostream>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	int h[n];
	for(int i=0; i<n; i++)
		cin>>h[i];
	int q;
	cin>>q;
	int alive=n;
	while(q--)
	{
		int x, y;
		cin>>x>>y;
		for(int i=0, mul=1; mul < x; i++, mul<<=1)
		{	if(x&mul)//if ith bit is set.
			{
			
			}	
			if((i&x) == i && h[i]>0)
			{	h[i]-=y;
			}
			if(h[i]<=0)
				alive--;
		}
		cout << alive<<'\n';
	}
}*/