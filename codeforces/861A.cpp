/*#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long n, k;
	cin>>n>>k;
	long long ans=1;
	for(int i=0; i<k; i++)
		ans*=10;
	cout<<n*ans/__gcd(n, ans);
	return 0;
}*/