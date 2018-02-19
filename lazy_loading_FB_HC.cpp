#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int t, n;
    cin>>t;
    for(int i=1; i<=t; i++)
    {   cin>>n;
        int w[n];
        for(int j=0; j<n; j++)
        {   cin>>w[j];
        }
        int ans=0, k=0;
        sort(w, w+n);
        for(int j=n-1; j>=k && w[j]*(j-k+1)>=50; j--)
        {   if(w[j]>=50)
            {   ans++;
            }
            else
            {   int a=50/w[j];
                if(50%w[j] != 0)
                    a++;
                ans++;
                k+=a-1;
            }
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}
