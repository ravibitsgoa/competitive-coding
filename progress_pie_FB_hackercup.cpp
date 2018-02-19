#include<iostream>
#include<cmath>
#define PI 3.1415926
using namespace std;
int main()
{   int t, p, x, y;
    cin>>t;
    for(int i=1; i<=t; i++)
    {   cin>>p>>x>>y;
        double th=atan((double)(x-50)/(y-50));
        cout<<"Case #"<<i<<": ";
        if((th<p*PI/50.0) && (sqrt((double)(x-50.0)*(x-50.0) + (y-50.0)*(y-50.0))<=50.0))
        {   cout<<"black\n";
        }
        else
            cout<<"white\n";
        //cout<<(sqrt((double)(x-50.0)*(x-50.0) + (y-50.0)*(y-50.0)));
    }
return 0;
}

