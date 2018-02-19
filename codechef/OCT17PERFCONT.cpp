#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	int n, p;
		cin>>n>>p;
		int cakewalk=0, hard=0;
		while(n--)
		{
			int part=0;
			cin>>part;
			if(part>= p/2)
				cakewalk++;
			else if(part <= p/10)
				hard++;
		}
		if(cakewalk==1 && hard==2)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
}