#include<iostream>
using namespace std;
int main()
{	int t;
	cin>>t;
	while(t--)
	{	int n, i, ite=0, n0;
		cin>>n;
		string x="zyxwvutsrqponmlkjihgfedcba";
		if(n<25)	{i=(n+1)%26;i=26-i;}
		else i=0;
		n0=n;
		while(ite<=n0)
		{	/*if(n>25)
			{	if(ni-n %26==-1) cout<<'z';
				else						cout<<(char)(26-((ni-n)%26) + 97);
			}
			else
			{	if(n%26==-1) cout<<'z';
				else 				cout<<(char)(n%26 + 97);
			}
			n--;*/
			cout<<x[i];
			ite++; i++;
			if(i==26)
			{	if(n<49)	{i=(n+2)%26;i=26-i;}
				else i=0;
				n-=26;
			}
		}
		cout<<endl;
	}
	return 0;
}
