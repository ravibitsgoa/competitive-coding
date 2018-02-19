/*#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int n, m, k;
	cin>>n>>m>>k;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	
	deque<int> l;
	l.push_back(a[0]);
	int ans=0;
	for(int i=1; i<n; i++)
	{	while(l.size()>0 && a[i]-l.front() >=m)
		{	l.pop_front();
		}
		l.push_back(a[i]);
		if(l.size()>=k)
		{	l.pop_back();
			ans++;
		}
	}
	cout << ans;
}*/