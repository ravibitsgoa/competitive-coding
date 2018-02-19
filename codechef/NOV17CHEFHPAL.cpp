#include <iostream>
using namespace std;

int palin(string &str)
{
    int maxLength = 1;  // The result (length of LPS)
 
    int start = 0;
    int len = str.length();
 
    int low, high;
 
    for (int i = 1; i < len; ++i)
    {
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
 
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
	return maxLength;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{	int n, A;
		cin>>n>>A;
		if(A==1)
		{	string s(n, 'a');
			cout<<palin(s)<<' '<<s<<'\n';
		}
		else if(A>2)
		{	string temp;
			for(int i=0; i<n; i++)
				temp+= (char)('a'+(i%A));
			cout<<palin(temp)<<' '<<temp;
			cout<<'\n';
		}
		else
		{
			if(n<11)
			{
				string ans(n, 'a');
				int minpalin = n;
				for(int i=0; i<(1<<n); i++)
				{
					string s;
					for(int j=0; j<n; j++)
					{	if((1<<j) & i)
							s+='b';						
						else
							s+='a';
					}
					if(minpalin > palin(s))
					{
						minpalin = palin(s);
						ans= s;
					}
				}
				cout<<minpalin<<' '<<ans<<'\n';
			}
			else
			{
				string s="aabbab", temp;
				for(int i=0; i<n; i++)
					temp+= s[i%6];
				cout<<palin(temp)<<' '<<temp;
				cout<<'\n';
			}
		}
	}
	return 0;
}