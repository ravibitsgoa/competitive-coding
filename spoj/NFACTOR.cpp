/*#include <iostream>
using namespace std;

const int NMAX = 1e6+1;
int arr[NMAX][10];
int factors[NMAX];

void computeSumUpto(int n, int numFactors[])
{
	for(int i=2; i<n; i++)
	{	if(numFactors[i]==0)//if i's a prime, enter this condition.
		{	numFactors[i]=1;
			for(int j=2*i; j<n; j+=i)
			{
				numFactors[j]++;
			}
		}
	}
}

int main()
{
	computeSumUpto(NMAX, factors);
	
	for(int j=0; j<10; j++)
		arr[1][j]=0;
	arr[1][0]=1;
	
	for(int i=2; i<NMAX; i++)
	{
		arr[i][factors[i]] = arr[i-1][factors[i]] + 1;
		for(int j=0; j<10; j++)
		{	if(j!=factors[i])
				arr[i][j]= arr[i-1][j];
		}
	}
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		int a, b, n;
		cin >> a >> b >> n;
		/*int sum=0;
		for(int i=a; i<=b; i++)
			if(factors[i]==n)
			{	sum++;
				//cout <<i<<' ';
			}
		//cout <<'\t'<< sum<<' ';
		cout << arr[b][n] - arr[a-1][n] << '\n';
	}
}*/