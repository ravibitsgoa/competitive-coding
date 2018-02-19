#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int gettime()
{	int h, m, s;
	char c1, c2;
	cin >> h >> c1 >> m >> c2 >> s;
	return (h*3600 + m*60 +s);
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int test_case=1; test_case<=t; test_case++)
	{
		int n;
		cin >> n;
		queue<int> times;
		int time_arr[n];
		for(int i=0; i<n; i++)
		{	time_arr[i] = gettime();
		}
		int diff;
		cin >> diff;
		if(n==0)
		{	cout << "Case "<<test_case<<": 0\n";
			continue;
		}
		sort(time_arr, time_arr+n);
		times.push(time_arr[0]);
		int ans=1;
		for(int i=1; i<n; i++)
		{	while(!times.empty() && (time_arr[i]- times.front() >= diff))
			{	times.pop();
			}
			times.push(time_arr[i]);
			ans = max(ans, (int)times.size());
		}
		cout <<"Case "<<test_case<<": "<< ans<<'\n';
	}
}