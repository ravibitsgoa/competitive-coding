#include<iostream>
#include<vector>
using namespace std;

int abs(int x)
{   if(x>=0)
        return x;
    return -x;
}

int main()
{   int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<int> dp(n);
    dp[0]=1;
    for(int i=1; i<n; i++)
    {   int mxlen=0;
        //cout<<i<<' ';
        for(int j=0; j<i; j++)
        {   if((abs(arr[j]) < abs(arr[i]) ) && ((arr[j]<0) != (arr[i]<0)) && mxlen<dp[j])
            {   mxlen=dp[j];
                //cout<<j;
            }
        }
        dp[i]=mxlen+1;
        //cout<<endl;
    }
    int ans=0;
    for(int i=0; i<n; i++)
        ans=max(ans, dp[i]);
    cout<<ans;
    return 0;
}
