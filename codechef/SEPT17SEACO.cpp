#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
const long long MOD = 1e9+ 7;
/*int main()
{
	int T;
	cin>>T;
	while(T--)
	{	int n, m;
		cin>>n>>m;
		long long arr[n]={0}, left[n]={0}, right[n]={0};
		vector< vector<int> > command(m, vector<int>(3));
		long long commandLeft[m]={0}, commandRight[m]={0};
		for(int i=0; i<m; i++)
		{	int typ, l, r;
			cin>>typ>>l>>r;
			command[i]= {typ, l-1, r-1};
		}
		long long current=1;
		for(int i=m-1; i>=0; i--)
		{	current = (current + commandRight[i])%MOD;
			if(i<(m-1)) current-= commandLeft[i+1];
			if(current<0)
				current+=MOD;
			if(command[i][0] == 2)
			{	commandLeft[command[i][1]]  += current;
				commandLeft[command[i][1]] %= MOD;
				commandRight[command[i][2]] += current;
				commandRight[command[i][2]] %= MOD;
			}
			else if(command[i][0]==1)
			{	left[command[i][1]]  += current;
				left[command[i][1]] %= MOD;
				right[command[i][2]] += current;
				right[command[i][2]] %= MOD;
			}
			else
				assert(0);
		}
		current= left[0];
		arr[0]= current;
		for(int i=1; i<n; i++)
		{	current = (current + left[i] - right[i-1])%MOD;
			if(current<0)
				current+=MOD;
			arr[i]= current;
		}
		for(int i =0; i<n; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	return 0;
}*/