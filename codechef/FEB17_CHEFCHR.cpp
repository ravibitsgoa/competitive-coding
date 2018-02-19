/*#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		int c=0, h=0, e=0, f=0, ans=0;
		for(int i=0; i<s.length(); i++)
		{
			if(s[i] == 'c')
				c++;
			else if(s[i] == 'h')
				h++;
			else if(s[i] == 'e')
				e++;
			else if(s[i] == 'f')
				f++;
			if(i>3)
			{
				if(s[i-4] == 'c')
					c--;
				else if(s[i-4] == 'h')
					h--;
				else if(s[i-4] == 'e')
					e--;
				else if(s[i-4] == 'f')
					f--;				
			}
			if(c==1 && h==1 && e==1 && f==1)
				ans++;
		}
		if(ans)
			cout << "lovely "<<ans<<'\n';
		else 
			cout << "normal\n";
	}
}*/