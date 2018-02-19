#include <iostream>
#include <set>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, r;
		cin>>n>>r;
		int a[n];
		for(int i=0; i<n; i++)
			cin>>a[i];
		int invalid =0;
		set<int> seen;
		if(n<=2)
		{
			cout<<"YES\n";
			continue;
		}
		
		for(int i=0; i<n; i++)
		{	seen.insert(a[i]);
			if(a[i]>r)
			{	auto iter =seen.begin(), searchiter = seen.find(a[i]);
				searchiter--;
				if(a[i+1] > a[i])
				{	invalid =1;
					break;
				}
				if((a[i] != (*iter)) && (a[i+1] < *searchiter))
				{	invalid =1;
					break;
				}
			}
			else if(a[i]<r) 
			{	auto iter =seen.end(), searchiter = seen.find(a[i]);
				searchiter++;
				iter--;
				if(a[i+1] < a[i])
				{	invalid =1;
					break;
				}
				if(a[i] != (*iter) && (a[i+1]>*(searchiter)))
				{	invalid =1;
					break;
				}
			}
		}
		if(!invalid)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}