#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n, m;
        cin>>n>>m;
        int inp[n];
        for(int i=0; i<n; i++)
            cin>>inp[i];
        sort(inp, inp+n);
        /*for(int i=0; i<n; i++)
            cout<<inp[i];*/
        long long int sum=0;
        for(long long int i=1; i<=(1<<n); i++)
        {   int k=0;
            sum=0;
            for(long long int j=2; j<=i && k<n; j*=2)
            {   sum+=inp[k]*((i%j)-(i%(j/2)));
                k++;
                if(sum>=m)
                break;
            }
            //cout<<(sum)<<endl;
            if(sum==m)
                break;
        }
        if(sum==m)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
