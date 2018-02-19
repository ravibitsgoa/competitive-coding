#include<iostream>
using namespace std;
int main()
{ 	string x;
	int opener=0, openerlast=0, closer=0, i=0, ans=0;
	while(i<x.length() && x[i]==')')
		i++;
	for(; i<x.length(); i++)
	{	if(x[i]=='(')
			opener++;
		else
			//openerlast=opener;
			closer++;
		ans+=(opener);
	}
}
