/*#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{	string s;
		cin>>s;
		bool ans=0;
		unordered_map <string, int> mymap;
		for(size_t i=0; i<s.length()-1; i++)
		{	for(size_t j=i+1; j<s.length(); j++)
			{	string x;
				x+= s[i];
				x+= s[j];
				//cout<<x<<endl;
				mymap[x]++;
				if(mymap[x]>1)
				{	ans=1;
				}
			}
		}
		if(ans==0)
			cout<<"no";
		else
			cout<<"yes";
		cout<<'\n';
	}
}*/