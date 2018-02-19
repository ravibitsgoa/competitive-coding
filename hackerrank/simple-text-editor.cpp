#include <stack>
#include <iostream>
#include <utility>
using namespace std;

void type1(string &s, string x)
{
	s+= x;
}

string type2(string &s, int x)
{
	string removedPortion;
	for(size_t i=s.length()-x; i<s.length(); i++)
		removedPortion+= s[i];
	s.erase(s.end()-x, s.end());
	return removedPortion;
}

int main() 
{
    stack<pair<int, string> > order;
    int q;
    cin>>q;
	string s= "";
    while(q--)
    {   
        int t;
        cin>>t;
        if(t==1)
        {
            string x;
            cin>>x;
			type1(s, x);
            order.push({1, x});
        }
        else if(t==2)
		{
			int x;
			cin>>x;
			string removed= type2(s, x);
			order.push({2, removed});
		}
		else if(t==3)
		{
			int x;
			cin>>x;
			cout << s[x-1]<<'\n';
		}
		else if(t==4)
		{
			pair<int, string> lastOp = order.top();
			order.pop();
			if(lastOp.first == 2)
				type1(s, lastOp.second);
			else
				type2(s, lastOp.second.length());
		}
		else
			return 1;
		//cout << s<<endl;
    }
    return 0;
}
