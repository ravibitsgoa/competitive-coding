#include <bits/stdc++.h>
using namespace std;
long long int fastInput() {

    long long int val = 0;

    char c = getchar_unlocked();

    while (c<33) c = getchar_unlocked();

    while (c>33) val = (val<<1) + (val<<3) + (c-'0'), c = getchar_unlocked();

    return val;
}

int main()
{	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	long long int n=fastInput();
	//long long int *vec=(long long int*)malloc(sizeof(long long int)*n);
	long long int x[32]={0};
	long long int temp;
	while(n--)
	{
		temp=fastInput();
		//long long int iter = 1;
		int j=0;
		while(temp>0)
		{	if(temp&1)
				x[j]++;
			temp>>=1;
			j++;
		}
	}
	long long int xer = 1;
	long long int sum = 0;
	for(int i = 0; i<32; ++i)
	{
		sum += ((x[i]*(x[i]-1))*xer)/2;
		xer <<=1;
	}
	cout<<sum;
	//cout<<sizeof(int);
	return 0;
}
