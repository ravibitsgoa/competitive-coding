/*#include <iostream>
using namespace std;
int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	string s;
	cin>>s;
	int n= s.length(), a[s.length()], b[s.length()];
	if(s[0]=='a')
	{	a[0]=1;
		b[0]=0;
	}
	else
	{	a[0]=0;
		b[0]=1;
	}
	for(int i=1; i<n; i++)
	{	if(s[i]=='a')
		{	a[i]=a[i-1]+1;
			b[i]=b[i-1];
		}
		else
		{	a[i]=a[i-1];
			b[i]=b[i-1]+1;
		}
	}
	int ans=0;
	for(int i=0; i<n; i++)
	{	for(int j=i+1; j<n; j++)
		{	if(ans < a[i]+b[j]-(b[i-1]*(i>0))+a[n-1]-a[j-1])
			{	//cout<<ans<<' '<<i<<' '<<j<<endl;
				ans = a[i]+b[j]-(b[i-1]*(i>0))+a[n-1]-a[j-1];
			}
		}
	}
	cout<<ans;
	return 0;
}
*/