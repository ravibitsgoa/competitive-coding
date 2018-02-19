/*#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include <algorithm>
using namespace std;
typedef long long ll;
//9,223,372,036,854,775,807
string toBinary(long long n)
{	string x;
	while(n)
	{	if(n&1)
			x= '1'+x;
		else
			x= '0'+x;
		n>>=1;
	}
	return x;
}

ll nextPow(ll delta)
{	ll i=1;
	while(i<delta)
		i<<=1;
	return i;
}

ll makeLinkList(const ll N, const vector<vector<ll> > &tree, const vector<ll> &x, vector<ll> &valueAtLevel)
{	stack<ll> st;
	st.push(0);
	vector<ll> visited(N, 0);
	vector<ll> onStack(N, 0);
	vector<ll> level(N, 0);
	onStack[0]=1;
	valueAtLevel[0] = x[0];
	while(!st.empty())
	{	ll done=1;
		visited.at(st.top())=1;
		ll current = st.top();
		for(ll node: tree.at(current))
		{	if(!visited[node])
			{	//cout<<node<<' '<<current<<endl;
				done=0;
				st.push(node);	//The child node is pushed onto the stack.
				onStack[node]=1;	//now 'node' is on the stack.
				valueAtLevel.at(level.at(current)+1)^= x.at(node);
				level.at(node) = level.at(current) +1;
			}
		}
		if(done)
		{	
			onStack.at(current) = 0;
			st.pop();
		}
	}
	//for(ll levelNum : level)
		//cout<<levelNum<<' ';
	//cout<<endl;
	//Returns depth of the tree.
	return *max_element(level.begin(), level.end());
}

int main()
{
	ll N, Q;
	cin>>N>>Q;
	vector<ll> xroot; 	//xroot[i] means x[i][0].
	vector<vector<ll> > tree(N);
	vector<ll> valueAtLevel(N, 0);
	for(int i=0; i<N-1; i++)
	{	ll x, y;
		cin>>x>>y;
		tree.at(x).push_back(y);
		tree.at(y).push_back(x);
	}
	vector<ll> x(N);
	for(int i=0; i<N; i++)
		cin>>x[i];
	//Input complete.
	
	//We implement DFS on the tree to calculate x of each node on day =1,2,3.
	//Thereafter, we can predict it for any day delta.
	xroot.push_back(x[0]);
	ll depth = makeLinkList(N, tree, x, valueAtLevel);
	//for(long long i : valueAtLevel)
		//cout<<i<<endl;
	vector<ll> valueAtLevelCopy (valueAtLevel);
	while(Q--)
	{	ll delta;
		cin>>delta;
		if(delta < xroot.size())
			cout<<xroot.at(delta)<<'\n';
		else
		{
			while(nextPow(delta)> N)
			{	delta -= nextPow(delta)/2;
				//cout<<delta<<endl;
			}
			//cout<<'a';
			while (xroot.size() <= delta)
			{	for(ll j=N-2; j>=0; j--)
				{	valueAtLevelCopy.at(j) ^= valueAtLevelCopy.at(j+1);
				}
				xroot.push_back(valueAtLevelCopy.at(0));
			}
			//cout<<valueAtLevelCopy[0]<<'\n';
			cout<<xroot.at(delta)<<'\n';
		}
		//cout<<delta<<' '<<xroot.at(delta)<<"\t\t\t"<<toBinary(xroot.at(delta))	<<'\n';
	}
	return 0;
}*/