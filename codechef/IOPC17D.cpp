#include<iostream>
using namespace std;
#define LIMIT 12500
#define mod 1000000007

long long fastpow(long long base,long long expo)
{
	if(expo==0)
	return 1;

	long long mid=fastpow(base,expo/2);

	if(expo%2)
	return ((mid*mid)%mod*base)%mod;

	return (mid*mid)%mod;
}

long long mmi(long long x)
{
	return fastpow(x,mod-2);
}
int main()
{ ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int p[LIMIT+10]={0};
  p[0]=p[1]=1;
  register int sgn=1;
  for(int i=2; i<=LIMIT; i++)
  { sgn=1;
    for(int j=1; ((3*j*j- j)/2)<=i && i+j<=LIMIT; j++)
    { if((i- ((3*j*j- j)/2))>=0)
        p[i]=(p[i] + sgn*p[i- ((3*j*j- j)/2)]);
      if((i- ((3*j*j+ j)/2))>=0)
        p[i]=(p[i] + sgn*p[i- ((3*j*j+ j)/2)]);
      sgn*=-1;
      p[i]%=mod;
      if(p[i]<0)
        p[i]+=mod;
    }
  }
  int t;
  cin>>t;
  long long int products[LIMIT+10];
  products[0]=1;
  for(int i=1; i<=LIMIT; i++)
    products[i]=(products[i-1]*p[i])%mod;
  while(t--)
  { long long N, M;
    cin>>N>>M;
    cout<<(products[M+N-1]*mmi(products[M-1]))%mod<<'\n';
  }

return 0;
}
