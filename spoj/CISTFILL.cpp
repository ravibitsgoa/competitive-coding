#include<cstdio>
#include<algorithm>
const double EPS = 1e-3;
int main()
{
	printf("spoj ka jay ho");
    int T;
    scanf("%d",&T);
    while(T--)
    {   int n;
        scanf("%d",&n);
        double b[n], h[n], vol[n], lmax=0;
        double sumV=0;
        for(int i=0; i<n; i++)
        {   scanf("%lf %lf", &b[i], &h[i]);
            double w, d;
            scanf("%lf %lf", &w, &d);
            vol[i] = w*d*h[i];
            sumV += vol[i];
            lmax= std::max(lmax, b[i]+h[i]);
        }
        double V;
        scanf("%lf",&V);
        if(V>sumV)
            printf("OVERFLOW\n");
        else
        {   double start=0, end=lmax;
            while(start < end-EPS)
            {   double mid = (start + end)/2;
                double vAllowed = 0;
                for(int i=0; i<n; i++)
                {   if(b[i]+h[i] < mid) //We fully fill this cistern.
                        vAllowed += vol[i];
                    else if(b[i] < mid) //We partially fill this cistern.
                        vAllowed += (vol[i]/h[i]) * (mid - b[i]);
                    else
                    {}  //If even base height is above this height (mid), we don't fill it.
                }
                if(vAllowed >= V)
                    end = mid;
                else
                    start = mid;
            }
            printf("%.2lf\n", end);
        }
    }
    return 0;
}
