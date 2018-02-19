#include <iostream>
#include <vector>
using namespace std;

const int NMAX = 500005;

void computeSumUpto(int n, vector<int> &sum)
{
	for(int i=1; i<=n; i++)
	{	for(int j=2*i; j<=n; j+=i)
		{
			sum[j]+=i;
		}
	}
}

int main()
{
	vector<int> sumOfDiv(NMAX, 0);
	computeSumUpto(NMAX, sumOfDiv);

	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout << sumOfDiv[n]<<'\n';
	}
}
