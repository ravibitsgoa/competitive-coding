#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int t;
	cin>>t;
	while(t--)
	{
		long long n, k, b;
		cin>>n>>k>>b;
		long long arr[n];
		for(int i=0; i<n; i++)
			cin>>arr[i];
		sort(arr, arr+n);
		
		if(k == 0)
		{
			//cout << "mm";
			int count=0;
			for(int i=0; i<n; i++)
			{	//cout << arr[i];
				if(arr[i] >= b)
				{	count++;
				}
			}
			cout << count << '\n';
			continue;
		}
		
		int ans=0, i=n-1;
		while(i >= 0)
		{
			auto iter= upper_bound(arr, arr+n, (arr[i]-b) / k) - arr;
			if(iter>=i)
				iter = i-1;
			while(iter >=0 && arr[i] < arr[iter]*k + b)
				iter--;
			
			//cout << iter << ' ';
			ans++;
			i = iter;
		}
		cout << ans << '\n';
	}
}