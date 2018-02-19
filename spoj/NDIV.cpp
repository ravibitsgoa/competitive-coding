#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;


int main()
{
	const int PRIME_MAX = 1e5 + 5;
	bool isPrime[PRIME_MAX];
	int numFact[PRIME_MAX]={0};

	for(int i=1; i<PRIME_MAX; i++)
	{	isPrime[i]= true;
		numFact[i]= 2;	//1 and i always divide i.
	}
	numFact[1]=1;
	for(int i=2; i<PRIME_MAX; ++i)
	{	for(int j=2*i; j<PRIME_MAX; j+=i)
		{	numFact[j]++;
			isPrime[j]= false;
		}
	}

	int primes[PRIME_MAX];
	long long primeSquares[PRIME_MAX];
	int primeCount = 0;
	for(int i=2; i<PRIME_MAX; ++i)
	{	if(isPrime[i])
		{	primes[primeCount] = i;
			long long ill = i;
			primeSquares[primeCount] = (ill*ill);
			primeCount++;
		}
	}

	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int a, b, n, count=0;
	cin >> a >> b >> n;
	for(int i=a; i<=b; ++i)
	{
		int factI=0, x=1, y=1;
		for(int iter=0; iter<primeCount; ++iter)
		{	int j = primes[iter];
			long long jll= j;
			if(jll*jll*jll > i)
				break;
			int icopy = i;
			while(icopy%j == 0)
			{	icopy/=j;
				x*=j;
			}
		}
		y= i/x;
		//now, x contains only the prime factors upto N^1/3, and y contains the rest.
		//So, we already know number of factors of x.

		int factX, factY=2;
		if(x < PRIME_MAX)
			factX= numFact[x];
		else
		{	int j;
			factX=0;
			for(j=1; j*j < x; ++j)
			{	if(x%j==0)
					factX+=2;
			}
			if(j*j == x)
				factX++;
		}
		if(factX > n)
			continue;
		if(y==1)
		{	factY = 1;
		}
		else if(y<PRIME_MAX && isPrime[y])	//y is a small prime.
				factY = 2;
		else if(binary_search(primeSquares, primeSquares + primeCount, y))//y = p.p
		{
			factY = 3;
		}
		else
		{	bool f1=0, f2=0, h=0;
			for(int iter=0; iter<primeCount; ++iter)
			{	int j = primes[iter];
				long long jll= j;
				if(jll*jll > y)
					break;
				if(y%j == 0)
				{	if(!f1)
					{	f1=true;
						if(y% (jll*jll) ==0)
							h=true;
					}
					else if(!f2)
						f2=false;
					else
						assert(0);
				}
			}
			if(!f1 && !f2)			//y is a big prime.
				factY = 2;
			else if(f1 && !f2 && !h)//y is a small prime* big prime.
			{	factY= 4;
			}
			else if(f1 && !f2 && h)	//y is square of a small prime.
				factY = 3;
			else if(f1 && f2)		//y = p.q where p and q are small primes.
				factY = 4;
			else
				assert(0);
		}
		//assert(__gcd(x, y) == 1);
		factI = factX*factY;
		if(factI==n)
			++count;
	}
	cout << count;
}
