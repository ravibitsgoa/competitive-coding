#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n>>k;
		unordered_set<int> A;
		while(n--)
		{	int x;
			cin>>x;
			A.insert(x);
		}
		int ans=0;
		for(ans=0; 1; ans++)//Code to find MEX anywhere.
		{	if(A.find(ans)==A.end())
			{	if(k>0)
					k--;
				else
				{	break;
				}
			}
		}
		cout<<ans+k<<'\n';
	}
}