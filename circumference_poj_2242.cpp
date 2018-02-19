#include<cstdio>
#include<cmath>
#include<iostream>
#define pi 3.141592653589793
using namespace std;
double d(double x1, double x2, double y1, double y2)
{   return sqrt(((x1-x2)*(x1-x2))+ ((y1-y2)*(y1-y2)));
}
int main()
{   int i;
    cin>>i;
    while(i--)//This is just temporary setting. This should be changed before uploading (submitting)
    {   double x1, x2, x3, y1, y2, y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        double ans=pi*d(x1, x2, y1, y2)*d(x1, x3, y1, y3)*d(x3, x2, y3, y2);
        ans/=(((x2-x1)*(y3-y1))-((y2-y1)*(x3-x1)));
        if(ans<0) ans=-ans;
        printf("%.2lf\n",ans);
    }
    return 0;
}
