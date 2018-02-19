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
            cin>>inp[i];
        sort(inp, inp+n);
        reverse(inp, inp+n);
        int sum=0;
        for(int i=0; i<n; i+=4)
        {   sum+=inp[i];
            if(i+1<n) sum+=inp[i+1];
        }
        cout<<sum<<endl;
    }
    return 0;
}
