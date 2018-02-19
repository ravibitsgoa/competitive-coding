#include <iostream>
#include <array>
using namespace std;

const int MOD = 1000000007;
array<int, 100> arr;
int len;
long long f(int pos, int a1, int a2)
{   cout<<pos<<' '<<a1<<' '<<a2<<endl;
    long long ans=0;
    if(pos>len and (arr[pos]+a1==0 or arr[pos+1]+a2==0))
        return 1;
    if(arr[pos]+a1 < 0 or arr[pos]+a2 < 0)
        return 0;
    for(int i=1; i<=arr[pos]+a1; i++)
    {   ans= (ans + f(pos+1, a2-i, i) ) %MOD;
    }
    return ans%MOD;
}

int main()
{   //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int T;
    cin>>T;
    while(T--)
    {
        cin>>len;
        for(int i=0; i<100; i++)
            arr[i]=0;
        for(int i=0; i<len; i++)
            cin>>arr[i];
        cout<<f(0, 0, 0)<<'\n';
    }
    return 0;
}
