#include<iostream>
#include<math.h>
#define e 0.000001
using namespace std;
int gcd(int y, long double x)
{   if(x>=-e && x<=e){return y;}
    else if(y==0){return x;}
    else if(x<=y+e && x>=y-e){return x;}
    else if(x>y){x=fmod(x,y); return gcd(y, x);}
    else {return gcd(fmod(y,x), x);}
    return 0;
}
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int y;
        long double x;
        cin>>y>>x;
        cout<<gcd(y,x)<<endl;
    }
return 0;
}
