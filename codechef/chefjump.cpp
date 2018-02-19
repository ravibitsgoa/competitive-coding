#include<iostream>
using namespace std;
int main()
{	long long int x, t;
    cin>>t;
    while(t--)
	{cin>>x;
	x=x%6;
	if(x==0 || x==1 || x==3) cout<<"yes";
	else cout<<"no";
	}
	return 0;
}
