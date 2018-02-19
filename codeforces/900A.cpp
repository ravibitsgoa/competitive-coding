#include <iostream>
using namespace std;
int f(int x, int y)
{	return (x>0);
}/*
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	int x[n], y[n], one=0, zero=0;
	for(int i=0; i<n; i++)
	{	cin>>x[i]>>y[i];
		if(f(x[i], y[i]))
			one++;
		else
			zero++;
	}
	if(one == 1 || zero==1 || one==0 || zero==0)
		cout <<"Yes";
	else
		cout << "No";
}*/