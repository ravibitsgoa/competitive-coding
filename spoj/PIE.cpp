//http://www.spoj.com/problems/PIE/
#include <cstdio>
#include <algorithm>

const double EPS = 1e-4;
const double PI = 3.141592653589793;

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {   int n, f;
        scanf("%d %d", &n, &f);
        int r[n];
        double v[n];//array of volumes
        double vmax=0;
        for(int i=0; i<n; i++)
        {   scanf("%d",&r[i]);
            v[i]= PI * r[i] * r[i]; // height is 1.
            vmax = max(v[i], vmax);
        }
        double start=0, end=vmax;
        f++;
        while(end-start > EPS)
        {   double mid = (start + end) / 2;
            //cout<<mid<<' ';
            int friend_count=0;
            for(int i=0; i<n; i++)
            {   friend_count += (int)(v[i]/mid);
            }
            //cout<<friend_count<<'\n';
            if(friend_count >= f)
            {   int next_count=0;
                for(int i=0; i<n; i++)
                {   next_count += (int)(v[i]/(mid+EPS));
                }
                if(next_count<f)
                {   end=mid;
                    break;
                }
            }
            if(friend_count <f)
                end = mid;      //binarySearch in [start, mid].
            else
                start = mid;    //binarySearch in [mid, end].
        }
        printf("%lf\n", end);
    }
    return 0;
}
