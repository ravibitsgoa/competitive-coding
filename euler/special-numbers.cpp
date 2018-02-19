#include <cassert>
#include <iostream>
using namespace std;

const int MAX = 1000005;
int phi[MAX];

int main()
{   
    for(int i=1; i<=MAX; i++)
		phi[i]=i;

	for(int i=2; i<=MAX; i++)
	{	if(phi[i]==i)
		{	// This condition guarantees that i is prime since it was not modified by any number <i.
			for(int j=i; j<=MAX; j+=i)
				phi[j]-=(phi[j]/i);		// In this step we multiply (1-1/i) to each multiple of i, since it would be a prime factor in factorisation of all its multiples.
		}
	}
	
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin>>t;
    while(t--)
    {   int p;
        cin >> p;
        assert(1<=p && p<=1000000);
        cout << phi[phi[p]]<<'\n';
    }
}
