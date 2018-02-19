#include<cmath>
#include<iostream>
using namespace std;
int main()
{
	long long l, r, x, y, k;
	cin>>l>>r>>x>>y>>k;
	for(long long i=l; i<=r; i++)
	{   if(i*k>=r && i*k<=r)
	    {   cout<<"YES";
	        return 0;
	    }
	}
	cout<<"NO";
	return 0;
}
