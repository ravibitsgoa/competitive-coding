#include<string>
#include<iostream>
using namespace std;
int sumdig(int a)
{ 	int s=0;
	while(a)
	{ 	s+=a%10;
		a/=10;
	}
	return s;
}
int main()
{ 	string x;
	cin>>x;
	int sum=0;
	for(int i=0; i<x.length(); i++)
		sum+=x[i]-'0';
	int i;
	if(x.length()==1)
	{	cout<<'0'; 
		return 0;
	}
	for(i=1; sum>9; i++)
	{	sum=sumdig(sum);
	}
	cout<<i;
	return 0;
}
