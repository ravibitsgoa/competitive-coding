#include <cassert>
#include <iostream>
using namespace std;
/*int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int k;
	cin>>k;
	if(k>36)
		cout << -1;
	else
	{
		long long n=0;
		while(k>=2)
		{	n*= 10;
			n+= 8;
			k-=2;
		}
		if(k==1)
		{	n*=10;
			n+= 4;
			k--;
		}
		assert(k == 0);
		if(n <= 1e18)
			cout << n;
		else
			cout << -1;
	}
}*/