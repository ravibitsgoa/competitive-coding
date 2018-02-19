#include <iostream>
using namespace std;

int main()
{
	
	const int N=1e6 +5;
	int phi[N];
	//precomputation:
	for(int i=1; i<=N; i++)
		phi[i]=i;

	for(int i=2; i<=N; i++)
	{	if(phi[i]==i)
		{	// This condition guarantees that i is prime since it was not modified by any number <i.
			for(int j=i; j<=N; j+=i)
				phi[j]-=(phi[j]/i);		// In this step we multiply (1-1/i) to each multiple of i, since it would be a prime factor in factorisation of all its multiples.
		}
		//Time Complexity:O(NlogN + T).
	}

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout << phi[n]<<'\n';
	}
}