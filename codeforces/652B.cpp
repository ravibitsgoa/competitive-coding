#include <algorithm>
#include <iostream>
using namespace std;
bool valid(int a[], int sz)
{
	for(int i=0; i<sz; i++)
	{	if(i>0 && i%2 == 0 && a[i]>a[i-1])
		{	return false;
		}
		else if(i%2!=0 && a[i]<a[i-1])
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	int b[n];
	int b_i=0, a_i=0;
	for(a_i=0; a_i<n && b_i<n; a_i++)
	{	b[b_i]= a[a_i];
		b_i+=2;
	}
	for(b_i=1; a_i<n; a_i++)
	{	b[b_i] = a[a_i];
		b_i+=2;
	}
	if(valid(b, n))
	{
		for(int i=0; i<n; i++)
			cout << b[i]<< ' ';
	}
	else
		cout << "Impossible";
}