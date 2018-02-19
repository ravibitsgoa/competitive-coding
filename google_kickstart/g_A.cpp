#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

long long ex(long long a, long long k, long long MOD)
{
    if(k==0)    return 1;
    if(k==1)    return a%MOD;
    if(k%2)     {long long x=ex(a, (k-1)/2, MOD)%MOD; assert(x>=0);   x= (x*x)%MOD; return (a*x)%MOD;}
    else        {long long y=ex(a, k/2, MOD)%MOD;     assert(y>=0);   y= (y*y)%MOD; return y;}
}
//#define N 1000005
#define MAXN 1000005
int phi[MAXN + 1], prime[MAXN/10], sz=0;
vector<bool> mark(MAXN + 1);

int main()
{   phi[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {   if(!mark[i])
        {   phi[i] = i-1;
            prime[sz++]= i;
        }
        for (int j=0; j<sz && prime[j]*i <= MAXN; j++)
        {   mark[prime[j]*i]=1;
            if(i%prime[j]==0)
            {   int ll = 0, xx = i;
                while(xx%prime[j]==0)
                {   xx/=prime[j];
                    ll++;
                }
                int mm = 1;
                for(int k=0;k<ll;k++) mm*=prime[j];
                phi[i*prime[j]] = phi[xx]*mm*(prime[j]-1);
                break;
            }
            else
                phi[i*prime[j]] = phi[i]*(prime[j]-1 );
        }
        //if(i<10)
        //    cout<<i<<' '<<phi[i]<<endl;
    }
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int T=1; T<=t; T++)
    {   int a, n, p;
        cin>>a>>n>>p;
        long long nfact = 1;
        if(a%p == 0)
        {   cout<<"Case #"<<T<<": "<<0<<'\n';
            continue;
        }
        a %= p;
        for(long long i=2; i<=n; i++)
        {   //cout<<i<<' ';
            if(p==2)
                nfact*=i;
            else
                nfact= (nfact * i)% phi[p];
            if(nfact == 0)
                break;
        }
        //nfact%= phi[p];
        //cout<<nfact<<endl;
        cout<<"Case #"<<T<<": "<<ex(a%p, nfact, p)<<'\n';
    }

}
