#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string x;
		cin>>x;
		int a=0, b=0, temp=0, last='.';
		for(int i=0; i<x.length(); i++)
		{	if(x[i]=='A')
			{	a++;
				if(last=='A')
					a+= temp;
				temp=0;
				last = 'A';
			}
			else if(x[i]=='B')
			{	b++;
				if(last=='B')
					b+= temp;
				temp=0;
				last = 'B';
			}
			else
				temp++;
		}
		cout<<a<<' '<<b<<'\n';
	}
}