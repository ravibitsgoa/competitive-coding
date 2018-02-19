#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


long long invMontgomeryA(long long a, long long p, int &k)
{   long long r=0, u=p, v=a, s=1;
    while(v>0)
    {   ++k;   
        if(!(u&1))      // if u is even
        {   u>>=1;
            s<<=1;
        }
        else if(!(v&1)) //if v is even.
        {   v>>=1;
            r<<=1;
        }
        else
        {   long long x= u-v;
            if(x>0)
            {   u = (x>>1);
                r+=s;
                s<<=1;
            }
            else
            {   v = -(x>>1);
                s+=r;
                r<<=1;   
            }
        }
    }
    if(r>p)
        r-=p;
    return (p-r);
}   //outputs y= inverse(a) * (2**k) (mod p)
 
long long inv(long long a, long long p)
{   int k=0;
	long long y= invMontgomeryA(a, p, k);
    for(int i=0; i<k; i++)
    {   if(!(y&1))  //if y is even
            y>>=1;
        else
            y = (y+p)>>1;
    }
    return y;
}   //outputs y= inverse(a) (mod p)

const int MAXN = 1e6 + 5;
const int MAXQ = 32e4;
int A[MAXN];
int prod[MAXN];
int zeros[MAXN];
int b[MAXQ];
		/*
int main()
{
	int t;
	scanf("%d", &t);
	vector<int> ans;
	while(t--)
	{
		int n, p, q;
		scanf("%d %d %d", &n, &p, &q);
		for(int i=0; i<n; i++)
			scanf("%d", &A[i]);
		for(int i=0; i<((q/64) + 2); i++)
		{
			scanf("%d", &b[i]);
		}
		int l, r;
		int x=0;
		if(A[0]==0)
		{	zeros[0]=1;
			prod[0] = 1;
		}
		else
		{	prod[0]= A[0];
			zeros[0] = 0;
		}
		
		for(int i=1; i<n; i++)
		{	zeros[i] = zeros[i-1];
			if(A[i]==0)
			{	prod[i]= prod[i-1];
				zeros[i]++;
			}
			else
				prod[i] = (prod[i-1] * A[i])%p;
		}
		
		for(int i=0; i<q; i++)
		{
			if(i%64 == 0)
			{
				l= (b[i/64] + x)%n;
				r= (b[i/64 + 1] + x)%n;
			}
			else
			{
				l= (l + x)%n;
				r= (r + x)%n;
			}
			if(l>r)
				swap(r, l);
			int res;
			
			if((l==0 && zeros[r]==0) || (zeros[l-1] == zeros[r]))
			{	
				if(l!=0)
					res = prod[r]*inv(prod[l-1], p) % p;
				else
					res = prod[r];
			}
			else
				res= 0;
			x = (1+ res)%p;
		}
		ans.push_back(x);
		//printf("%lld\n", x);
	}
	for(int x: ans)
		printf("%d\n", x);
}*/