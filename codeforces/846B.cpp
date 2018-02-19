#include <iostream>
#include <algorithm>
using namespace std;
/*int main()
{
	long long n, k, m;
	cin>>n>>k>>m;
	long long arr[k], sum=0;
	for(int i=0; i<k; i++)
	{	cin>>arr[i];
		sum+=arr[i];
	}
	sort(arr, arr+k);
	long long ans=0;
	int row=0;
	for(int i=0; i<k; i++)
	{	long long c1= min(n, m/arr[i]), c2= (k+1-i)*(sum<=m);
		if(c1 >= c2 || row>=(n-1))
		{	ans += c1;
			m -= c1*arr[i];
			sum -= arr[i];
			//cout<<'a';
		}
		else //if(c2>c1 && row<n-1)
		{	ans += c2;
			row++;
			m -= sum;
			//cout<<'b';
			i--;
		}
		//cout<<ans<<endl;
	}
	cout<<ans;
}*/