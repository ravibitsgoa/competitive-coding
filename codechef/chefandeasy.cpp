#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        int inp[n];
        for(int i=0; i<n; i++)
        {   cin>>inp[i];
        }
        sort(inp, inp+n);
        long long int sum=0;
        for(int i=n-1; i>-1; i-=2)
        {   sum+=inp[i];
        }
        cout<<sum<<endl;
    }
return 0;
}
