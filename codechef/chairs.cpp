#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n, ans=0;
        cin>>n;
        string x;
        cin>>x;
        int i=0, sum=0;
        while(i<n && x[i]=='1'){i++;}
        for(int j=i+1; j<n+i; j++)
        {   if(x[j%n]=='1' && x[(j-1)%n]=='0' && x[(j+1)%n]=='0')
                ans++;
            if(x[j%n]=='1')
                sum++;
        }
        if(sum==ans)
            cout<<sum-1<<endl;
        else
            cout<<ans<<endl;
    }
return 0;
}
