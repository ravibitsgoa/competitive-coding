#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        int inp[n];
        for(int i=0; i<n; i++)
            cin>>inp[i];
        int i;
        long long l=1;
        for(i=0; i<n; i++)
        {   l-=inp[i];
            if(l<0 && i<n-1)
            {   cout<<"No"; break;
            }
            l*=2;
        }
        if(l==0 && i==n) cout<<"Yes";
        if(l!=0 && i==n) cout<<"No";
        cout<<endl;
    }
    return 0;
}
