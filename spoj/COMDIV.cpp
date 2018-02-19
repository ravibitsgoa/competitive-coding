/*#include <iostream>
#include <algorithm>
using namespace std;

const int NMAX = 1e6+1;
int factors[NMAX];

void computeSumUpto(int n, int numFactors[])
{
	for(int i=1; i<n; i++)
	{	for(int j=i; j<n; j+=i)
		{
			numFactors[j]++;
		}
	}
}

int main()
{
	computeSumUpto(NMAX, factors);
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		int g=__gcd(a, b);
		cout << factors[g] << '\n';
	}
}*/