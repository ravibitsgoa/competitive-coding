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
        unsigned long long sum=0;
        for(iy = 0; iy<q; iy++)
        {   unsigned long long tempx=0, tempz=0, sumx=0, sumz=0;
            for(unsigned long long ix1=0; ix1<p && x[ix1]<=y[iy]; ix1++)
            {   sumx+=x[ix1];
                tempx++;
            }
            for(unsigned long long iz1=0; iz1<r && z[iz1]<=y[iy]; iz1++)
            {   sumz+=z[iz1];
                tempz++;
            }
            sum += ((y[iy]%MOD)*(sumx%MOD)*(tempz%MOD)) % MOD;
            sum %= MOD;
            sum += ((y[iy]%MOD)*(y[iy]%MOD)*tempx*tempz) % MOD;
            sum %= MOD;
            sum += ((sumx%MOD)*(sumz%MOD)) % MOD;
            sum %= MOD;
            sum += ((y[iy]%MOD)*(sumz%MOD)*tempx) % MOD;
            sum %= MOD;
        }
        cout<<sum<<"\n";
    }
    return 0;
}
