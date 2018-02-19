#include <iostream>
#include <map>
#include <set>
using namespace std;
/*int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int count[2];
	map<int, set<int> > A;
	A[0].insert(-1);
	count[s[0]-'0'] 	= 1;
	count[!(s[0]-'0')] 	= 0;
	A[-count[0] +count[1]].insert(0);
	for(int i=1; i<n; i++)
	{	count[s[i]-'0']++;
		A[count[1]-count[0]].insert(i);
	}
	int answer=0;
	for(auto i: A)
	{	answer= max(answer, *i.second.rbegin() - *i.second.begin());
		//cout<<i.first<<' '<<*i.second.rbegin()<<' '<< *i.second.begin()<<endl;
	}
	cout<<answer;
	return 0;
}
*/