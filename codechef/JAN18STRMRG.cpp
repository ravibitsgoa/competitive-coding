#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		size_t la, lb;
		cin >> la >> lb;
		string a, b;
		cin >> a >> b;
		int dp[la+1][lb+1];
		dp[0][1]= dp[0][0]=1;	//cost of null string.
		char last[lb+1] = {'\0', a[0]};
		
		for(size_t j=1; j<la; j++)
		{	dp[0][j+1] = dp[0][j] + (last[j] != a[j]);
			//populating first row of the table.
			last[j+1] = (a[j]);
		}
		last[0] = b[0];
		
		for(size_t i=1; i<=lb; i++)
		{	dp[i][0] = dp[i-1][0] + (last[0] != b[i-1]);
			//populating first col of the table.
			last[0] = b[i-1];
			for(size_t j=1; j<=la; j++)
			{	int score1= dp[i-1][j] + (last[j] != b[i-1]);
				int score2= dp[i][j-1] + (last[j-1] != a[j-1]);
				if(score1 < score2)
				{	dp[i][j] = score1;
					last[j]= b[i-1];
				}
				else
				{	dp[i][j] = score2;
					last[j] = a[j-1];
				}
			}
		}
		cout << dp[lb][la]<<'\n';
	}
	
}