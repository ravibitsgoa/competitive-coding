/*#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	long long n, x;
	cin>>n>>x;
	if(n==x)
	{
		cout << "Yes\n";
		while(n--)
			cout <<"0 ";
		return 0;
	}
	vector<int> rep;
	int count=0;
	while(n)
	{
		count+= (n&1);
		rep.push_back(n&1);
		n>>=1;
	}
	if(x<count)
		cout << "No";
	else
	{
		while(rep.size()>1)
		{
			int f=rep.back();
			count+= 2*f -1;
			if(count > x)
			{	cout << "No";
				return 0;
			}
			rep.pop_back();
			rep[rep.size()-1]+=2*f;
			if(count==x)
			{
				cout << "Yes\n";
				for(int i=rep.size()-1; i>=0; i--)
					while(rep[i]--)
						cout << i<<' ';
				return 0;
			}
		}
		queue<pair<int, int> > v;
		v.push({0, rep[0]});
		while(1)
		{
			pair<int, int> p = v.front();
			cout << count << ' ';
			count+= 2*p.second -1;
			cout << count << endl;
			if(count > x)
			{	cout << "No";
				return 0;
			}
			v.push({p.first-1, p.second*2});
			v.pop();
			//cout << p.first<<' '<<p.second<<endl;
			if(count==x)
			{
				for(int i=0; i<v.size(); i++)
				{	pair<int, int> p = v.front();
					while(p.second--)
						cout << p.first<<' '; 
					v.pop();
				}
				return 0;
			}
		}
	}
}*/