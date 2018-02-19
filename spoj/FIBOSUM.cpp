#include <iostream>
using namespace std;
const long long MOD = 1e9+ 7;
void power(long long mat[2][2], long long n)
{
	if(n==0)	//any matrix raised to power 0 is Identity matrix. [1 0; 0 1] 
	{	mat[0][0]=1;
		mat[0][1]=0;
		mat[1][0]=0;
		mat[1][1]=1;
		return;
	}
	
	long long copymat[2][2];
	copymat[0][0]=mat[0][0];
	copymat[0][1]=mat[0][1];
	copymat[1][0]=mat[1][0];
	copymat[1][1]=mat[1][1];
	power(mat, n/2);// x^([n/2]).
	//now we square the result:
	//[a b]^2 =[a*a +bc, ab+ bd]
	//[c d]    [ac  +dc, bc+d*d]
	long long squaremat[2][2];
	squaremat[0][0] = (((mat[0][0]*mat[0][0])%MOD) + ((mat[0][1]*mat[1][0])%MOD))%MOD;
	squaremat[0][1] = (((mat[0][0]*mat[0][1])%MOD) + ((mat[0][1]*mat[1][1])%MOD))%MOD;
	squaremat[1][0] = (((mat[1][0]*mat[0][0])%MOD) + ((mat[1][0]*mat[1][1])%MOD))%MOD;
	squaremat[1][1] = (((mat[1][0]*mat[0][1])%MOD) + ((mat[1][1]*mat[1][1])%MOD))%MOD;
	
	if(n&1)	//if n is odd, we have to multiply original matrix once again.
	{	//x^n = (x^([n/2]))*(x^([n/2]))*x
		long long ans[2][2];
		ans[0][0]= (((squaremat[0][0]*copymat[0][0])%MOD) + ((squaremat[0][1]*copymat[1][0])%MOD))%MOD;
		ans[0][1]= (((squaremat[0][0]*copymat[0][1])%MOD) + ((squaremat[0][1]*copymat[1][1])%MOD))%MOD;
		ans[1][0]= (((squaremat[1][0]*copymat[0][0])%MOD) + ((squaremat[1][1]*copymat[1][0])%MOD))%MOD;
		ans[1][1]= (((squaremat[1][0]*copymat[0][1])%MOD) + ((squaremat[1][1]*copymat[1][1])%MOD))%MOD;
		
		mat[0][0]= ans[0][0];
		mat[0][1]= ans[0][1];
		mat[1][0]= ans[1][0];
		mat[1][1]= ans[1][1];
		return;
	}
	//if n is even, x^n = x^(n/2) * x^(n/2).
	mat[0][0]= squaremat[0][0];
	mat[0][1]= squaremat[0][1];
	mat[1][0]= squaremat[1][0];
	mat[1][1]= squaremat[1][1];
}

long long fib(long long mat[2][2], long long n)
{
	power(mat, n);
	return mat[0][1];
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		long long mat[2][2]={{1, 1}, {1, 0}};
		long long mat2[2][2]={{1, 1}, {1, 0}};
		cout << (fib(mat, m+2)%MOD - fib(mat2, n+1)%MOD + MOD)%MOD << '\n';
	}
}