#include<iostream>
using namespace std;
int mn(int a, int b)
{   if(a<=b) return a;
    return b;
}
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n, k, x, out=0;
        cin>>n>>k;
        while(n--)
        {   cin>>x; int b=k*(int)(x/k);
            out+=mn(x- b, k+b-x);
        }
        cout<<out<<endl;
    }
    return 0;
}
