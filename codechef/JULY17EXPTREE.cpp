/*
tags: trees, combinatorics, number-theory.
explanation: number of ordered trees with n vertices is Q= (2n-2) C (n-1) / n,
-> remember: x1 + x2 +x3 +...+xr = n (xi>=0) has solutions (n+r-1) C (r-1).
let xi be number of children of a node.
so, number of trees with at least 1 node of 1-child-only is P=(2n-4) C (n-2).
In order to reduce P/Q, we divide both of them by gcd(P,Q), hence making them coprime.
Then, we have to print P*Qinverse mod prime1 and prime2.
The trick used while dividing P with gcd is because P involves N^2 and N was upto 10^18, which will definitely overflow.
So, I have done: P/=gcd ni jagya e P*=modInverse(gcd(P,Q))%prime1.

This solution would be less obfuscated in Python or with use of boost libarary bigInts, but that would cause TLE.

Also, I have computed modular multiplicate inverse using Fermat's little theorem: Ainverse mod M = A^(M-2) mod M where M is a prime.
*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
ull modularExponentiation(ull x,ull n,ull M)
{
    x%=M;
    ull result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n/=2;
    }
    return result;
}
ull modInverse(ull A, ull M)
{ return modularExponentiation(A,M-2,M);
}
const ull prime1=1e9+7, prime2= 1e9+9;
int main()
{ int T;
  cin>>T;
  while(T--)
  { ull N;
    cin>>N;
    ull a=N, b=2*((2*N)-3), g=__gcd(a, b);
    a=(a%prime1)*(modInverse(g,prime1))%prime1;
    b/=g;
    g=__gcd(N-1, b);
    b/=g;
    a=(a*(((N-1)%prime1 * modInverse(g, prime1))%prime1))%prime1;
    ull binverse=modInverse(b, prime1);
    cout<<(a * binverse)%prime1<<' ';

    a=N; b=2*((2*N)-3); g=__gcd(a, b);
    a=(a%prime2)*(modInverse(g,prime2))%prime2;
    b/=g;
    g=__gcd(N-1, b);
    b/=g;
    a=(a*(((N-1)%prime2 * modInverse(g, prime2))%prime2))%prime2;
    binverse=modInverse(b, prime2);
    cout<<(a * binverse)%prime2<<'\n';
  }
  return 0;
}
