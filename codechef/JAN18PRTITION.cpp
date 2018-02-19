#include <iostream>
using namespace std;
using ll = long long;
int main()
{  
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{	
		ll n, x;
		cin >> x >> n;
		if(n<=3)
		{
			cout<<"impossible\n";
			continue;
		}
		else
		{
			ll sum=n*(n+1);
			sum/=2;
			sum-=x;
			if(sum&1) 
			{	cout<<"impossible\n";
				continue;
			}
			sum/=2;
			int arr[n+1]={0};
			int c=n;
			arr[x] = 2;
			while(sum>=c && sum>0)
			{
				if(sum<=n && arr[sum]==0)
				{	arr[sum]=1;
					sum=0;
					break;
				}
				if(c==x)
					c--;
				if(arr[c]==0 && sum!=c+x)
				{	sum-=c;
					arr[c] = 1;
				}
				c--;
			}
			if(sum)
			{	int c=1;
				while(sum>=c && sum>0)
				{
					if(sum<=n && arr[sum]==0)
					{	arr[sum]=1;
						sum=0;
						break;
					}
					if(c==x)
						c++;
					if(arr[c]==0 && sum<=n && arr[sum-c]==0)
					{	sum=0;
						arr[c] = arr[sum-c]= 1;
					}
					c++;
				}
			}			
			if(sum!=0)
			{	cout << "impossible\n";
				continue;
			}
			ll s1=0, s2=0;
			for(int i=1; i<=n; i++) 
			{	//cout << arr[i];
				if(arr[i]==1)
					s1+=i;
				else if(arr[i]==0)
					s2+= i;
			}
			if(s1!=s2)
			{	cout << "impossible\n";
				continue;
			}
			for(int i=1; i<=n; i++) 
			{	cout << arr[i];
			}
			//cout << '\n'<<s1<<' '<<s2;
			cout << '\n';
		}
	}
}