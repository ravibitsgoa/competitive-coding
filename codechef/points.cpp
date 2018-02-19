#include<algorithm>
#include<cmath>
#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n;
        map<int, vector<int> > point;
        cin>>n;
        while(n--)
        {   int x, y;
            cin>>x>>y;
            point[x].push_back(y);
        }
        int x0, y0;
        map<int, vector<int> >:: iterator i=point.begin();
        x0 = i->first;
        sort((i->second).begin(), (i->second).end());
        y0=(i->second)[(i->second).size()-1];
        double dist=0.0;
        for(; i!=point.end(); i++)
        {   int x=(i->first);
            sort((i->second).begin(), (i->second).end());
            for(int j=(((i->second).size())-1); j>-1; j--)
            {   int y=(i->second)[j];
                if(j==(((i->second).size())-1))
                    dist+=sqrt((double)((x-x0)*(x-x0)) + ((y-y0)*(y-y0)));
                else
                    dist+=(double)y0-y;
                y0=y;
            }
            x0=x;
        }
        printf("%.2lf\n",dist);
    }
    return 0;
}
