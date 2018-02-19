#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>> n;
		int a[n][n];
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				cin>>a[i][j];
			sort(a[i], a[i]+n);
		}
		int ele= a[n-1][n-1];
		long long sum = ele;
		for(int i=n-2; i>=0; i--)
		{
			bool mila=0;
			for(int j=n-1; j>=0; j--)
			{	if(a[i][j]<ele)
				{	mila=1;
					ele = a[i][j];
					sum += ele;
					break;
				}
			}
			if(!mila)
			{	sum = -1;
				break;
			}
		}
		cout << sum <<'\n';
	}
}