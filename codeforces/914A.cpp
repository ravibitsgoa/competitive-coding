/*#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	int ar[n];
	for(int i=0; i<n; i++)
		cin>>ar[i];
	sort(ar, ar+n);
	for(int i=n-1; i>=0; i--)
	{
		int temp = sqrt(ar[i]);
		if(temp*temp != ar[i])
		{
			cout << ar[i];
			return 0;
		}
	}
}*/