#include<algorithm>
#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)  cin>>a[i];
        int ans=0;
        for(int i=0; i<n; i++)
        {   for(int j=i+1; j<n; j++)
            {   if((a[i]|a[j]) <= max(a[i], a[j]))
                    ans++;
                //cout<<a[i]<<' '<<a[j]<<' '<<(a[i]|a[j])<<'\n';
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
