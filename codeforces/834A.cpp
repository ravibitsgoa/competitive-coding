#include<iostream>
using namespace std;
int main()
{   char x, y;
    cin>>x>>y;
    long long n;
    cin>>n;
    char chhe[4]={'v','<','^','>'};
    int init=0, fin=0;
    while(chhe[init]!=x)
        init++;
    while(chhe[fin]!=y)
        fin++;
    long long ans=(init + n)%4;
    if(ans==fin && (init + 3*n)%4 != fin)
        cout<<"cw";
    else if((init + 3*n)%4 == fin && ans!=fin)
        cout<<"ccw";
    else
        cout<<"undefined";
return 0;
}
