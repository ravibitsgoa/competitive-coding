#include <set>
#include <iostream>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--)
	{
		int n, a, b, c;
		cin>> n >> a>> b>>c;
		long long ans=0;
		
		set<int> factor_n;
		for(int i=1; i*i<=n; i++)
		{
			if(n%i == 0)
			{	factor_n.insert(i);
				factor_n.insert(n/i);
			}
		}
		
		for(int i : factor_n)
		{
			if( i> a)
				break;
				
			int prod = n/i;
			//int sqrt_prod = sqrt(prod);
			set<int> factors;
			for(int j=1; j*j<=prod; j++)
			{
				if(prod%j == 0)
				{	factors.insert(j);
					factors.insert(prod/j);
				}
			}
				
			for(int j : factors)
			{
				if(j > b)
					break;
				int div = prod/j;
				if(div <= c)
					ans++;
			}
		}
		cout << ans << '\n';
	}
}