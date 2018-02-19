#include<iostream>
using namespace std;
int main()
{	int t;
	cin>>t;
	while(t--)
	{	int n;
		cin>>n;
		if(360%n==0 && n<360) cout<<"y ";
		else cout<<"n ";
		if(n>360) cout<<"n ";
		else cout<<"y ";
		if(n<27) cout<<'y';//why?
		else cout<<'n';
		cout<<endl;
	}
return 0;
}
