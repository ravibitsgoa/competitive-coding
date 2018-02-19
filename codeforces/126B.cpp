//Password.
#include <iostream>
#include <vector>
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
/*
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	string s;
	cin>>s;
	vector<int> z = computeZ(s);
	
	int z_max=0, n=s.length();
	for(int i=0; i<n; i++)
	{
		if(z[i] == n-i)	//i.e. s[i, n-1] == s[0, n-i-1]
		{
			if(z_max >= z[i])	
			{//i.e. there is some middle string with at least this length.
				while(i!=n)
				{	cout << s[i];
					i++;
				}
				return 0;
			}
		}
		z_max = max(z_max, z[i]);
	}
	cout << "Just a legend";
}*/