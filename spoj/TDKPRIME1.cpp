#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

const int NMAX = 86028125, SIZE= 5000000+10;
bitset<NMAX> is_composite;
long long primes[SIZE];
	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	primes[0] = 2;
	int prime_count=1;
	register long long i, j, inc;
	
	for(i=3; i<NMAX; i+=2)
	{	if(!is_composite[i])
		{	for(j=i*i, inc = 2*i; j<NMAX; j+=inc)
			{	is_composite[j] = true;
			}
			primes[prime_count++]=i;
		}
		if(prime_count >= SIZE)
			break;
	}
	
	// preprocesing complete.
	int Q;
	cin>>Q;
	
	while(Q--)
	{	
		int index;
		cin>>index;
		cout << primes[index-1]<<'\n';
	}
}