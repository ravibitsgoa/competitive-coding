#include <iostream>
#include <algorithm>
using namespace std;
/*int main()
{
	int n;
	cin>>n;
	int pies[n], sum=0;
	for(int i=0; i<n; i++)
	{	cin>>pies[i];
		sum+=pies[i];
	}
	reverse(pies, pies+n);
	int dp[n][2];
	dp[0][0] = 0;
	dp[0][1] = pies[0];
	for(int i=1; i<n; i++)
	{	dp[i][0] = min(dp[i-1][0]+pies[i], dp[i-1][1]);
		//1 etle pasandgi mara haath ma chhe.
		dp[i][1] = max(pies[i]+dp[i-1][0], dp[i-1][1]);
	}
	int bob = dp[n-1][1];
	cout<<sum-bob<<' '<<bob;
	return 0;
}*/