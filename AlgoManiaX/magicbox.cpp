#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int T;
    cin>>T;
    while(T--)
    {   int a1, o1, w1;
        cin>>a1>>o1>>w1;
        int g1 = __gcd(w1, __gcd(a1, o1) );
        int a2, o2, w2;
        cin>>a2>>o2>>w2;
        int g2 = __gcd(w2, __gcd(a2, o2) );
        if(g1 == g2)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
    return 0;
}
