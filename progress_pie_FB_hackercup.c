#include<iostream>
#include<cmath>
using namespace std;
int main()
{   int t, p, x, y;
    cin>>t;
    for(int i=1; i<=t; i++)
    {   cin>>p>>x>>y;
        double th=atan((double)(x-50)/(y-50));
        if(th<=p*PI/50 && sqrt((double)x-50.0)*(x-50.0) + (y-50.0)*(y-50.0))<=50.0)
    }

}
