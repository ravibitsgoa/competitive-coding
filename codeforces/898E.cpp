/*#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	long long a[n];
	long long squp[n];
	long long sqd[n];
	long long unsq[n];
	for(int i=0; i<n; i++)
	{	cin>>a[i];
		long long temp = sqrt(a[i]);
		if(temp*temp == a[i])
		{	unsq[i]=1;
			squp[i]=sqd[i]=0;
		}
		else
		{	unsq[i]=0;
			sqd[i]= a[i]- temp*temp;
			squp[i]= (temp+1)*(temp+1) - a[i];
		}
	}
	
}*/