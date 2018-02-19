/*#include <iostream>
#include <algorithm>
using namespace std;

long long gcdExtended(long long a, long long b, long long *x, long long *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    long long x1, y1; // To store results of recursive call
    long long gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

int main()
{
	long long n, a, b;
	cin>>n>>a>>b;
	if(n%__gcd(a,b))
	{	cout << "NO";
		return 0;
	}
	long long x, y;
	gcdExtended(a, b, &x, &y);
	x*= n/__gcd(a, b);
	y*= n/__gcd(a, b);
	long long m1= -__gcd(a,b)*x/b;
	long long m2= (__gcd(a,b)*y/a) +1;
	for(long long m=m1-5; m<m2+5; m++)
	{	if((x+ m*b/__gcd(a, b))>=0 && (y- m*a/__gcd(a, b))>=0)
		{	cout << "YES\n";
			cout << (x+ m*b/__gcd(a, b))<<' ';
			cout << (y- m*a/__gcd(a, b));
			return 0;
		}
	}
	cout << "NO";
}*/