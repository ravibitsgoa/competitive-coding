/*
 * Using extended Euclidean algo to solve linear diphontine equations.
 * */
/*
#include <iostream>
using namespace std;
void extendedEuclid(long long A, long long B, long long &gcd, long long &x, long long &y)
{
	if(B == 0) 
	{
		gcd = A;
		x = 1;
		y = 0;
	}
    else 
	{
		extendedEuclid(B, A%B, gcd, x, y);
		long long temp = x;
		x = y;
		y = temp - (A/B)*y;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a, b, d;
		cin>>a>>b>>d;
		long long x, y, gcd;
		extendedEuclid(a, b, gcd, x, y);
		x*= d/gcd;
		y*= d/gcd;
		//cout << x<<' '<<y<<' ';
		long long k1= -x*gcd/b, k2=y*gcd/a;
		//k belongs to [k1, k2] for (x,y) to be a natural solution.
		//so (k1, k2) definitely satisfies the equation, and the end points should be checked.
		//cout << k1<<' '<<k2<<' ';
		long long ans= k2-k1-1;
		if(((a*(x + k1*b/gcd) + b*(y - k1*a/gcd)) == d) && (x + k1*b/gcd)>=0 && (y - k1*a/gcd)>=0)
		    ans++;
		if(((a*(x + k2*b/gcd) + b*(y - k2*a/gcd)) == d) && (x + k2*b/gcd)>=0 && (y - k2*a/gcd)>=0)
		    ans++;
		if(ans<0)
		    ans=0;
		cout << ans<<'\n';
	}
}*/