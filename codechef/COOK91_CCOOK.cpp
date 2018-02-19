#include <iostream>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	string str[] = {"Beginner", "Junior Developer", "Middle Developer", "Senior Developer", "Hacker", "Jeff Dean"};
	for(int i=0; i<n; i++)
	{
		int x=0, t;
		for(int j=0; j<5; j++)
		{	cin>>t;
			x+=t;
		}
		
		cout << str[x] << endl;
	}
}