#include <iostream>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int t;
	cin>>t;
	while(t--)
	{	string s;
		cin>>s;
		int stack_size= 0, ans=0;
		for(int i=0; i<s.length(); i++)
		{	if(s[i]=='<')
				stack_size++;
			else 
				stack_size--;
			if(stack_size<0)
				break;
			if(stack_size==0 && i)
				ans = i+1;
		}
		cout << ans<<'\n';
	}
}