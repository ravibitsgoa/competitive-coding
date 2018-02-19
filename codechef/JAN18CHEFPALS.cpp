/*#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include <cassert>
using namespace std;

string f(const string &x)
{
	string ans="";
	int cur=0;
	for(size_t i=0; i<x.length(); i++)
	{	if(x[i]=='w')
			cur++;
		else if(cur>0)
		{	ans += to_string(cur);
			cur = 0;
		}
	}
	if(cur>0)
		ans += cur;
	return ans;
}

int dist(const string &s)
{
	int ans=0;
	size_t l=s.length();
	for(size_t i=0; i<l; i++)
	{
		ans+= (s[i]!=s[l-i-1]);
	}
	return ans;
}

int costFn(int n, const string strings[], const int perm[])
{
	string str;
	for(int i=0; i<n; i++)
	{
		int p = perm[i];
		str+= f(strings[p-1]);
	}
	return dist(str);
}

int trivial_cost(int n, int l[], int b[], const int perm[])
{
	string str;
	for(int i=0; i<n; i++)
	{
		int p = perm[i];
		str+= to_string(l[p-1]-b[p-1]);
	}
	return dist(str);
}

int main()
{
	random_device rng;
	mt19937 urng(rng());
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int l[n];
	for(int i=0; i<n; i++)
		cin >> l[i];
	int b[n];
	for(int i=0; i<n; i++)
		cin >> b[i];
	string arr[n];
	for(int i=0; i<n; i++)
	{	const string def(l[i], 'w');
		arr[i] = def;
		for(int j=0; j<b[i]; j++)
			arr[i][j]= 'b';
		cout << arr[i] << '\n';
	}
	
	int perm[n];
	int best[n];
	for(int i=0; i<n; i++)
		best[i]=perm[i]= i+1;
	int trials=10000, cost= trivial_cost(n, l, b, perm);
	while(trials--)
	{
		shuffle(perm, perm+n, urng);
		int tempCost = trivial_cost(n, l, b, perm);
		if(tempCost < cost)
		{	cost = tempCost;
			for(int i=0; i<n; i++)
				best[i]=perm[i];
		}
	}
	//cout << cost<<endl;
	for(int i=0; i<n; i++)
		cout << best[i] << ' ';
}*/