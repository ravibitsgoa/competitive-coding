#include<iostream>
#include<cmath>
#include<cassert>
using namespace std;
unsigned long long third(unsigned long long num, unsigned long long i, unsigned long long j)
{   //cout<<i<<' '<<j<<endl;
    if(i>j || j>num)
        assert(0);
    if(j==i)    return i;
    if(i==j-1 && i*i*i==num)    return i;
    else if(i==j-1 )    return j;
    unsigned long long mid=(i+j)/2;
    if(mid*mid*mid == num)
        return mid;
    if(mid*mid*mid < num)
        return third(num, mid, j);
    else
        return third(num, i, mid);
}
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    while(n--)
    {   unsigned long long a, b;
        cin>>a>>b;
        unsigned long long pro=a*b;
        unsigned long long x=third(pro, 1, pow(pro, 0.34));
        a/=x;
        b/=x;
        if(a*b == x && x*x*x==pro)
            cout<<"Yes"<<'\n';
        else
            cout<<"No"<<'\n';
    }
    return 0;
}
