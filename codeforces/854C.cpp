#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

/*int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll n, k, temp;
	cin>>n>>k;
	pair<ll, ll> c[n];
	for(ll i=0; i<n; i++)
	{	cin>>temp;
		c[i] = {temp, i};
	}
	//sort(c, c+n, cmp);
	ll ans=0, arr[n]={0}, count=0;
	priority_queue<pair<ll, ll> > ahi_sudhi;
	for(ll i=0; i<k+1 && i<n; i++)
		ahi_sudhi.push(c[i]);
	for(ll i=k+1; i<=(k+n) && count<n; i++)
	{	pair<ll, ll> p =ahi_sudhi.top();
		arr[p.second]= i;
		ans += (i- p.second-1) * p.first;
		ahi_sudhi.pop();
		count++;
		if(i<n)
			ahi_sudhi.push(c[i]);
	}
	cout<<ans<<'\n';
	for(ll i=0; i<n; i++)
		cout<<arr[i]<<' ';
}*/