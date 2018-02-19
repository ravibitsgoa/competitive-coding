#include<iostream>
#include<cmath>
using namespace std;
bool pr(int n)
{   int i;
    if(n%2==0 && n!=2){return 1;}
    for(i=3; i<=sqrt(n); i+=2)
    {   if(n%i==0)
        {   return 1;
        }
    }
    return 0;
}
int main()
{   int n, x, y;
    cin>>n;
    x=n/2; if(n%2)y=(n+1)/2; else y=n/2;
    while(x>1 && y<n)
    {   if(pr(x) && pr(y) && x+y==n)
        {   cout<<x<<' '<<y;
            break;
        }
        x--; y=n-x;
    }
    return 0;
}
