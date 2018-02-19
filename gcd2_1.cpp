#include<string>
#include<iostream>
using namespace std;
int main()
{	int t;
	cin>>t;
	while(t--)
	{	int a, b0=0;
		//cin>>a;
		string b;
		cin>>b;
		string c=substr(b + b.length()-6, 6);
		for(i=0; i<c.length(); i++)
		{	b0+=c[i]; b0*=10;
		}
		cout<<b0;
	}
return 0;
}
