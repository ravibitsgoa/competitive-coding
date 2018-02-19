/*#include <iostream>
#include <algorithm>
using namespace std;

int maxnines(const long long x)
{	long long c = x, dig=0, i=1;
	while(c!=0)
	{	dig++;
		c/=10;
		i*=10;
	}
	if(x== i-1)
		return dig;
	else
		return dig-1;
}

long long f(long long x)
{	if(x%2)
		return x+1;
	else
		return x;
}

int main()
{	long long n;
	cin>>n;
	int k = maxnines(2*n -1);
	if(k==0)
	{	cout << n*(n-1)/2;
		return 0;
	}
	long long num=0, i=1;
	for(int kcopy=0; kcopy<k; kcopy++)
	{	num*=10;
		num+=9;
		i*=10;
	}
	long long ans=min(f(abs(num-n-n))/2, (num-1)/2);
	for(int j=1; j<10; j++)
	{	cout <<ans<<endl;
		num+= i;
		if(num> 2*n-1)
			break;
		//cout << j;
		ans+= min(f(abs(num-n-n))/2, (num-1)/2);
	}
	cout << ans;
}*/