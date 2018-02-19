#include<iostream>
#define EPS 1e-7
using namespace std;
long double abs(long double a)
{	if(a<0)
		return -a;
	else 
		return a;
}
int main()
{	int t;
	cin>>t;
	while(t--)
	{	long double x;
		cin>>x;
		long long int i=x;
		x-=i;
		int count=1;
		long double y=x;
		while(count<10000 && abs(y-i)>EPS && abs(y-i-1)>EPS && abs(y-i +1)>EPS)
		{	count++;	
			y+=x;
			i=(long long)y;
		}
		cout<<count<<'\n';
	}
	return 0;
}
