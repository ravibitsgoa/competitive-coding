#include <iostream>
using namespace std;
const double EPS = 1e-10;
int main()
{
    long double x = 0.2L;
    //double i= 1;
    for(int i=0; i < 64; i++)
    {   
        if(int(x) & 1)
            cout<<1;
        else
            cout<<0;
        x*=2;
    }
    return 0;
}
