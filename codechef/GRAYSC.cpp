#include <iostream>
#include <vector>
#include <utility>
#include <map>
using ull = unsigned long long;
using namespace std;
 
int log2(ull x)
{	int a=0;
	while(x>0)
	{	a++;
		x>>=1;
	}
	return a;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	ull arr[n];
	vector<int> diff_by(66, -1);
	for(int i=0; i<n; i++)
	{	cin>>arr[i];
	}
	for(int i=1; i<n; i++)
	{	ull temp = arr[i]^arr[i-1];//temp = 2^k. k belongs to N.
		int t = diff_by.at(log2(temp));
		if(t == -1)
		{	diff_by.at(log2(temp)) = i-1;
		}
		else if(t == i-2)
		{	
		}
		else
		{	cout<<"Yes";
			return 0;
		}
	}
	map<ull, int> freq;
	int gEQ2 =0;
	for(int i=0; i<n; i++)
	{	freq[arr[i]]++;
	}
	for(auto i: freq)
	{	if(i.second>1)
			gEQ2++;
		if(i.second>3)
		{	cout<<"Yes";
			return 0;
		}
	}
	if(gEQ2 > 1)
		cout<<"Yes";
	else
		cout<<"No";
} 