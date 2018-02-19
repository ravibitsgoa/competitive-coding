#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, p;
		cin>>n>>p;
		string ans(n, '0');
		ans[0]='a';
		for(int i=0; i<n; i+=p)
		{	if(i+p <n)
				ans[i+p] = ans[i];
			ans[n-i-1] = ans[i];
		}
		int invalid = 0;
		for(int i=0; i<n; i++)
		{	if(ans[i]=='0')
			{	ans[i] = 'b';
				for(int j=i; j<n; j+=p)
				{	if(j+p < n)
					{	if( ans[j+p]!='a')
							ans[j+p] = ans[i];
						else
						{	invalid=1;
							break;
						}
					}
					if( ans[n-j-1]!='a')
						ans[n-j-1] = ans[i];
					if(j>=p)
					{	if( ans[j-p]!='a')
							ans[j-p] = ans[i];
						else
						{	invalid=1;
							break;
						}
					}
				}
				break;
			}
		}
		for(int i=0; i<n; i++)
		{	if(ans[i]=='0')
			{	ans[i] = 'a';
				for(int j=i; j<n; j+=p)
				{	if(j+p < n)
					{	if( ans[j+p]!='b')
							ans[j+p] = ans[i];
						else
						{	invalid=1;
							break;
						}
					}
					if( ans[n-j-1]!='b')
						ans[n-j-1] = ans[i];
					if(j>=p)
					{	if( ans[j-p]!='b')
							ans[j-p] = ans[i];
						else
						{	invalid=1;
							break;
						}
					}
				}
			}
		}
		string astring(n, 'a'), bstring(n, 'b');
		if(ans==astring || ans==bstring)
			invalid=1;
		if(invalid ==1)
			cout<<"impossible\n";
		else
			cout<<ans<<'\n';
	}
}