#include<iostream>
using namespace std;
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {   int n, d;
        cin>>n>>d;
        long long a[n];
        long long sum=0;
        for(int i=0; i<n; i++)
        {   cin>>a[i];
            sum+=a[i];
        }
        if(sum%n!=0)
        {   cout<<-1<<'\n';
            continue;
        }
        sum/=n;
        long long ans=0;
        for(int i=0; i<n-d; i++)
        {   a[i+d]+=a[i]-sum;
            ans+=abs(a[i]-sum);
            a[i]=sum;
        }
        for(int i=0; i<n; i++)
        {   if(a[i]!=sum)
                ans=-1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
