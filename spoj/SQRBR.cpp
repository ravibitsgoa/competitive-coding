#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n, k;
        cin>>n>>k;
        char x[n]={0};
        while(k--)
        {   int i;
            cin>>i;
            x[i-1]='[';
        }
        int ans[2*n][2*n]={0};
        ans[0][1]=1;
        for(int i=1; i<2*n; i++)
        {   if(x[i]=='[')
                ans[i][0]=0;
            else
                ans[i][0]=ans[i-1][1];
            for(int j=1; j<=i; j++)
            {   if(x[i]=='[')
                    ans[i][j]=ans[i-1][j-1];
                else
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j+1];
            }
        }
        cout<<ans[2*n - 1][0]<<'\n';
    }
    return 0;
}
