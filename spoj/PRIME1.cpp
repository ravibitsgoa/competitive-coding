/*#include <iostream>
#include <algorithm>
using namespace std;

const int PRIME_MAX = 1e5;
bool isPrime[PRIME_MAX];
int primes[PRIME_MAX], numprimes=0;

void sieve (int n) {
	std::fill (isPrime, isPrime + n, true);
	for (int i = 2; i < n; ++i) {
		if (isPrime[i])
		{	primes[numprimes] = i; 
			numprimes++;
		}
		for (int j = 0; j < numprimes && i * primes[j] < n; ++j) 
		{	isPrime[i * primes[j]] = false;
			if (i % primes[j] == 0) break;
		}
	}
}
	
int main()
{
	sieve(PRIME_MAX);
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int t;
	cin>>t;
	while(t--)
	{
		int lower, upper;	//we have to print all primes in [lower, upper].
		cin >> lower >> upper;
		if(lower<PRIME_MAX)
		{	for(int i=lower; i<=upper && i<PRIME_MAX; i++)
			{	if(isPrime[i])
					cout << i<<'\n';
			}
			if(upper< PRIME_MAX)
			{	//cout << '\n';
				continue;
			}
			lower= PRIME_MAX;
		}
		
		bool isBigPrime[upper-lower+1];
		for(int i=0; i<=upper-lower; i++)
			isBigPrime[i]= true;
			
		for(int primeIndex=1; primeIndex < numprimes; primeIndex++)
		{	int p = primes[primeIndex];
			int start=((int)(lower/p))*p;
			for(int i=start; i<=upper; i+=p)
			{	if(i<lower)
					continue;
				isBigPrime[i-lower] = false;
			}
		}
		for(int i=0; i<=upper-lower; i++)
		{	if(((i+lower) &1) && isBigPrime[i])
				cout << i+lower << '\n';
		}
		//cout << '\n';
	}
}*/