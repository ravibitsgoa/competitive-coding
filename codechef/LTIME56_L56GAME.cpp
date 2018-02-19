/*#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	
		int n;
		cin>>n;
		int arr[n], count=0;
		for(int i=0; i<n; i++)
		{	
			cin>>arr[i];
			if(arr[i] & 1)
				count++;
		}
		if(n==1)
		{	
			cout << 1 <<'\n';
			continue;
		}
		n=1;
		cout << (count%2) + n << '\n';
	}
} */