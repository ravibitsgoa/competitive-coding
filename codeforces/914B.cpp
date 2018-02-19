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
	int arr[n], mx=1e5+5;
	int fr[mx]={0}, lr=0;
	for(int i=0; i<n; i++)
	{
		cin>> arr[i];
		fr[arr[i]]++;
		lr = max(lr, arr[i]);
	}
	sort(arr, arr+n);
	int odd=0;
	for(int i=n-1; i>=0; i--)
	{
		if(fr[arr[i]]%2 == 1)
			odd = 1;
	}
	if(odd == 1)
		cout << "Conan";
	else 
		cout << "Agasa";
}*/