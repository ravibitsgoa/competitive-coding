#include <iostream>
using namespace std;

void extendedEuclid(int A, int B, int &d, int &x, int &y)
{
    if(B == 0) 
	{
        d = A;
        x = 1;
        y = 0;
    }
    else 
	{
        extendedEuclid(B, A%B, d, x, y);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
int modInverse(int A, int M)
{
    int d, x, y;
    extendedEuclid(A, M, d, x, y);
    return (x%M + M )%M;    //x may be negative
}

int main( ) 
{
    int d, x, y;
	//extendedEuclid(16, 10, d, x, y);
	//cout << "The GCD of 16 and 10 is " << d << endl;
	//cout << "Coefficients x and y are "<< x << " and " << y << endl;
	cout << modInverse(1, 5);
	return 0;
}
//copied from hackerearth.
//A template ready to be used.
