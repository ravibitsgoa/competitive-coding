#include <iostream>
using namespace std;
int main()
{   std::string x;
    int n;
    std::cin>>x;
    n=x.length();
    while(x!="0")
    {   long long dp[n+1]={0};
        dp[n-1]=dp[n]=1;
        if(x[n-1]=='0')
            dp[n-1]=0;
        for(int i=n-2; i>=0; i--)
        {   if(x[i]=='0')
                dp[i]=0;
            else if((x[i]-'0')*10 + (x[i+1]-'0') <=26)
                dp[i] =dp[i+1]+dp[i+2];
            else
                dp[i] =dp[i+1];
        }
        std::cout<<dp[0]<<'\n';
        std::cin>>x;
        n=x.length();
    }
    return 0;
}
