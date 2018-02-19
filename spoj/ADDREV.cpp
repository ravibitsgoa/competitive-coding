#include<algorithm>
#include<iostream>
using namespace std;
int rev(int n)
{   int i, out=0;
    for(i=1; i<=n; i*=10){out+=(((int)(n/i))%10); out*=10;}
    if(out%10==0) out/=10;
    return out;
}
int main()
{   int t;
    int n1, n2, out;
    cin>>t;
    while(t--)
    {   cin>>n1>>n2;
        cout<<rev(rev(n1)+rev(n2))<<endl;
        //cout<<out;
    }
    return 0;
}
