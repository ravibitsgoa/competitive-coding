#include <cstdio>
const double EPS = 1e-9;

using namespace std;

double binarySearch(double start, double end, double x)
{
    double middle = (start+end)/2;
    //printf("%.10lf\n", middle);
    if (start>end)
        return -1;
    if( (middle*middle - x)<EPS && (middle*middle - x)>(-EPS) )
        return middle;
    if (middle*middle > x)
        return binarySearch(start, middle, x);
    else
        return binarySearch(middle, end, x);
}

double sqroot(double x) //sqrt(x) must lie between 0 and x.
{
    if(x<0)
        printf("i*");
    return binarySearch(0, x, x);
}


int main()
{
    double x=-3.0;
    printf("%.10lf",sqroot(x));
    return 0;
}
