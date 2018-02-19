#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n, i, sum=0, m;
        cin>>n>>m;
        int inp[n];
        for(i=0; i<n; i++)
        {   cin>>inp[i];
            sum+=inp[i];
        }
        sort(inp, inp+n);
        if(sum%m==0)
        {   cout<<(sum/m)<<endl;
        }
        else
        {   int k= (int) sum/m;
            if(inp[0]<=(sum-(k*m)))
            {   cout<<"-1"<<endl;
            }
            else
            {   cout<<k<<endl;
            }
        }
    }
    return 0;
}
