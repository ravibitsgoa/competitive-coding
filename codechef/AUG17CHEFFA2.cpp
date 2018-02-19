#include<iostream>
using namespace std;
typedef long long ll;

ll fib[100]={0};
int a[100]={0};

long long f(long long n, int mx, int c)
{   if(n==0)    return 1;
    if(n<0)     return 0;
    //if(n==1)    return 1;
    while(mx>=0 && fib[mx]>n )
        mx--;
    cout<<mx<<' ';
    if(mx<0)
        return 0;
    long long res=0, tmp, temp;
    while(mx>=0)
    {   tmp=n-fib[mx];
        int ccopy=0;
        while(tmp>=0 && ccopy<=c && ccopy<=a[mx])
        {   //cout<<n<<' '<<tmp<<' ';
            temp=f(tmp, mx-1, c);
            res+=temp;
            tmp-=fib[mx];
            ccopy--;
            //cout<<res<<'\n';
        }
        //cout<<endl;
        mx--;
    }
    return res;
}

int main()
{   fib[0]=1;
    fib[1]=2;
    for(int i=2; i<90; i++)
    {   fib[i] = fib[i-1] + fib[i-2];
        //cout<<fib[i]<<' ';
    }
    int T;
    cin>>T;
    while(T--)
    {   int len;
        cin>>len;
        ll n;
        for(int i=0; i<len; i++)
        {   cin>>a[i];
            n += a[i]*fib[i];
        }
        cout<<n<<' ';
        cout<<f(n, 9, 50)<<'\n';
    }
    return 0;
}
