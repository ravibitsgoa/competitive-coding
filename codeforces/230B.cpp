#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	const int NMAX = 1e6 + 5;
	bool isprime[NMAX];
	isprime[1] = false;
	
	for(int i=2; i<NMAX; i++)
		isprime[i] = true;
	
	for(int i=2; i<NMAX; i++)
	{	if(isprime[i])
		{	for(int j=2*i; j<NMAX; j+=i)
			{	isprime[j] = false;
			}
		}
	}
	
	int n;
	cin>>n;
	long long a;
	for(int i=0; i<n; i++)
	{	cin>>a;
		long long sq = sqrt(a);
		if(a!=1 && sq*sq == a && isprime[sq])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
}