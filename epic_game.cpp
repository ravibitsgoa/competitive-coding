#include<iostream>
using namespace std;
int gcd(int a, int b)
{   if(a>b){return gcd(a-b, b);}
    else if(a<b){return gcd(a, b-a);}
    else if(a==b){return a;}
    else if(b==0){return a;}
    else if(a==0){return b;}
}
int main()
{   int a, b, n, ga, gb, i=0;
    cin >> a;
    cin >> b;
    cin >> n;
    ga=gcd(n,a); gb=gcd(n,b);
    while(n>0)
    {   n-= ga*(i==0) + gb*(i==1);
        i=!i;
    }
    cout<<!i;
    return 0;
}
