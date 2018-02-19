#include<iostream>
#include<algorithm>
#define MOD 1000000007
using namespace std;
int main()
{   unsigned long long num_case;
    cin>>num_case;
    while(num_case--)
    {   unsigned long long p, q, r, ix, iy, iz;
        cin>>p;
        cin>>q;
        cin>>r;
        unsigned long long x[p], y[q], z[r];
        for(ix=0; ix<p; ix++)
            cin>>x[ix];
        for(iy=0; iy<q; iy++)
            cin>>y[iy];
        for(iz=0; iz<r; iz++)
            cin>>z[iz];
        sort(x, x+p);
        sort(y, y+q);
        sort(z, z+r);
        unsigned long long sum=0, ix=0, iz=0, sumx=0, sumz=0;
        for(iy = 0; iy<q; iy++)
        {   for(; ix<p && x[ix]<=y[iy]; ix++)
            {   sumx+=x[ix];
                sumx%=MOD;
            }
            for(; iz<r && z[iz]<=y[iy]; iz++)
            {   sumz+=z[iz];
                sumz%=MOD;
            }
            sum += ((sumx + (ix*y[iy]) %MOD) % MOD)*(((iz*y[iy])%MOD + sumz) % MOD) %MOD;
        }
        cout<<sum<<"\n";
    }
    return 0;
}
