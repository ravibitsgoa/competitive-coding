#include <bits/stdc++.h>
using namespace std;

int sumdig(string x)
{	int ans=0;
	for(char i : x)
		ans+=(i-'0');
	return ans;
}

int main()
{	int k;
	string n;
	cin>>k>>n;
	int a=sumdig(n);
	if(a>=k)
		cout<<0;
	else
	{	sort(n.begin(), n.end());
		int i;
		for(i=0; i<n.length() && a<k; i++)
		{	a-=n[i]-'0';
			n[i]='9';
			a+=9;
		}
		cout<<i;
	}
	return 0;
}
