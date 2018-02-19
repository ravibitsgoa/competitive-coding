#include <iostream>
#include <vector>
using namespace std;

const int Nmax = 1e7+1;
int smallestPrimeFactor[Nmax];

vector<int> factors(int n)
{
	vector<int> factorsFound;
	while(n!=1)
	{
		factorsFound.push_back(smallestPrimeFactor[n]);
		n/=smallestPrimeFactor[n];
	}
	return factorsFound;
}

void findSmallestFactorsUpto(int n, int smallestPrimeFactor[])//the array has to have size at least n.
{
	for(int i=1; i<=n; i++)
		smallestPrimeFactor[i]=i;

	for(int i=2; i<=n; i++)
	{	if(smallestPrimeFactor[i]==i)	//if i is a prime.
		{	for(int j=2*i; j<=n; j+=i)
			{	if(smallestPrimeFactor[j]==j)
					smallestPrimeFactor[j]=i;
			}
		}
	}
}

int main()
{
	findSmallestFactorsUpto(Nmax, smallestPrimeFactor);
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	while(cin>>n && !cin.eof())
	{
		vector<int> vec(factors(n));
		cout <<"1";
		for(int i: vec)
			cout <<" x "<< i;
		cout << '\n';
	}
}
