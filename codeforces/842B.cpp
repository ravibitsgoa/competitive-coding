#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int r, d;
	cin>>r>>d;
	int n, ans=0;
	cin>>n;
	while(n--)
	{	double x, y, rsm;
		cin>>x>>y>>rsm;
		if(((x*x + y*y) >= (rsm + r-d)*(rsm + r-d)) && ((x*x + y*y) <= (-rsm + r)*(-rsm + r)))
			ans++;
	}
	cout<<ans;
	return 0;
}

