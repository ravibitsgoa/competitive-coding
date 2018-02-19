/*#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

const int LIMIT  = 200000;
vector <int> prime;
bool is_composite[LIMIT];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int main()
{
	long long n, m;
	cin >> n >> m;
	sieve(2*n);
	if(n==2)
	{
		cout << "2 2\n1 2 2";
	}
	else
	{
		vector<pair<int, int> > graph[n+1];
		set<int> gr[n+1];
		gr[1].insert(2);
		gr[2].insert(1);
		gr[2].insert(n);
		gr[n].insert(2);
		
		auto iter = lower_bound(prime.begin(), prime.end(), n);
		while(*iter < n)
		{	iter++;
		}
		int req_prime = *iter;
		
		graph[1].push_back({n, 2});
		graph[n].push_back({1, 2});
		
		graph[1].push_back({2, req_prime-(n-1)});
		graph[2].push_back({1, req_prime-(n-1)});
		
		const long long inf = 1e9;
		
		m-=2;
		int last=2;
		for(int j=3; j<n; j++)
		{
			gr[last].insert(j);
			gr[j].insert(last);
			graph[last].push_back({j, 1});
			graph[j].push_back({last, 1});
			last = j;
		}
		for(int i=1; i<=n && m; i++)
		{
			for(int j=1; j<=n && m; j++)
			{
				if(i==j)
					continue;
				if(gr[i].find(j)==gr[i].end())
				{	gr[i].insert(j);
					gr[j].insert(i);
					graph[i].push_back({j, inf});
					graph[j].push_back({i, inf});
					m--;
				}
			}
		}
		cout << 2 << ' '<< req_prime<<'\n';
		for(int i=1; i<=n; i++)
		{
			for(auto j : graph[i])
			{
				if(j.first>i)
					cout << i<<' '<<j.first<<' '<<j.second<<'\n';
			}
		}
	}
}*/