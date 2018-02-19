/*#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	int a, ones=0, twos=0;
	for(int i=0; i<n; i++)
	{	cin>>a;
		if(a==1)
			ones++;
		else
			twos++;
	}
	
	if(ones==0)
		cout<<0;
	else
	{	int temp= min(ones, twos);
		cout << (temp)+((ones-temp)/3);
	}
}*/