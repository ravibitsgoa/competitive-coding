#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{   int i, l=1000, n=3*log10(l);
    for(i=1; i<l; i++)
    {   cout<<i<<setw(n)<<i*i<<endl;
    }
    return 0;
}
