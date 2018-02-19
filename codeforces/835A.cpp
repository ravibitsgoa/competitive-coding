#include <bits/stdc++.h>
using namespace std;
int main()
{	int s, v1, v2, t1, t2;
	cin>>s>>v1>>v2>>t1>>t2;
	int ans1=2*t1 + v1*s, ans2=2*t2 + v2*s;
	if(ans1<ans2)
		cout<<"First";
	else if(ans1==ans2)
		cout<<"Friendship";
	else
		cout<<"Second";
	return 0;
}
