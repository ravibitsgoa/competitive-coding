#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int n, k;
	cin>>n>>k;
	int num[n];
	for(int i=0; i<n; i++)
		cin>>num[i];
	sort(num, num+n);
	long long ans=0;
	for(int i=0; i<n; i++)
	{	ans+= upper_bound(num, num+n, num[i]+k)- lower_bound(num, num+n, num[i]+k);
	}
	cout << ans;
}