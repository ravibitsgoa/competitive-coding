#include <iostream>
#include <algorithm>
using namespace std;
/*int main()
{
	//ios_base::sync_with_stdio(false);
	//cout.tie(nullptr);
	//cin.tie(nullptr);
	
	//precomputing Euler's totient function values for numbers upto 1000000.
	long long phi[1000005]={0};
	phi[1] = 1;
	phi[2] = 1;
	phi[3] = 2;
	for(int i=4; i<1000005; i++)
	{	for(int j=2; j*j <=i; j++)
		{	if(i%j == 0)
			{	int m = j, n= i/j;
				//cout<<i<<' '<<m<<' '<<n<<' '<<__gcd(m,n)<<endl;
				phi[i] = phi[m]*phi[n]*__gcd(m,n)/phi[__gcd(m,n)];
				break;
			}
		}
		if(phi[i] == 0)	//if i is a prime.
			phi[i] = i-1;
	}
	//for(int i=1; i<=100; i++)
		//cout<<i<<' '<<phi[i]<<'\n';
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		long long ans= 1;
		for(int i=1; (i*i)<=n; i++)
		{	if(n%i == 0)
			{	ans+= i*phi[i];
				if(i*i != n)
					ans+= (n/i)*phi[n/i];
			}
		}
		ans*= n;
		ans/=2;
		cout<<ans<<'\n';
	}
	return 0;
}*/