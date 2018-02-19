#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a[4];
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		sort(a, a+4);
		if(a[0]==a[1] && a[2]==a[3])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}