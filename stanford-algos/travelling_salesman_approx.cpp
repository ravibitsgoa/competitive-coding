#include <cassert>
#include <cstdio>
#include <cmath>
const double INF = 1e9;
int main()
{   int n;
    scanf("%d",&n);
    long double x[n], y[n], len=0;
    for(int i=0; i<n; i++)
    {   int temp;
        scanf("%d %LG %LG", &temp, &x[i], &y[i]);
        assert(temp == i+1);
    }
    //input phase done.

    int covered[n]={0}, count=1, i=0;   //starting travel from city indexed 0.
    covered[0]=1;
    while(count<n)
    {   long double minD2=INF;
        int index;
        for(int j=0; j<n; j++)
        {   if(!covered[j])
            {   long double dist2 = ( (x[i]-x[j]) * (x[i]-x[j]) ) + ( (y[i]-y[j]) * (y[i]-y[j]) );
                if(dist2 < minD2)
                {   minD2 = dist2;
                    index=j;
                }
            }
        }
        //if(minD2==INF)
            //assert(0);
        len += sqrt(minD2);
        i=index;
        count++;
        covered[i]=1;
        //printf("%d ",i+1);
    }
    len += sqrt( ( (x[i]-x[0]) * (x[i]-x[0]) ) + ( (y[i]-y[0]) * (y[i]-y[0]) ) );
    printf("%LG", len);
    return 0;
}
