#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> computeZ(string s)
{
	int L=0, R=0, n=s.length();
	//loop invariant : [L, R] matches [0, R-L].
	vector<int> z(s.length());
	for (int i = 1; i < n; i++) 
	{
		if (i > R) 
		{
			L = R = i;
			while (R < n && s[R-L] == s[R]) //while Rth and R-L th char match.
				R++;						//Keep incrementing R.
			z[i] = R-L;						//s[i, R) match s[0, R-i)
			R--;							//now, s[i, R]==s[0, R-i]
		} 
		else 
		{
			int k = i-L;
			if (z[k] < R-i+1) 				//s[k, R] doesn't match s[0, R-k].
				z[i] = z[k];
			else 
			{
				L = i;
				while (R < n && s[R-L] == s[R]) 
					R++;
				z[i] = R-L; 
				R--;
			}
		}
	}
	return z;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{	
		string s;
		cin>>s;
		reverse(s.begin(), s.end());
		vector<int> z = computeZ(s);
		int q;
		cin>>q;
		while(q--)
		{
			size_t x;
			cin>>x;
			if(x==s.length())
				cout << s.length()<<'\n';
			else
				cout << z[s.length()-(x-1)-1]<<'\n';
		}
	}
}