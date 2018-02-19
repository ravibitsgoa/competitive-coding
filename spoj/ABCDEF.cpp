#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int s[n];
	for(int i=0; i<n; i++)
		cin>>s[i];
	vector<int> hmm;
	//hmm stores d*(e+f) for all (d,e,f).
	for(int i=0; i<n; i++)
	{	for(int j=0; j<n; j++)
		{	for(int k=0; k<n; k++)
			{	if(s[k]!=0)
					hmm.push_back((s[i]+s[j])*s[k]);
			}
		}
	}
		
	sort(hmm.begin(), hmm.end());
	long long ans=0;
	for(int i=0; i<n; i++)
	{	for(int j=0; j<n; j++)
		{	for(int k=0; k<n; k++)
			{	int val = s[i]*s[j] + s[k];
				auto par= equal_range(hmm.begin(), hmm.end(), val);
				ans+= par.second-par.first;
			}
		}
	}
	cout << ans;
}