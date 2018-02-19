#include <iostream>
using namespace std;
int main()
{   int v;
    cin>>v;
    while(v)
    {
        long long NMAX=0, MMAX=0;
        while(MMAX*(MMAX+1)*(MMAX+2)/6 <=v)
        {   MMAX++;
        }
        while(NMAX*(NMAX)*(NMAX) <=v)
        {   NMAX++;
        }
        long long vmax=0;
        for(long long n=0; n <= NMAX; n++)
        {   for(long long m=0; m <= MMAX; m++)
            {   if(n*n*n <=v)
                {   vmax = max(vmax, n*n*n);
                    if((m*(m+1)*(m+2)/6) + (n*n*n) <= v )
                        vmax = max(vmax, (m*(m+1)*(m+2)/6) + (n*n*n));
                }
                if((m*(m+1)*(m+2)/6) <= v )
                    vmax = max(vmax, (m*(m+1)*(m+2)/6) );
            }
        }
        cout<<vmax<<'\n';
        cin>>v;
    }
}   
