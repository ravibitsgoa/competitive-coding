#include <iostream>
#include <unordered_set>
using namespace std;
/*int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	int a[n], kill[n];
	unordered_set<int> k;
	for(int i=0; i<n; i++)
	{	cin>>a[i];
		kill[i] = 0;
	}
	int mn=n;
	for(int i=n-1; i>=0; i--)
	{	if(kill[i])
			k.insert(i);
		if(a[i]==0)
			continue;
		if(i-a[i] < mn)
		{	for(int j=min(mn, i-1); j>=i-a[i] && j>=0; j--)
			{	kill[j]=1;
			}
			mn = i-a[i];
		}
		//mn = min(mn, max(0, i-a[i]));
	}
	//for(int i: k)
		//cout << i<<endl;
	cout << n-k.size();
	return 0;
}
*/