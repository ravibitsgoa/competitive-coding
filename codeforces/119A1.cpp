#include<iostream>
using namespace std;
int gcd(int a, int b)
{   if(a>b)         {return gcd(a%b, b);}
    else if(a<b)    {return gcd(a, b%a);}
    else if(a==b)   {return a;}
    else if(b==0)   {return a;}
    else if(a==0)   {return b;}
}
int main()
{   int a, b, n, ga, gb, i=0;
    cin >> a;
    cin >> b;
    cin >> n;
    while(n>0)
    {   ga=gcd(n, a); gb=gcd(n, b);
	cout<<ga<<' '<<gb<<endl;
        if(i){n-=gb;}
	else{n-=ga;}        
	i=!i;
    }
    cout<<!i;
    return 0;
}
