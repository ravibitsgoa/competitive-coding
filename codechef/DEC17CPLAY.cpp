#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	while(cin>>s && !cin.eof())
	{
		int a=0, aturns=5, b=0, bturns=5, i=0;
		int w=-1;
		for(i=0; i<10 && w==-1; i++)
		{	if(i%2 == 0)
			{	a+= s[i]-'0';
				aturns--;
			}
			else
			{	b+= s[i]-'0';
				bturns--;
			}
			if(a>(b+bturns))
			{	w=0;
				//cout << a << b;
			}
			else if(b>(a+aturns))
			{	w=1;
				//cout << a << b;
			}
		}
		if(w==-1)
		{	for(i=10; i<s.length() && w==-1; i+=2)
			{	a+= s[i]-'0';
				b+= s[i+1]-'0';
				if(a>b)
				{	w=0;
				}
				else if (b>a)
				{	w=1;
				}
			}
		}
		if(w==0)
			cout << "TEAM-A " << i;
		else if(w==1)
			cout << "TEAM-B " << i;
		else 
			cout << "TIE";
		cout << '\n';
	}
}