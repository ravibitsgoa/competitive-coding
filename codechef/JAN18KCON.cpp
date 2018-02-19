#include <iostream>
#include <algorithm>
using namespace std;

const long long inf = 1e17;
long long maxSum(int arr[], int size)
{
    long long total_max = -inf, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here += arr[i];
        if (total_max < max_ending_here)
            total_max = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return total_max;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n>>k;
		int a[n];
		long long sum=0, prefSum=0, sufSum=0, maxPref, maxSuf;
		
		for(int i=0; i<n; i++)
		{	cin >> a[i];
			sum += a[i];
		}
		maxPref = a[0];
		prefSum = a[0];
		for(int i=1; i<n; i++)
		{	prefSum += a[i];
			maxPref = max(maxPref, prefSum);
		}
		
		maxSuf = a[n-1];
		sufSum = a[n-1];
		for(int i=n-2; i>=0; i--)
		{	sufSum += a[i];
			maxSuf = max(maxSuf, sufSum);
		}
		
		long long ans=0;
		
		if(k==2)
		{	ans = maxPref + maxSuf;
			ans = max(ans, maxSum(a, n));
			ans = max(ans, maxPref);
			ans = max(ans, maxSuf);
		}
		else if(k>2)
		{	
			ans = max(sum*(k-2), sum*(k-2) + maxSuf + maxPref);
			ans = max(ans, maxSum(a, n));
			ans = max(ans, maxSuf + maxPref);
		}
		else
		{
			ans = maxSum(a, n);
		}
		cout << ans << '\n';
	}
}