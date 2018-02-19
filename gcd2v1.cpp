#include<string>
#include<iostream>
using namespace std;
int gcd(int x, int y)
{	if(x==0) return y;
	else if(y==0) return x;
	else if(x<y) return gcd(x, y%x);
	else if(y<x) return gcd(x%y, y);
	else return y;
}
int main()
{	int t;
	cin>>t;
	while(t--)
	{	int a, b0=0;
		string b;
		cin>>a>>b;
		
		cout<<gcd(a,b0)<<endl;
	}
return 0;
}
//2107757298379527717213600518699389595229783738061356212322972511214654115727593174080683423236414793504734471782400000000000000000000
//2107757298379527717213600518699389595229783738061356212322972511214654115727593174080683423236414793504734471782400000000000000000000   
