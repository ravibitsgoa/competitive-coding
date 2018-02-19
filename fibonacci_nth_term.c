#include<stdio.h>
#include<math.h>
int main()
{   int n=14;
    double phi=(sqrt((double)5.000000)+1.00)/2.00, f=(pow(phi, n)-pow(1/phi, n)) / sqrt((double)5.00);
    printf("%lf",f);
    return 0;
}
