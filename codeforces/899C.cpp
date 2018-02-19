/*#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	long long g1=0, g2=0;
	int group[n+1]={0}, t=1;
	if(n%2==0)
	{	for(int i=1; i<=n/2; i++)
		{	if(group[i]!=0)
				break;
			if(i==n/2)
			{	long long d1 = abs(g1+i-g2-(n-i+1));
				long long d2 = abs(g1+n-i+1-g2-i);
				long long d3 = abs(g1+n-i+1+i-g2);
				long long d4 = abs(g1-g2-i-(n-i+1));
				long long m=min(d1, min(d2, min(d3, d4)));
				if( m==d1)
				{	group[i]=1;
					group[n-i+1]=2;
					g1+= i;
					g2+= n-i+1;
				}
				else if(m==d2)
				{	group[i]=2;
					group[n-i+1]=1;
					g2+= i;
					g1+= n-i+1;
				}
				else if(m==d3)
				{	group[i]=1;
					group[n-i+1]=1;
					g1+= i;
					g1+= n-i+1;
				}
				else 
				{	group[i]=2;
					group[n-i+1]=2;
					g2+= i;
					g2+= n-i+1;
				}
			}
			else if(group[n-i+1]==0)
			{	group[i]=t;
				group[n-i+1]=t;
				if(t==1)
					g1 += i+ n-i+1;
				else
					g2 += i + n-i+1;
			}
			else
			{	if(abs(g1+i-g2) < abs(g1-g2-i))
				{	group[i]=1;
					g1+=i;
				}
				else
				{	group[i]=2;
					g2+=i;
				}
			}
			if(t==1)
				t=2;
			else
				t=1;
		}
	}
	else
	{	for(int i=2; i<=(n+1)/2; i++)
		{	if(group[i]!=0)
				break;
			if(i==(n+1)/2)
			{	long long d1 = abs(g1+i-g2-(n-i+2));
				long long d2 = abs(g1+n-i+2-g2-i);
				long long d3 = abs(g1+n-i+2+i-g2);
				long long d4 = abs(g1-g2-i-(n-i+2));
				long long m=min(d1, min(d2, min(d3, d4)));
				if( m==d1)
				{	group[i]=1;
					group[n-i+2]=2;
					g1+= i;
					g2+= n-i+2;
				}
				else if(m==d2)
				{	group[i]=2;
					group[n-i+2]=1;
					g2+= i;
					g1+= n-i+2;
				}
				else if(m==d3)
				{	group[i]=1;
					group[n-i+2]=1;
					g1+= i;
					g1+= n-i+2;
				}
				else 
				{	group[i]=2;
					group[n-i+2]=2;
					g2+= i;
					g2+= n-i+2;
				}
			}
			else if(group[n-i+2]==0)
			{	group[i]=t;
				group[n-i+2]=t;
				if(t==1)
					g1 += i+ n-i+2;
				else
					g2 += i+ n-i+2;
			}
			else
			{	if(abs(g1+i-g2) < abs(g1-g2-i))
				{	group[i]=1;
					g1+=i;
				}
				else
				{	group[i]=2;
					g2+=i;
				}
			}
			if(t==1)
				t=2;
			else
				t=1;
		}
		assert(group[1]==0);
		if(abs(g1+ 1 -g2) < abs(g1-g2-1))
		{	group[1] = 1;
			g1++;
		}
		else
		{	group[1] = 2;
			g2++;
		}
	}
	cout<<abs(g1 - g2)<<'\n';
	vector<int> group1;
	for(int i=1; i<=n; i++)
	{	if(group[i]==1)
			group1.push_back(i);
	}
	cout<<group1.size();
	for(int i: group1)
		cout<<' '<<i;
}*/